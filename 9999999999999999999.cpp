#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include <conio.h>
#include<stdlib.h>
#include<fstream>
#include<algorithm>
using namespace std;
class people //����һ��people�����ڴ洢������Ϣ 
{
  public:
	char name[20]; //���� 
	int birthday[3]; //���� ��/��/�� 
	char phone[20]; //�绰 
	char email[30]; //���� 
	char relationship; //��ϵ 
	char mm[30]; //ѧУ/��λ/�ƺ� 
};
int num; //����һ��ȫ�ֱ�����¼���� 
people student[200]; //�����������Ϊ200�� 
bool comparename(people a , people b) //����һ���ȽϺ������Ƚ������������� 
{
	return strcmp( a.name ,b.name ) < 0; //��С�������� 
}
bool comparebirthday(people a , people b) //����һ���ȽϺ������Ƚ������������� 
{
	return a.birthday <b.birthday  ; //��С�������� 
}
class menu :public people //����һ���˵���ʵ�ֳ������й��� 
{
public:
	
	void add() //¼����Ϣ���� 
	{
		system("cls");
		cout << "*****¼�������Ϣ*****" << endl;
		cout << "*����������������";
		cin >> student[num].name; cout << endl;
		cout << "*������������Ĺ�ϵ(1.ͬѧ,2.ͬ��,3.����,4.����)��";
		cin >> student[num].relationship; cout << endl;
		if (student[num].relationship == '1'){cout << "*���������ǵ�ѧУ��";
		cin >> student[num].mm; cout << endl;}
		else if (student[num].relationship == '2'){cout << "*���������ǵĵ�λ��";
		cin >> student[num].mm; cout << endl;}
		else if (student[num].relationship == '3'){cout << "*������������ĳƺ���";
		cin >> student[num].mm; cout << endl;}
		else if (student[num].relationship == '4'){cout << "*���������ǵ���ʶ�ص㣺";
		cin >> student[num].mm; cout << endl;}
		cout << "*��������������( �� �� ��)��";
		cin >> student[num].birthday[0] >> student[num].birthday[1] >> student[num].birthday[2]; cout << endl;
		cout << "*���������ĵ绰��";
		cin >> student[num].phone; cout << endl;
		cout << "*�������������䣺";
		cin >> student[num].email;
		cout << endl << "**********************"<<endl;
	}
	void modification() //�޸���Ϣ���� 
	{
		int n; string m;int l=0;
		system("cls");
		cout << "******�޸ĸ�����Ϣ*****" << endl;
		if (num != 0)
		{
			cout << "*Ҫ�޸ĵ���������" ; //�����޸������� 
			cin >> m;
			for (n = 0; n < num; n++)
			{
				if (student[n].name == m)
				{
					l=1;
					int i;
					cout << "*��Ҫ�޸ģ�1.�绰��2.����; 3.��ϵ; ����"; //�ṩ�޸� �绰 ���� ��ϵ�ȹ��� 
					cin >> i;
					switch (i)
					{
					case 1:
						char p[20];
						cout << "*������Ҫ�޸ĵĵ绰��";
						cin >> p;
						strcpy (student[n].phone,p);
						cout<<endl<<"*�޸���ɣ�"<<endl; 
						break; 
					case 2:
						char e[30];
						cout << "*������Ҫ�޸ĵ����䣺";
						cin >> e;
						strcpy (student[n].email,e);
						cout<<endl<<"*�޸���ɣ�"<<endl;
						break;
					case 3:
					    char r;
						cout<<  "*������Ҫ�޸�Ϊʲô��ϵ(1.ͬѧ��2.ͬ�£�3.���ݣ�4.����)��";
						cin >> r;
						student[n].relationship=r;
						char m[30];
						if(student[n].relationship=='1') 
						{
						    cout<<"����Ҫ�޸�Ϊʲô��ͬѧУ��";
							cin>>m;
							strcpy(student[n].mm,m); 
						} 
				        else if(student[n].relationship=='2') 
						{
						    cout<<"����Ҫ�޸�Ϊʲô���µ�λ��";
							cin>>m;
							strcpy(student[n].mm,m); 
						}
						else if(student[n].relationship=='3') 
						{
						    cout<<"����Ҫ�޸�Ϊʲô���ĳƺ���";
							cin>>m;
							strcpy(student[n].mm,m); 
						}  
						else if(student[n].relationship=='4') 
						{
						    cout<<"����Ҫ�޸�Ϊʲô��ʶ�ص㣺";
							cin>>m;
							strcpy(student[n].mm,m); 
						}  
						cout<<endl<<"*�޸���ɣ�"<<endl; 
						break ;
					}
				}
			}
		}
		else cout << "*�޼�¼��" << endl;
		if(l==0)cout<< "*û�м�¼���ˣ�" << endl;
		cout << "***********************"<<endl; 
	}

