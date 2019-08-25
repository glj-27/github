#include <time.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std; 
int main()
{
    time_t timep;
   
    time(&timep); /*获取time_t类型的当前时间*/
    /*用gmtime将time_t类型的时间转换为struct tm类型的时间，按没有经过时区转换的UTC时间
      然后再用asctime转换为我们常见的格式 Fri Jan 11 17:25:24 2008
    */
    printf("%s", asctime(gmtime(&timep)));
    return 0;
}

//char *asctime(const struct tm* timeptr);
//将结构中的信息转换为真实世界的时间，以字符串的形式显示

//struct tm* localtime(const time_t* timep);
//和gmtime类似，但是它是经过时区转换的时间。

/*
 time_t now;   //取得从1970年1月1日至今的秒数。
 time(&now);  //获取time_t类型的当前时间

 tm* nowtime;
 struct tm  //在<time.h>下获取日期和时间 
 {
    int tm_sec;  秒，正常范围0-59， 但允许至61
    int tm_min;  分钟，0-59
    int tm_hour; 小时， 0-23
    int tm_mday; 日，即一个月中的第几天，1-31
    int tm_mon;  月， 从一月算起，0-11  1+p->tm_mon;
    int tm_year;  年， 从1900至今已经多少年  1900＋ p->tm_year;
    int tm_wday; 星期，一周中的第几天， 从星期日算起，0-6
    int tm_yday; 从今年1月1日到目前的天数，范围0-365
    int tm_isdst; 日光节约时间的旗标
  };
nowtime=localtime(&now); //它是经过时区转换的时间

cout<<asctime(nowtime);  //将结构中的信息转换为真实世界的时间，以字符串的形式显示
*/
