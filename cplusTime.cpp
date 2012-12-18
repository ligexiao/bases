#include<iostream> 
#include<string>
#include<ctime>
using namespace std;
int main()
{
     time_t rawtime = time(NULL);
     cout<<"rawtime:"<<rawtime<<endl;
     struct tm localtm = *localtime(&rawtime);
     struct tm UTCtm = *gmtime(&rawtime);
     cout<<"----------local time VS UTC time-----------"<<endl;
     cout<<"tm_sec:   "<<localtm.tm_sec<<"          "<<UTCtm.tm_sec<<endl;
     cout<<"tm_min:   "<<localtm.tm_min<<"          "<<UTCtm.tm_min<<endl;
     cout<<"tm_hour:  "<<localtm.tm_hour<<"          "<<UTCtm.tm_hour<<endl;
     cout<<"tm_mday:  "<<localtm.tm_mday<<"          "<<UTCtm.tm_mday<<endl;
     cout<<"tm_mon:   "<<localtm.tm_mon+1<<"          "<<UTCtm.tm_mon+1<<endl;
     cout<<"tm_year:  "<<localtm.tm_year+1900<<"        "<<UTCtm.tm_year+1900<<endl;
     cout<<"tm_yday:  "<<localtm.tm_yday<<"         "<<UTCtm.tm_yday<<endl;
     cout<<"tm_isdst: "<<localtm.tm_isdst<<"           "<<UTCtm.tm_isdst<<endl;
     string cstime = asctime(&localtm);
     cout<<"string time:"<<cstime<<endl;
     time_t makeLocal = mktime(&localtm);
     cout<<"mktime (hours)local: "<<makeLocal/3600<<endl;
     time_t makeUTC = mktime(&UTCtm);
     cout<<"mktime (hours)UTC: "<<makeUTC/3600<<endl;
     return 0;
}
