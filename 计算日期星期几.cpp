#include<iostream>  
using namespace std;  
  
void PrintfDay(int y,int m, int d); //����PrintfDay����  
  
void CaculateWeekDay(int y, int m, int d)  
{  
    if(m==1||m==2) //��һ�ºͶ��»������һ���ʮ���º�������  
    {  
        m+=12;  
        y--;  
    }  
    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;  
    switch(Week)  
    {  
        case 0: PrintfDay(y,m,d); cout << "������һ" << endl; break;  
        case 1: PrintfDay(y,m,d); cout << "�����ڶ�" << endl; break;  
        case 2: PrintfDay(y,m,d); cout << "��������" << endl; break;  
        case 3: PrintfDay(y,m,d); cout << "��������" << endl; break;  
        case 4: PrintfDay(y,m,d); cout << "��������" << endl; break;  
        case 5: PrintfDay(y,m,d); cout << "��������" << endl; break;  
        case 6: PrintfDay(y,m,d); cout << "��������" << endl; break;  
    }  
}  
  
void PrintfDay(int y,int m,int d)  
{  
    cout << y << "��" << m << "��" << d << "��";  
}  
int main()  
{  
    int year,month,day;  
    cout << "�������� �� ��" << endl;  
    cin >> year >> month >> day ;  
    CaculateWeekDay(year,month,day);  
    return 0;  
}  
