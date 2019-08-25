#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cctype>
#include <conio.h>

using namespace std;

class Time  //时间类
{
public:
	Time(int n=0, int m=0, int d=0)
	{
		year = n, month = m, day = d;
	}
private:
    int month, day, year;
};

typedef class CFinance
{
public:
    int year, month, day;
    double Income, Output;
    CFinance *next;
} Infor;

void SearchIncomeInfor(Infor *head);
void SearchOutputInfor(Infor *head);
int menu_select();
void SearchDateInfor(Infor *head);


Infor *Inforinitlist()     //创建链表头（无信息） 
{
    Infor *head;
    head = new Infor;
    head->next = NULL;
    return head;
}

int menu_select()
{
    char c[50];
    do
    {
        system("cls");
        cout << "\t\t----------财务管理系统总菜单----------------" << endl;
        cout << "\t\t\t1.录入财务信息" << endl;
        cout << "\t\t\t2.浏览财务信息" << endl;
        cout << "\t\t\t3.查询财务信息" << endl;
        cout << "\t\t\t4.统计财务信息" << endl;
        cout << "\t\t\t5.保存财务信息" << endl;
        cout << "\t\t\t6.退出财务系统" << endl;
        cout << "\t\t\tChoice:" << endl;
        cin >> c;
    }
    while(c[0] < '1' || c[0] > '6' || c[1]);

    return(c[0] - '0');
}

void SaveToFile(Infor *head)
{
    fstream FInfor("FInfor.txt", ios::out | ios::binary);
    if(!FInfor)
    {
        cout << "文件打开失败！";
    }
    for (Infor *p = head->next; p; p = p->next)
    {
        FInfor << "\t年份：" << p->year << endl;
        FInfor << "\t月份：" << p->month << endl;
        FInfor << "\t日期：" << p->day << endl;
        FInfor << "\t收入情况：" << p->Income << endl;
        FInfor << "\t支出情况：" << p->Output << endl;
        FInfor << endl;
    }

    FInfor.close();
    system("C:/WINDOWS/NOTEPAD FInfor.txt");
    return;
}

void InputFinanceInfor(Infor *&head)
{
    system("cls");
    cout << "\t\t------------------输入财务信息---------------------" << endl << endl;
    Infor *p = new Infor;//p指针保存当前信息 
    Infor *s;
	char Input[10];
    while (1)
    {
        cout << "\t\t\t年份[int]: ";
        cin >> p->year;
        A:{cout << endl << "\t\t\t月份[int]: ";
           cin >> p->month;}
        
        if(p->month > 12 || p->month < 1)
        {
             cout<<"\t\t\t月份输入错误", "错误！";
             goto A;
        }
    
        B:{cout << endl << "\t\t\t日期[int]: ";
           cin >> p->day;}
        
        if(p->month == 1 || p->month == 3 || p->month == 5 || p->month == 7 || p->month == 8 || p->month == 10 || p->month == 12)
        {
            if(p->day > 31 || p->day < 1)
            {
                cout<<"\t\t\t日期输入错误", "错误！";
                goto B;
            }
        }
        else
        {
            if(p->month == 4 || p->month == 6 || p->month == 9 || p->month == 11)
                if(p->day < 1 || p->day > 30)
                {
                    cout<<"\t\t\t日期输入错误", "错误！";
                    goto B;
                }
        }
    
    if(p->month == 2)
        if(p->day > 29 || p->day < 1)
        {
            cout<<"\t\t\t日期输入错误", "错误！";
            goto B;
        }
        
        
        cout << endl << "\t\t\t收入[double]: ";
        cin >> p->Income;
        cout << endl << "\t\t\t支出[double]: ";
        cin >> p->Output;
        if(head->next==NULL)head->next=p;
        else s->next=p;
        s=p;
        p = new Infor;
        cout << endl << "\t是否继续输入？(Y/N)";
        cin >> Input;
        while (Input[0] != 'N' && Input[0] != 'Y') {
        	cout << endl << "\t是否继续输入？(Y/N)";
        	cin >> Input;
		}
        if (Input[0] == 'N') break;
    }   s->next=NULL;
    delete p;
    //head->next = NULL;
    return;
 
}

