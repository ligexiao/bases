#ifndef OPENLOG_H
#define OPENLOG_H
#include<string>
using namespace std;
class OpenLog
{
public:
	OpenLog();
	string getTag()const {return m_tag;}
	void setTag(string tag){m_tag =tag;}
	string getMessage()const {return m_message;}
	void setMessage(string message){m_message = message;}

	static int    writeLog(void* ptr);
	string getLogContent();
	struct tm getCurrentTime()const;
	string changeToReadableTime(struct tm* ptrlocaltm);
	string createLogDateSuffix(struct tm* ptrlocaltm);
	void mylog(string tag, string message);
private:
	string m_tag;
	string m_message;
};
#endif 