	void deletes() //ɾ����Ϣ���� 
	{
		system("cls");
		cout << "******ɾ��������Ϣ*****" << endl;
		int i=0;
		if (num != 0)
		{
			cout << "*������Ҫɾ���˵�������";
			int n; string m;
			cin>>m;
			for (n = 0; n < num; n++)
			{
				if(student[n].name==m)
				{
				  i=1;
				  cout << "*������" << student[n].name << endl;
				  cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				  cout << "*�绰��" << student[n].phone << endl;
			      cout << "*���䣺" << student[n].email << endl;
				  cout << "*��ϵ��" ;
				  if(student[n].relationship=='1') cout<<"ͬѧ"<< endl<< "*ѧУ��"<< student[n].mm << endl<< endl;
				  else if(student[n].relationship=='2') cout<<"ͬ��"<< endl<< "*��λ��"<< student[n].mm << endl<< endl;
				  else if(student[n].relationship=='3') cout<<"����"<< endl<< "*�ƺ���"<<student[n].mm << endl<< endl;
				  else if(student[n].relationship=='4') cout<<"����"<< endl<< "*�ص㣺"<<student[n].mm << endl<< endl;
				  cout << "*ȷ��Ҫɾ���𣿣�y/n����";        //ȷ���Ƿ�ɾ�� 
				  
				  char x;cin>>x;
				  if (x == 'y')
				  {
					for(n;n<num;n++)
					{
					 strcpy(student[n].name,student[n+1].name);
					 student[n].birthday[0] = student[n+1].birthday[0];
					 student[n].birthday[1] = student[n+1].birthday[1];
					 student[n].birthday[2] = student[n+1].birthday[2];
					 strcpy(student[n].phone,student[n+1].phone);
					 strcpy(student[n].email,student[n+1].email); 
					 student[n].relationship=student[n+1].relationship;
					 strcpy(student[n].mm,student[n+1].mm);
					}
					cout<<endl<<"*ɾ����ɣ�"<<endl;
					num--; 
				  }
				  else if(x == 'n')
				  {
					cout<<endl<<"*δɾ����"<<endl; 
				  }
				}
			}
            
		}
		else cout << "*�޼�¼��" << endl;
		if(i==0)cout<< "*û�м�¼���ˣ�" << endl;
		cout << "***********************"<<endl;
	}

