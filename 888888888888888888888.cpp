#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cctype>
#include <conio.h>

using namespace std;

class Time  //ʱ����
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


Infor *Inforinitlist()     //��������ͷ������Ϣ�� 
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
        cout << "\t\t----------�������ϵͳ�ܲ˵�----------------" << endl;
        cout << "\t\t\t1.¼�������Ϣ" << endl;
        cout << "\t\t\t2.���������Ϣ" << endl;
        cout << "\t\t\t3.��ѯ������Ϣ" << endl;
        cout << "\t\t\t4.ͳ�Ʋ�����Ϣ" << endl;
        cout << "\t\t\t5.���������Ϣ" << endl;
        cout << "\t\t\t6.�˳�����ϵͳ" << endl;
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
        cout << "�ļ���ʧ�ܣ�";
    }
    for (Infor *p = head->next; p; p = p->next)
    {
        FInfor << "\t��ݣ�" << p->year << endl;
        FInfor << "\t�·ݣ�" << p->month << endl;
        FInfor << "\t���ڣ�" << p->day << endl;
        FInfor << "\t���������" << p->Income << endl;
        FInfor << "\t֧�������" << p->Output << endl;
        FInfor << endl;
    }

    FInfor.close();
    system("C:/WINDOWS/NOTEPAD FInfor.txt");
    return;
}

