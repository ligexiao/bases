#include"myLog.h"
#include<stdio.h>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
string changeToReadableTime(struct tm* ptrlocaltm)
{
	char buffer[10];
        sprintf(buffer,"%d-",ptrlocaltm->tm_year+1900);
        string myntime = buffer;
        if(ptrlocaltm->tm_mon < 10)
        {
                sprintf(buffer,"0%d-",ptrlocaltm->tm_mon+1);
        }
        else
                sprintf(buffer,"%d-",ptrlocaltm->tm_mon+1);
        myntime += buffer;
        if(ptrlocaltm->tm_mday < 10)
        {
                sprintf(buffer,"0%d ",ptrlocaltm->tm_mday);
        }
        else
                sprintf(buffer,"%d ",ptrlocaltm->tm_mday);
        myntime += buffer;
        if(ptrlocaltm->tm_hour < 10)
        {
                sprintf(buffer,"0%d:",ptrlocaltm->tm_hour);
         }
        else
                sprintf(buffer,"%d:",ptrlocaltm->tm_hour);
        myntime += buffer;
        if(ptrlocaltm->tm_min < 10)
        {
                sprintf(buffer,"0%d:",ptrlocaltm->tm_min);
        }
        else
                sprintf(buffer,"%d:",ptrlocaltm->tm_min);
        myntime += buffer;
        if(ptrlocaltm->tm_sec < 10)
        {
                sprintf(buffer,"0%d",ptrlocaltm->tm_sec);
        }
        else
                sprintf(buffer,"%d",ptrlocaltm->tm_sec);
        myntime += buffer;
	return myntime;

}
void mylog(const char* tag, const char* message)
{
	time_t now;
	time(&now);
	//string temp=ctime(&now)
	//string mytime(temp,0,temp.length()-1);
	//cout<<mytime<<" ["<<tag<<"] :"<<message<<endl;
	struct tm localtm = *localtime(&now);
	string myntime = changeToReadableTime(&localtm);
	myntime += " [";
        myntime += tag;
        myntime += "]: ";
        myntime += message;
        myntime +=".";

	cout<<myntime<<endl;
}