	void show() //�г�������Ϣ 
	{
		int n;int i=0;
		cout << "*�����г���1.ȫ����Ϣ��2.����ϵ�г�����" << endl;
		cout << "*������1-2��";
		int x;cin>>x;
		switch(x)
		{
		  case 1:
		  system("cls");
		  cout << "******�г�ȫ��������Ϣ*****" << endl;
		  if (num != 0)
			for (n = 0; n < num; n++)
			{
				cout << "*������" << student[n].name << endl;
				cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				cout << "*�绰��" << student[n].phone << endl;
				cout << "*���䣺" << student[n].email << endl;
				cout << "*��ϵ��" ;
			    if(student[n].relationship=='1') cout<<"ͬѧ"<< endl<< "*ѧУ��"<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='2') cout<<"ͬ��"<< endl<< "*��λ��"<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='3') cout<<"����"<< endl<< "*�ƺ���"<<student[n].mm << endl<< endl;
				else if(student[n].relationship=='4') cout<<"����"<< endl<< "*�ص㣺"<<student[n].mm << endl<< endl;
		    }
		  else cout << "*�޼�¼��" << endl;
		  cout << "***************************"<<endl;
		  break;
		  case 2:
		  	cout << "*�����г���1.ͬѧ��2.ͬ�£�3.���ݣ�4.���ѣ�" << endl;
			cout << "*������1-4��";
		  	int y;cin>>y;
			switch(y)
			{
				case 1:
				   system("cls");
		           cout << "******�г�ͬѧ�ĸ�����Ϣ*****" << endl;
		           if (num != 0)
			       for (n = 0; n < num; n++)
			       {
				        if (student[n].relationship == '1')
				        {
				        cout << "*������" << student[n].name << endl;
				        cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				        cout << "*�绰��" << student[n].phone << endl;
				        cout << "*���䣺" << student[n].email << endl;
				        cout << "*ѧУ��" << student[n].mm << endl;
				        cout <<endl;
				        i=1;
				        }
			       }
	               else cout << "*�޼�¼��" << endl;
		           if(i==0)cout<< "*��¼��û��ͬѧ����Ϣ��" << endl;
		           cout << "*****************************"<<endl;
				   break;
				case 2:
				   system("cls");
		           cout << "******�г�ͬ�µĸ�����Ϣ*****" << endl;
		           if (num != 0)
			       for (n = 0; n < num; n++)
			       {
				       if (student[n].relationship == '2')
				       {
				           cout << "*������" << student[n].name << endl;
				           cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				           cout << "*�绰��" << student[n].phone << endl;
				           cout << "*���䣺" << student[n].email << endl;
				           cout << "*��λ��" << student[n].mm << endl;
				           cout <<endl;
				           i=1;
			           }
			       }
		           else cout << "*�޼�¼��" << endl;
		           if(i==0)cout<< "*��¼��û��ͬ�µ���Ϣ��" << endl;
		           cout << "*****************************"<<endl;
				   break;
				case  3:
				   system("cls");
		           cout << "******�г����ݵĸ�����Ϣ*****" << endl;
		           if (num != 0)
		           for (n = 0; n < num; n++)
			       {
				        if (student[n].relationship == '3')
				        {
			               cout << "*������" << student[n].name << endl;
				           cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				           cout << "*�绰��" << student[n].phone << endl;
				           cout << "*���䣺" << student[n].email << endl;
				           cout << "*�ƺ���" << student[n].mm << endl;
				           cout <<endl;
				           i=1;
			            }
			       }
		           else cout << "*�޼�¼��" << endl;
		           if(i==0)cout<< "*��¼��û�����ݵ���Ϣ��" << endl;
		           cout << "*****************************"<<endl;
				   break;
				case 4:
				   system("cls");
		           cout << "******�г����ѵĸ�����Ϣ*****" << endl;
		           if (num != 0)
			       for (n = 0; n < num; n++)
			       {
				        if (student[n].relationship == '4')
				        {
			                  cout << "*������" << student[n].name << endl;
				              cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				              cout << "*�绰��" << student[n].phone << endl;
				              cout << "*���䣺" << student[n].email << endl;
				              cout << "*�ص㣺" << student[n].mm << endl;
				              cout <<endl;
				              i=1;
			            }
			       }
		           else cout << "*�޼�¼��" << endl;
		           if(i==0)cout<< "*��¼��û�����ѵ���Ϣ��" << endl;
		           cout << "*****************************"<<endl;
		           break;
			}
			
		} 
	}

	void checkname()  //������������Ϣ 
	{
		int n; string m;int i=0;
		system("cls");
		cout << "******���Ҹ�����Ϣ*****" << endl;
		if (num != 0)
		{
		  cout << "*������Ҫ����������";
		  cin >> m;
		  for (n = 0; n < num; n++)
		  {
			if (student[n].name == m)
			{
				cout << "*������" << student[n].name << endl;
				cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				cout << "*�绰��" << student[n].phone << endl;
				cout << "*���䣺" << student[n].email << endl;
				cout << "*��ϵ��";
			    if(student[n].relationship=='1') cout<<"ͬѧ"<< endl<< "*ѧУ��"<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='2') cout<<"ͬ��"<< endl<< "*��λ��"<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='3') cout<<"����"<< endl<< "*�ƺ���"<<student[n].mm << endl<< endl;
				else if(student[n].relationship=='4') cout<<"����"<< endl<< "*�ص㣺"<<student[n].mm << endl<< endl;
				i=1;
			}
		  }
	    }
		else cout << "*�޼�¼��" << endl;
		if(i==0)cout<< "*û�м�¼���ˣ�" << endl;
		cout << "***********************"<<endl;
	}
	
	void outfile() //��������Ϣ����txt�ļ��� 
	{
	   system("cls");
	   cout << "******��������Ϣ�����ļ�*****" << endl;
		if (num != 0)
		{
		  {fstream outfile;
		  outfile.open( "������Ϣ����ϵͳ.txt", ios::out|ios::binary );
		  outfile<<num;
		  for(int n = 0; n < num; n++)
		  { outfile.write( ( char* )&student[n],sizeof( people )) ;}
		  outfile.close() ;} 
		  
		  {fstream outfile;
		  outfile.open( "������Ϣ����ϵͳ1.txt", ios::out|ios::binary );
		  for(int n = 0; n < num; n++)
		  { 
		     if(student[n].relationship=='1') 
		     outfile.write( ( char* )&student[n],sizeof( people )) ;
		  }
		  outfile.close() ;} 
		  
		  {fstream outfile;
		  outfile.open( "������Ϣ����ϵͳ2.txt", ios::out|ios::binary );
		  for(int n = 0; n < num; n++)
		  { 
		     if(student[n].relationship=='2') 
		     outfile.write( ( char* )&student[n],sizeof( people )) ;
		  }
		  outfile.close() ;} 
		  
		  {fstream outfile;
		  outfile.open( "������Ϣ����ϵͳ3.txt", ios::out|ios::binary );
		  for(int n = 0; n < num; n++)
		  { 
		     if(student[n].relationship=='3') 
		     outfile.write( ( char* )&student[n],sizeof( people )) ;
		  }
		  outfile.close() ;} 
		  
		  {fstream outfile;
		  outfile.open( "������Ϣ����ϵͳ4.txt", ios::out|ios::binary );
		  for(int n = 0; n < num; n++)
		  { 
		     if(student[n].relationship=='4') 
		     outfile.write( ( char* )&student[n],sizeof( people )) ;
		  }
		  outfile.close() ;} 
		  cout<<endl<<"*������Ϣд���ļ��ɹ���"<<endl; 
	    }
		else cout << "*�޼�¼��" << endl;
		cout << "*****************************"<<endl;
	}
	
	void paixu() //������������ 
	{
		system("cls");
		cout << "******���������Ϣ*****" << endl;
		if (num != 0)
		{ 
		   cout<<"����1.��������2.������������";
		   int i;cin>>i;
		   switch(i)
		   {
		      case 1:
			     sort(student,student+num,comparename);break; //����sort������������ 
		      case 2:
		      	 sort(student,student+num,comparebirthday);break;//����sort������������ 
			}
		   for (int n = 0; n < num; n++)
		   {
			 cout << "*������" << student[n].name << endl;
			 cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
			 cout << "*�绰��" << student[n].phone << endl;
			 cout << "*���䣺" << student[n].email << endl;
			 cout << "*��ϵ��" ;
			 if(student[n].relationship=='1') cout<<"ͬѧ"<< endl<< "*ѧУ��"<< student[n].mm << endl<< endl;
			 else if(student[n].relationship=='2') cout<<"ͬ��"<< endl<< "*��λ��"<< student[n].mm << endl<< endl;
			 else if(student[n].relationship=='3') cout<<"����"<< endl<< "*�ƺ���"<<student[n].mm << endl<< endl;
			 else if(student[n].relationship=='4') cout<<"����"<< endl<< "*�ص㣺"<<student[n].mm << endl<< endl;
		   }
		}
		else cout<< "*�޼�¼��" ; 
		cout << "***********************"<<endl;
	}
	
	void checktime() //ͬ�³�����Ϣ��ѯ 
	{
		system("cls");
		cout << "******����ͬ�³����ĸ�����Ϣ*****" << endl;
		double m;int x=0; 
		if (num != 0)
		{
		  cout << "*������Ҫ�����·ݣ�";
		  cin >> m;
		  for (int n = 0; n < num; n++)
		  {
			if (student[n].birthday[1] == m)
			{
				cout << "*������" << student[n].name << endl;
				cout << "*���գ�" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				cout << "*�绰��" << student[n].phone << endl;
				cout << "*���䣺" << student[n].email << endl;
				cout << "*��ϵ��";
			    if(student[n].relationship=='1') cout<<"ͬѧ"<< endl<< "*ѧУ��"<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='2') cout<<"ͬ��"<< endl<< "*��λ��"<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='3') cout<<"����"<< endl<< "*�ƺ���"<<student[n].mm << endl<< endl;
				else if(student[n].relationship=='4') cout<<"����"<< endl<< "*�ص㣺"<<student[n].mm << endl<< endl;
				x++;
			}
			 
		  }
	    }
		else cout << "*�޼�¼��" << endl;
		if(x==0)cout<< "*�޴������ռ�¼��" << endl;
		else cout<<"*"<<m<<"�·ݳ���������Ϊ��"<<x<<"��"<<endl;
		cout << "**********************************"<<endl;
	}
	 
    int runyear(int y)//�ж��Ƿ�������  
    {  
       return y%4==0&&y%100!=0||y%400==0;//�淵��Ϊ1����Ϊ0  
    }  
    int daysOfMonth(int y,int m)  
    {  
       int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
       if(m!=2)  return day[m-1];  
       else  return 28+runyear(y);  
    }   
    int daysOfDate(int y,int m,int d)//����һ��������  
    {  
        int days=d;  
        for(int a=1;a<y;a++)//������  
        days+=365+runyear(a);  
        for(int b=1;b<m;b++)//������  
        days+=daysOfMonth(y,b);   
        return days;  
    }
	
	void CaculateWeekDay(int y, int m, int d)  //�ж����ڼ� 
    {  
       if(m==1||m==2) //��һ�ºͶ��»������һ���ʮ���º�ʮ����  
       {  
           m+=12;  
           y--;  
       }  
       int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;  
       switch(Week)  
       {  
        case 0: cout << "������һ��" << endl; break;  
        case 1: cout << "�����ڶ���" << endl; break;  
        case 2: cout << "����������" << endl; break;  
        case 3: cout << "�������ģ�" << endl; break;  
        case 4: cout << "�������壩" << endl; break;  
        case 5: cout << "����������" << endl; break;  
        case 6: cout << "�������գ�" << endl; break;  
       }  
    }
	  
	void checkdate() //����ָ�������ڹ����յ���Ϣ 
	{
		system("cls");
		cout << "********���������ڹ����յĸ�����Ϣ********" << endl;
		int date[3];int i=0;
		cout<<"*������Ҫ���ҵ����ڣ��� �� �գ���";
		cin>>date[0]>>date[1]>>date[2];
		int day1=daysOfDate(date[0],date[1],date[2]);
		cout << "*�����ڹ����յ������£�"<<endl;
		for(int n=0;n<num;n++)
		{
			int day2=daysOfDate(date[0],student[n].birthday[1],student[n].birthday[2]);
			
			
			if(day2-day1>=0&&day2-day1<5)
			{ 
			    if(student[n].relationship=='1') cout<<"*ͬѧ:";
				else if(student[n].relationship=='2') cout<<"*ͬ��:";
				else if(student[n].relationship=='3') cout<<"*"<<student[n].mm<<":";
				else if(student[n].relationship=='4') cout<<"*����";
			    cout << student[n].name << endl;
				cout << "*���գ�" << student[n].birthday[1] << "��" << student[n].birthday[2] <<"��";
				CaculateWeekDay(date[0],student[n].birthday[1],student[n].birthday[2]); 
				cout << "*�绰��" << student[n].phone << endl;
				cout << "*���䣺" << student[n].email << endl<<endl;	
				i++;
				char a[20]=".txt";
				char b[20];
				strcpy(b,student[n].name);
                strcat(b,a);
				fstream outfile;
		        outfile.open(b, ios::out|ios::binary );
		        outfile<<student[n].name<<":"<<"     "<<"ף���տ��֣������Ҹ���"<<"     "<<"Ī��\n";
				outfile.close();   
			}
			day2=daysOfDate(date[0]+1,student[n].birthday[1],student[n].birthday[2]);
			if(day2-day1>=0&&day2-day1<5)
			{
			    if(student[n].relationship=='1') cout<<"*ͬѧ:";
				else if(student[n].relationship=='2') cout<<"*ͬ��:";
				else if(student[n].relationship=='3') cout<<"*"<<student[n].mm<<":";
				else if(student[n].relationship=='4') cout<<"*����";
			    cout << student[n].name << endl; 
				cout << "*���գ�" << student[n].birthday[1] << "��" << student[n].birthday[2] <<"��";
				CaculateWeekDay(date[0]+1,student[n].birthday[1],student[n].birthday[2]);
				cout << "*�绰��" << student[n].phone << endl;
				cout << "*���䣺" << student[n].email << endl<<endl;	
				i++;
				char a[20]=".txt";
				char b[20];
				strcpy(b,student[n].name);
				cout<<b;
                strcat(b,a);
                fstream outfile;             //�������յ��˵ĺؿ���Ϣд���ı��ĵ� 
		        outfile.open(b,ios::out|ios::binary);
		        outfile<<student[n].name<<":"<<'\t'<<"     "<<"ף���տ��֣������Ҹ���"<<'\t'<<"                      "<<"Ī��\n";
				outfile.close(); 
			}
		}
		if(i==0) cout<<"*û�����������������գ�"<<endl;
		else cout<<"*����������յ���"<<i<<"��"<<endl; 
		cout << "******************************************"<<endl;
	} 

};
			
			int main()
			{
				fstream infile;   //��ȡtxt�ļ��д洢����Ϣ 
		        infile.open(  "������Ϣ����ϵͳ.txt", ios::in|ios::binary );
		        infile>>num;
		        if(num!=0)
		        {
		            for(int n=0;n<num;n++)
				    {
				        infile.read(( char * )&student[n],sizeof( people ));	
		            }
                    infile.close();
		        }
			A:{	
			    cout << "***********��ӭʹ��ѧ����Ϣ����ϵͳ��************"<<endl;   //��ҳ��ʾ�Ĳ˵��� 
				cout << "*                *1.¼����Ϣ��                  *" << endl
					 << " *               *2.�޸���Ϣ��                 *" << endl
					 << "  *              *3.ɾ����Ϣ��                *" << endl
					 << "   *             *4.������Ϣ��               *" << endl
					 << "    *            *5.�г���Ϣ��              *" << endl
					 << "     *           *6.��Ϣ����             *" << endl
					 << "    *            *7.ͬ�³�����ѯ��          *" << endl
					 << "   *             *8.�����ڹ����ղ�ѯ��       *"<<endl 
					 << "  *              *9.����ͨѶ¼�ļ���          *" << endl
					 << " *               *10.�˳���                    *" << endl
					 << "*��ܰ��ʾ���˳�����ʱ�ǵý���Ϣ����ͨѶ¼�ļ�Ŷ��*"<<endl
					 << "**************************************************"<<endl
					 << "*������1-10��";
				int n;
				menu eee;
				cin >> n;
				switch (n)
				{
				  case 1: //¼�빦�� 
					eee.add();
					num++;
					break;
				  case 2:  //�޸Ĺ��� 
					eee.modification();
					break;
				  case 3:  //ɾ������ 
					eee.deletes();
					break;
				  case 4: //�������ҹ��� 
					eee.checkname();
					break;
				  case 5:  //�����Ϣ����
				    eee.show();
					break; 
				  case 6:  //������ 
				     eee.paixu();
					 break;
				  case 7:  //ͬ�����ղ�ѯ���� 
				     eee.checktime();
					 break;
				  case 8:  //ָ������������������Ϣ��ѯ���� 
				  	 eee.checkdate();
				  	 break;
				  case 9:  //����ͨѶ¼�ļ����� 
				    eee.outfile();
				    break; 
				  case 10:  //�˳����� 
				      return 0; 
				}
			  }
				cout<<"���س������ز˵���"; 
			    getch();
				system("cls");
				goto A;  //�����������˵� 
			}
