#include"myLog.h"
//#include<stdio.h>
#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
const string logPath = "/home/centos6/program/cpp/temp/" ;
string changeToReadableTime(struct tm* ptrlocaltm)
{
	stringstream strm;
	strm <<ptrlocaltm->tm_year+1900<<"-";
        if(ptrlocaltm->tm_mon < 10)
        {
                strm<<"0"<<ptrlocaltm->tm_mon+1;
        }
        else
                strm<<ptrlocaltm->tm_mon+1<<"-";
        if(ptrlocaltm->tm_mday < 10)
        {
                strm<<"0"<<ptrlocaltm->tm_mday<<" ";
        }
        else
                strm<<ptrlocaltm->tm_mday<<" ";
        if(ptrlocaltm->tm_hour < 10)
        {
                strm<<"0"<<ptrlocaltm->tm_hour<<":";
        }
        else
                strm<<ptrlocaltm->tm_hour<<":";
        if(ptrlocaltm->tm_min < 10)
        {
                strm<<"0"<<ptrlocaltm->tm_min<<":";
        }
        else
                strm<<ptrlocaltm->tm_min<<":";
        if(ptrlocaltm->tm_sec < 10)
        {
                strm<<"0"<<ptrlocaltm->tm_sec;
        }
        else
                strm<<ptrlocaltm->tm_sec;
	return strm.str();

}
string createLogDateSuffix(struct tm* ptrlocaltm)
{
        stringstream strm;
        if(ptrlocaltm->tm_mon < 10)
        {
                strm<<"0"<<ptrlocaltm->tm_mon+1;
        }
        else
                strm<<ptrlocaltm->tm_mon+1<<".";
        if(ptrlocaltm->tm_mday < 10)
        {
                strm<<"0"<<ptrlocaltm->tm_mday<<".";
        }
        else
                strm<<ptrlocaltm->tm_mday<<".";
        strm <<ptrlocaltm->tm_year+1900;
        return strm.str();

}

string getLogMessage(const char* tag, const char* message)
{
	time_t now;
	time(&now);
	//string temp=ctime(&now)
	//string mytime(temp,0,temp.length()-1);
	//cout<<mytime<<" ["<<tag<<"] :"<<message<<endl;
	struct tm localtm = *localtime(&now);
	string myContent = changeToReadableTime(&localtm);
	myContent += " [";
        myContent += tag;
        myContent += "]: ";
        myContent += message;
        myContent +=".";
	return myContent;
}
int writeLog(string message)
{
        //location file
	time_t now = time(NULL);
        struct tm localtm = *localtime(&now);
        string dateSuffix = createLogDateSuffix(&localtm);
        string logFileName(logPath);
        logFileName =logFileName+ "my.log."+dateSuffix;

	//write log
        ofstream outfile;
        outfile.open(logFileName.c_str(),ofstream::out|ofstream::app);
        if(!outfile)
        {
                cerr<<"error: unable to open output file:"<<endl;
                return -1;
        }
        outfile<<message<<endl;
        
	outfile.close();
        outfile.clear();
        return 0;
}
void mylog(const char* tag, const char* message)
{
	string logMessage = getLogMessage(tag,message);
	writeLog(logMessage);
}