void ListFinanceInfor(Infor *&head)
{
    Infor *p;
    p = head->next;
    if(p != NULL)
    {
        system("cls");
        cout << endl << "\t\t==========浏览全部财务信息==========" << endl;
        while(p != NULL)
        {
            cout << "\t\t-------------------------------------------" << endl << endl;
            cout << setw(8) << "\t\t年：" << p->year << endl;
            cout << setw(8) << "\t\t月：" << p->month << endl;
            cout << setw(8) << "\t\t日: " << p->day << endl;
            cout << "\t\t收入情况：" << p->Income << endl;
            cout << "\t\t支出情况：" << p->Output << endl;
            cout << "\t\t==================================" << endl;
            p = p->next;
            
        }
        getch(); 
    }

}

//查询总菜单
void SearchMenu(Infor *&head)
{
    Infor *p;
    p = head->next;
    int Ch;
    system("cls");
    cout << "**********财务查询**********" << endl << endl;
    cout << "=========1.支出查询=========" << endl << endl;
    cout << "=========2.收入查询=========" << endl << endl;
    cout << "=========3.日期查询=========" << endl << endl;
    cout << "=========4.返回上层=========" << endl << endl;
    cout << "****************************" << endl << endl;
    cout << "Option:";
    cin >> Ch;
    switch (Ch)
    {
	    case 1:
	        SearchOutputInfor(p);
	        break;
	    case 2:
	        SearchIncomeInfor(p);
	        break;
	    case 3:
	        SearchDateInfor(p);
	        break;
	    case 4:
	        system("cls");
	        break;
	    default:
	        break;
    }
}


void SearchOutputInfor(Infor *head)
{
    Infor *p;
    p = head;
    system("cls");
    cout << endl << endl << "\t\t====================支出查询===============" << endl;
    while(p != NULL)
    {
        if(p->Output)
        {
            cout << setw(8) << "年：" << p->year << endl;
            cout << setw(8) << "月：" << p->month << endl;
            cout << setw(8) << "日：" << p->day << endl;
            cout << setw(8) << "支出：" << p->Output << endl;
            cout << "\t\t ---------------------------------------" << endl;
        }
        p = p->next;
    }getch();
}

void SearchIncomeInfor(Infor *head)
{
    Infor *p;
    p = head;
    system("cls");
    cout << endl << endl << "\t\t====================收入查询===============" << endl;
    while(p != NULL)
    {
        if(p->Output != 0)
        {
            cout << setw(8) << "年：" << p->year << endl;
            cout << setw(8) << "月：" << p->month << endl;
            cout << setw(8) << "日：" << p->day << endl;
            cout << setw(8) << "收入：" << p->Income << endl;
            cout << "\t\t ---------------------------------------" << endl;
        }
        p = p->next;
        getch();
    }
}


void SearchDateInfor(Infor *head)
{
    int x, y, z;
    Infor *p;
    p = head;
    cout << "请输入日期。" << endl;
    cin >> x >> y >> z;
    Time Time1(x, y, z);
    cout << endl << endl << "\t\t====================日期查询===============" << endl;
    while(x != p->year || y != p->month || z != p->day)
    {
        if(p->next == NULL)
        {
            cout << "未找到记录！" << endl;
            cout << "\t\t----------------------------------------" << endl;
            return;
        }

        p = p->next;
        getch();
    }
    system("cls");
    cout << setw(8) << "年：" << p->year << endl;
    cout << setw(8) << "月：" << p->month << endl;
    cout << setw(8) << "日：" << p->day << endl;
    cout << setw(8) << "收入：" << p->Income << endl;
    cout << setw(8) << "支出：" << p->Output << endl;
    cout << "\t\t ---------------------------------------" << endl;
    getch();
}

