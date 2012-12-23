#include"myLog.h"
#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
const string logPath = "/home/centos6/program/cpp/temp/" ;
OpenLog::OpenLog()
{
	setTag("info");
	setMessage("NULL message");
}

struct tm OpenLog::getCurrentTime()const
{
	time_t now;
	time(&now);
	struct tm localtm = *localtime(&now);
	return localtm;
}
string OpenLog::changeToReadableTime(struct tm* ptrlocaltm)
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
string OpenLog::createLogDateSuffix(struct tm* ptrlocaltm)
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

string OpenLog::getLogContent()
{
	string tag = getTag();
	string message = getMessage();
	struct tm localtm = getCurrentTime();
	string myContent = changeToReadableTime(&localtm);
	myContent += " [";
        myContent += tag;
        myContent += "]: ";
        myContent += message;
        myContent +=".";
	return myContent;
}
int OpenLog::writeLog(string message)
{
        //location file
        struct tm localtm = getCurrentTime();
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
void OpenLog::mylog(string tag, string message)
{
	setTag(tag);
	setMessage(message);

        string logMessage = getLogContent();
        writeLog(logMessage);
}

