#include <time.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std; 
int main()
{
    time_t timep;
   
    time(&timep); /*��ȡtime_t���͵ĵ�ǰʱ��*/
    /*��gmtime��time_t���͵�ʱ��ת��Ϊstruct tm���͵�ʱ�䣬��û�о���ʱ��ת����UTCʱ��
      Ȼ������asctimeת��Ϊ���ǳ����ĸ�ʽ Fri Jan 11 17:25:24 2008
    */
    printf("%s", asctime(gmtime(&timep)));
    return 0;
}

//char *asctime(const struct tm* timeptr);
//���ṹ�е���Ϣת��Ϊ��ʵ�����ʱ�䣬���ַ�������ʽ��ʾ

//struct tm* localtime(const time_t* timep);
//��gmtime���ƣ��������Ǿ���ʱ��ת����ʱ�䡣

/*
 time_t now;   //ȡ�ô�1970��1��1�������������
 time(&now);  //��ȡtime_t���͵ĵ�ǰʱ��

 tm* nowtime;
 struct tm  //��<time.h>�»�ȡ���ں�ʱ�� 
 {
    int tm_sec;  �룬������Χ0-59�� ��������61
    int tm_min;  ���ӣ�0-59
    int tm_hour; Сʱ�� 0-23
    int tm_mday; �գ���һ�����еĵڼ��죬1-31
    int tm_mon;  �£� ��һ������0-11  1+p->tm_mon;
    int tm_year;  �꣬ ��1900�����Ѿ�������  1900�� p->tm_year;
    int tm_wday; ���ڣ�һ���еĵڼ��죬 ������������0-6
    int tm_yday; �ӽ���1��1�յ�Ŀǰ����������Χ0-365
    int tm_isdst; �չ��Լʱ������
  };
nowtime=localtime(&now); //���Ǿ���ʱ��ת����ʱ��

cout<<asctime(nowtime);  //���ṹ�е���Ϣת��Ϊ��ʵ�����ʱ�䣬���ַ�������ʽ��ʾ
*/