void CalculateMonthInfor(Infor *head)
{
    int x, y;
    Infor *p;
    p = head;
    system("cls");
    cout << endl << endl << "\t\t====================按月统计===============" << endl;
    cout << "输入年份，月份！" << endl;
    cin >> x >> y;
    while(p != NULL)
    {
        if(x == p->year && y == p->month)
        {
            cout << setw(8) << "年：" << p->year << endl;
            cout << setw(8) << "月：" << p->month << endl;
            cout << setw(8) << "日：" << p->day << endl;
            cout << setw(8) << "支出：" << p->Output << endl;
            cout << setw(8) << "收入：" << p->Income << endl;
            cout << "\t\t ---------------------------------------" << endl;
            getch();
        }
        p = p->next;
    }
}

void CalculateYearInfor (Infor *head)
{
    int x;
    Infor *p;
    p = head;
    system("cls");
    cout << endl << endl << "\t\t====================按年统计===============" << endl;
    cout << "输入年份！" << endl;
    cin >> x;
    while(p != NULL)
    {
        if(x == p->year)
        {
            cout << setw(8) << "年：" << p->year << endl;
            cout << setw(8) << "月：" << p->month << endl;
            cout << setw(8) << "日：" << p->day << endl;
            cout << setw(8) << "支出：" << p->Output << endl;
            cout << setw(8) << "收入：" << p->Income << endl;
            cout << "\t\t ---------------------------------------" << endl;
            getch();
        }
        p = p->next;
    }
}


void CalculateDayInfor (Infor *head)
{
    int x, y, z;
    Infor *p;
    p = head;
    system("cls");
    cout << endl << endl << "\t\t====================按日统计===============" << endl;
    cout << "输入年份,月份，日期！" << endl;
    cin >> x >> y >> z;
    while(p != NULL)
    {
        if(x == p->year && y == p->month && z == p->day)
        {
            cout << setw(8) << "年：" << p->year << endl;
            cout << setw(8) << "月：" << p->month << endl;
            cout << setw(8) << "日：" << p->day << endl;
            cout << setw(8) << "支出：" << p->Output << endl;
            cout << setw(8) << "收入：" << p->Income << endl;
            cout << "\t\t ---------------------------------------" << endl;
            getch();
        }
        p = p->next;
    }
}


void CalculateInfor(Infor *head)
{
    Infor *p;
    p = head->next;
    int Ch;
    system("cls");
    cout << endl << "**********财务统计**********" << endl << endl;
    cout << "=========1.按年统计=========" << endl << endl;
    cout << "=========2.按月统计=========" << endl << endl;
    cout << "=========3.按日统计=========" << endl << endl;
    cout << "=========4.返回上层=========" << endl << endl;
    cout << "****************************" << endl << endl;
    cout << "Option:";
    cin >> Ch;
    switch (Ch)
    {
	    case 1:
	        CalculateYearInfor(p);
	        break;
	    case 2:
	        CalculateMonthInfor(p);
	        break;
	    case 3:
	        CalculateDayInfor(p);
	        break;
	    case 4:
	        system("cls");
	        return;
	    default:
	        break;
    }
}

int main()
{
    system("color 3");
    Infor *st, *head = NULL;
    st = Inforinitlist();
    int choice = 0;
    while(choice != 6)
    {
        choice = menu_select();
        switch(choice)
        {
	        case 1:
	            InputFinanceInfor(st);
	            break;
	        case 2:
	            ListFinanceInfor(st);
	        case 3:
	            SearchMenu(st);
	            break;
	        case 4:
	            CalculateInfor(st);
	            break;
	        case 5:
	            system("cls");
	            SaveToFile(st);
	            break;
	        case 6:
	            break;
	        default: break;
        }
    }
    return 0;
}