void InputFinanceInfor(Infor *&head)
{
    system("cls");
    cout << "\t\t------------------���������Ϣ---------------------" << endl << endl;
    Infor *p = new Infor;//pָ�뱣�浱ǰ��Ϣ 
    Infor *s;
	char Input[10];
    while (1)
    {
        cout << "\t\t\t���[int]: ";
        cin >> p->year;
        A:{cout << endl << "\t\t\t�·�[int]: ";
           cin >> p->month;}
        
        if(p->month > 12 || p->month < 1)
        {
             cout<<"\t\t\t�·��������", "����";
             goto A;
        }
    
        B:{cout << endl << "\t\t\t����[int]: ";
           cin >> p->day;}
        
        if(p->month == 1 || p->month == 3 || p->month == 5 || p->month == 7 || p->month == 8 || p->month == 10 || p->month == 12)
        {
            if(p->day > 31 || p->day < 1)
            {
                cout<<"\t\t\t�����������", "����";
                goto B;
            }
        }
        else
        {
            if(p->month == 4 || p->month == 6 || p->month == 9 || p->month == 11)
                if(p->day < 1 || p->day > 30)
                {
                    cout<<"\t\t\t�����������", "����";
                    goto B;
                }
        }
    
    if(p->month == 2)
        if(p->day > 29 || p->day < 1)
        {
            cout<<"\t\t\t�����������", "����";
            goto B;
        }
        
        
        cout << endl << "\t\t\t����[double]: ";
        cin >> p->Income;
        cout << endl << "\t\t\t֧��[double]: ";
        cin >> p->Output;
        if(head->next==NULL)head->next=p;
        else s->next=p;
        s=p;
        p = new Infor;
        cout << endl << "\t�Ƿ�������룿(Y/N)";
        cin >> Input;
        while (Input[0] != 'N' && Input[0] != 'Y') {
        	cout << endl << "\t�Ƿ�������룿(Y/N)";
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
        cout << endl << "\t\t==========���ȫ��������Ϣ==========" << endl;
        while(p != NULL)
        {
            cout << "\t\t-------------------------------------------" << endl << endl;
            cout << setw(8) << "\t\t�꣺" << p->year << endl;
            cout << setw(8) << "\t\t�£�" << p->month << endl;
            cout << setw(8) << "\t\t��: " << p->day << endl;
            cout << "\t\t���������" << p->Income << endl;
            cout << "\t\t֧�������" << p->Output << endl;
            cout << "\t\t==================================" << endl;
            p = p->next;
            
        }
        getch(); 
    }

}

//��ѯ�ܲ˵�
void SearchMenu(Infor *&head)
{
    Infor *p;
    p = head->next;
    int Ch;
    system("cls");
    cout << "**********�����ѯ**********" << endl << endl;
    cout << "=========1.֧����ѯ=========" << endl << endl;
    cout << "=========2.�����ѯ=========" << endl << endl;
    cout << "=========3.���ڲ�ѯ=========" << endl << endl;
    cout << "=========4.�����ϲ�=========" << endl << endl;
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
    cout << endl << endl << "\t\t====================֧����ѯ===============" << endl;
    while(p != NULL)
    {
        if(p->Output)
        {
            cout << setw(8) << "�꣺" << p->year << endl;
            cout << setw(8) << "�£�" << p->month << endl;
            cout << setw(8) << "�գ�" << p->day << endl;
            cout << setw(8) << "֧����" << p->Output << endl;
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
    cout << endl << endl << "\t\t====================�����ѯ===============" << endl;
    while(p != NULL)
    {
        if(p->Output != 0)
        {
            cout << setw(8) << "�꣺" << p->year << endl;
            cout << setw(8) << "�£�" << p->month << endl;
            cout << setw(8) << "�գ�" << p->day << endl;
            cout << setw(8) << "���룺" << p->Income << endl;
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
    cout << "���������ڡ�" << endl;
    cin >> x >> y >> z;
    Time Time1(x, y, z);
    cout << endl << endl << "\t\t====================���ڲ�ѯ===============" << endl;
    while(x != p->year || y != p->month || z != p->day)
    {
        if(p->next == NULL)
        {
            cout << "δ�ҵ���¼��" << endl;
            cout << "\t\t----------------------------------------" << endl;
            return;
        }

        p = p->next;
        getch();
    }
    system("cls");
    cout << setw(8) << "�꣺" << p->year << endl;
    cout << setw(8) << "�£�" << p->month << endl;
    cout << setw(8) << "�գ�" << p->day << endl;
    cout << setw(8) << "���룺" << p->Income << endl;
    cout << setw(8) << "֧����" << p->Output << endl;
    cout << "\t\t ---------------------------------------" << endl;
    getch();
}

void CalculateMonthInfor(Infor *head)
{
    int x, y;
    Infor *p;
    p = head;
    system("cls");
    cout << endl << endl << "\t\t====================����ͳ��===============" << endl;
    cout << "������ݣ��·ݣ�" << endl;
    cin >> x >> y;
    while(p != NULL)
    {
        if(x == p->year && y == p->month)
        {
            cout << setw(8) << "�꣺" << p->year << endl;
            cout << setw(8) << "�£�" << p->month << endl;
            cout << setw(8) << "�գ�" << p->day << endl;
            cout << setw(8) << "֧����" << p->Output << endl;
            cout << setw(8) << "���룺" << p->Income << endl;
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
    cout << endl << endl << "\t\t====================����ͳ��===============" << endl;
    cout << "������ݣ�" << endl;
    cin >> x;
    while(p != NULL)
    {
        if(x == p->year)
        {
            cout << setw(8) << "�꣺" << p->year << endl;
            cout << setw(8) << "�£�" << p->month << endl;
            cout << setw(8) << "�գ�" << p->day << endl;
            cout << setw(8) << "֧����" << p->Output << endl;
            cout << setw(8) << "���룺" << p->Income << endl;
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
    cout << endl << endl << "\t\t====================����ͳ��===============" << endl;
    cout << "�������,�·ݣ����ڣ�" << endl;
    cin >> x >> y >> z;
    while(p != NULL)
    {
        if(x == p->year && y == p->month && z == p->day)
        {
            cout << setw(8) << "�꣺" << p->year << endl;
            cout << setw(8) << "�£�" << p->month << endl;
            cout << setw(8) << "�գ�" << p->day << endl;
            cout << setw(8) << "֧����" << p->Output << endl;
            cout << setw(8) << "���룺" << p->Income << endl;
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
    cout << endl << "**********����ͳ��**********" << endl << endl;
    cout << "=========1.����ͳ��=========" << endl << endl;
    cout << "=========2.����ͳ��=========" << endl << endl;
    cout << "=========3.����ͳ��=========" << endl << endl;
    cout << "=========4.�����ϲ�=========" << endl << endl;
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


