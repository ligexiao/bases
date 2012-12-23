#include "OpenLog.h"
#include<iostream>
using namespace std;
int main()
{
	OpenLog write;
	write.mylog("Info","This is a test information message");
	write.mylog("Warn","This is a test warning message");
	return 0;
}
