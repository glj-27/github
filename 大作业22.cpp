#include<iostream>
#include<cstdio>
#include<cstring>
#include <conio.h>
#include<stdlib.h>
#include<fstream>
#include<algorithm>
using namespace std;
class people
{
public:
	char name[20];
	int birthday[3];
	char phone[20];
	char email[30];
	char relationship;
	char mm[30];
};
int num;people student[100];
bool compare(people a , people b)
{
	return strcmp( a.name ,b.name ) < 0;
}
class menu :public people
{
public:
	void add()
	{
		cout << "*****录入个人信息*****" << endl;
		cout << "*请输入他的姓名：";
		cin >> student[num].name; cout << endl;
		cout << "*请输入他与你的关系(1.同学,2.同事,3.亲戚)：";
		cin >> student[num].relationship; cout << endl;
		if (student[num].relationship == '1'){cout << "*请输入你们的学校：";
		cin >> student[num].mm; cout << endl;}
		else if (student[num].relationship == '2'){cout << "*请输入你们的单位：";
		cin >> student[num].mm; cout << endl;}
		else if (student[num].relationship == '3'){cout << "*请输入你对他的称呼：";
		cin >> student[num].mm; cout << endl;}
		cout << "*请输入他的生日( 年 月 日)：";
		cin >> student[num].birthday[0] >> student[num].birthday[1] >> student[num].birthday[2]; cout << endl;
		cout << "*请输入他的电话：";
		cin >> student[num].phone; cout << endl;
		cout << "*请输入他的邮箱：";
		cin >> student[num].email;
		cout << endl << "**********************"<<endl;
	}
	void modification()
	{
		int n; string m;int l=0;
		system("cls");
		cout << "******修改个人信息*****" << endl;
		if (num != 0)
		{
			cout << "*要修改的人姓名：" ;
			cin >> m;
			for (n = 0; n < num; n++)
			{
				if (student[n].name == m)
				{
					l=1;
					int i;
					cout << "*你要修改（1.电话；2.邮箱; 3.关系; ）：";
					cin >> i;
					switch (i)
					{
					case 1:
						char p[20];
						cout << "*请输入要修改的电话：";
						cin >> p;
						strcpy (student[n].phone,p);
						cout<<endl<<"*修改完成！"<<endl; 
						break; 
					case 2:
						char e[30];
						cout << "*请输入要修改的邮箱：";
						cin >> e;
						strcpy (student[n].email,e);
						cout<<endl<<"*修改完成！"<<endl;
						break;
					case 3:
					    char r;
						cout<<  "*请输入要修改为什么关系(1.同学；2.同事；3.亲戚；)：";
						cin >> r;
						student[n].relationship=r;
						char m[30];
						if(student[n].relationship=='1') 
						{
						    cout<<"输入要修改为什么学校：";
							cin>>m;
							strcpy(student[n].mm,m); 
						} 
				        else if(student[n].relationship=='2') 
						{
						    cout<<"输入要修改为什么单位：";
							cin>>m;
							strcpy(student[n].mm,m); 
						}
						else if(student[n].relationship=='3') 
						{
						    cout<<"输入要修改为什么称呼：";
							cin>>m;
							strcpy(student[n].mm,m); 
						}  
						  
						cout<<endl<<"*修改完成！"<<endl; 
						break ;
					}
				}
			}
		}
		else cout << "*无记录！" << endl;
		if(l==0)cout<< "*无记录！" << endl;
		cout << "**********************"<<endl; 
	}

	void deletes()
	{
		system("cls");
		cout << "******删除个人信息*****" << endl;
		int i=0;
		if (num != 0)
		{
			cout << "*请输入要删除人的姓名：";
			int n; string m;
			cin>>m;
			for (n = 0; n < num; n++)
			{
				if(student[n].name==m)
				{
				  i=1;
				  cout << "*姓名：" << student[n].name << endl;
				  cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				  cout << "*电话：" << student[n].phone << endl;
			      cout << "*邮箱：" << student[n].email << endl;
				  cout << "*关系：" ;
				  if(student[n].relationship=='1') cout<<"同学"<< endl<< "*学校："<< student[n].mm << endl<< endl;
				  else if(student[n].relationship=='2') cout<<"同事"<< endl<< "*单位："<< student[n].mm << endl<< endl;
				  else if(student[n].relationship=='3') cout<<"亲戚"<< endl<< "*称呼："<<student[n].mm << endl<< endl;
				  cout << "*确定要删除吗？（y/n）：";
				  
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
					cout<<endl<<"*删除完成！"<<endl;
					num--; 
				  }
				  else if(x == 'n')
				  {
					cout<<endl<<"*未删除！"; 
				  }
				}
			}
            
		}
		else cout << "*无记录！" << endl;
		if(i==0)cout<< "*无记录！" << endl;
		cout << "**********************"<<endl;
	}

	void ashow()
	{
	    system("cls");
		cout << "******列出全部个人信息*****" << endl;
		int n;
		if (num != 0)
			for (n = 0; n < num; n++)
			{
				cout << "*姓名：" << student[n].name << endl;
				cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				cout << "*电话：" << student[n].phone << endl;
				cout << "*邮箱：" << student[n].email << endl;
				cout << "*关系：" ;
			    if(student[n].relationship=='1') cout<<"同学"<< endl<< "*学校："<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='2') cout<<"同事"<< endl<< "*单位："<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='3') cout<<"亲戚"<< endl<< "*称呼："<<student[n].mm << endl<< endl;
		    }
		else cout << "*无记录！" << endl;
		cout << "****************************"<<endl;
	}

	void bshow()
	{
		system("cls");
		cout << "******列出同学的个人信息*****" << endl;
		int n;int i=0;
		if (num != 0)
			for (n = 0; n < num; n++)
			{
				if (student[n].relationship == '1')
				{
				 cout << "*姓名：" << student[n].name << endl;
				 cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				 cout << "*电话：" << student[n].phone << endl;
				 cout << "*邮箱：" << student[n].email << endl;
				 cout << "*学校：" << student[n].mm << endl;
				 cout <<endl;
				 i=1;
				}
			}
		else cout << "*无记录！" << endl;
		if(i==0)cout<< "*无记录！" << endl;
		cout << "*****************************"<<endl;
	}
	void cshow()
	{
	    system("cls");
		cout << "******列出同事的个人信息*****" << endl;
		int n;int i=0;
		if (num != 0)
			for (n = 0; n < num; n++)
			{
				if (student[n].relationship == '2')
				{
				 cout << "*姓名：" << student[n].name << endl;
				 cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				 cout << "*电话：" << student[n].phone << endl;
				 cout << "*邮箱：" << student[n].email << endl;
				 cout << "*单位：" << student[n].mm << endl;
				 cout <<endl;
				 i=1;
			    }
			}
		else cout << "*无记录！" << endl;
		if(i==0)cout<< "*无记录！" << endl;
		cout << "*****************************"<<endl;
	}
	void dshow()
	{
	    system("cls");
		int n;int i=0;
		cout << "******列出亲戚的个人信息*****" << endl;
		if (num != 0)
			for (n = 0; n < num; n++)
			{
				if (student[n].relationship == '3')
				{
			     cout << "*姓名：" << student[n].name << endl;
				 cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				 cout << "*电话：" << student[n].phone << endl;
				 cout << "*邮箱：" << student[n].email << endl;
				 cout << "*称呼：" << student[n].mm << endl;
				 cout <<endl;
				 i=1;
			    }
			}
		else cout << "*无记录！" << endl;
		if(i==0)cout<< "*无记录！" << endl;
		cout << "*****************************"<<endl;
	}

	void checkname()
	{
		int n; string m;int i=0;
		system("cls");
		cout << "******查找个人信息*****" << endl;
		if (num != 0)
		{
		  cout << "*请输入要查找姓名：";
		  cin >> m;
		  for (n = 0; n < num; n++)
		  {
			if (student[n].name == m)
			{
				cout << "*姓名：" << student[n].name << endl;
				cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				cout << "*电话：" << student[n].phone << endl;
				cout << "*邮箱：" << student[n].email << endl;
				cout << "*关系：";
			    if(student[n].relationship='1') cout<<"同学"<< endl<< "*学校："<< student[n].mm << endl<< endl;
				else if(student[n].relationship='2') cout<<"同事"<< endl<< "*单位："<< student[n].mm << endl<< endl;
				else if(student[n].relationship='3') cout<<"亲戚"<< endl<< "*称呼："<<student[n].mm << endl<< endl;
				i=1;
			}
		  }
	    }
		else cout << "*无记录！" << endl;
		if(i==0)cout<< "*无记录！" << endl;
		cout << "**********************"<<endl;
	}
	
	void outfile()
	{
	   system("cls");
	   cout << "******将个人信息存入文件*****" << endl;
		if (num != 0)
		{
		  fstream outfile;
		  outfile.open( "个人信息管理系统.txt", ios::out|ios::binary );
		  outfile<<num;
		  for(int n = 0; n < num; n++)
		  { outfile.write( ( char* )&student[n],sizeof( people )) ;}
		  outfile.close() ;
		  cout<<endl<<"*写入文件成功！"<<endl; 
	    }
		else cout << "*无记录！" << endl;
		cout << "*****************************"<<endl;
	}
	
	void paixu()
	{
		system("cls");
		cout << "******排序个人信息*****" << endl;
		sort(student,student+num,compare);

		for (int n = 0; n < num; n++)
		{
			cout << "*姓名：" << student[n].name << endl;
			cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
			cout << "*电话：" << student[n].phone << endl;
			cout << "*邮箱：" << student[n].email << endl;
			cout << "*关系：" ;
			if(student[n].relationship=='1') cout<<"同学"<< endl<< "*学校："<< student[n].mm << endl<< endl;
			else if(student[n].relationship=='2') cout<<"同事"<< endl<< "*单位："<< student[n].mm << endl<< endl;
			else if(student[n].relationship=='3') cout<<"亲戚"<< endl<< "*称呼："<<student[n].mm << endl<< endl;
		}
		cout << "**********************"<<endl; 
	}
	
	void checktime()
	{
		system("cls");
		cout << "******查找同月出生的个人信息*****" << endl;
		double m;int x=0; 
		if (num != 0)
		{
		  cout << "*请输入要查找月份：";
		  cin >> m;
		  for (int n = 0; n < num; n++)
		  {
			if (student[n].birthday[1] == m)
			{
				cout << "*姓名：" << student[n].name << endl;
				cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				cout << "*电话：" << student[n].phone << endl;
				cout << "*邮箱：" << student[n].email << endl;
				cout << "*关系：";
			    if(student[n].relationship='1') cout<<"同学"<< endl<< "*学校："<< student[n].mm << endl<< endl;
				else if(student[n].relationship='2') cout<<"同事"<< endl<< "*单位："<< student[n].mm << endl<< endl;
				else if(student[n].relationship='3') cout<<"亲戚"<< endl<< "*称呼："<<student[n].mm << endl<< endl;
				x++;
			}
			 
		  }
	    }
		else cout << "*无记录！" << endl;
		if(x==0)cout<< "*无记录！" << endl;
		else cout<<"*"<<m<<"月份出生的人数为："<<x<<"人"<<endl;
		cout << "**********************************"<<endl;
	}
	 
    int runyear(int y)//判断是否是闰年  
    {  
       return y%4==0&&y%100!=0||y%400==0;//真返回为1，假为0  
    }  
    int daysOfMonth(int y,int m)  
    {  
       int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
       if(m!=2)  return day[m-1];  
       else  return 28+runyear(y);  
    }   
    int daysOfDate(int y,int m,int d)//计算一共的天数  
    {  
        int days=d;  
        for(int a=1;a<y;a++)//计算年  
        days+=365+runyear(a);  
        for(int b=1;b<m;b++)//计算月  
        days+=daysOfMonth(y,b);   
        return days;  
    }  
	void checkdate()
	{
		system("cls");
		cout << "******查找五天内过生日的个人信息*****" << endl;
		int date[3];int i=0;
		cout<<"*请输入要查找的日期（年 月 日）：";
		cin>>date[0]>>date[1]>>date[2];
		int day1=daysOfDate(date[0],date[1],date[2]);
		cout << "*五天内过生日的人如下："<<endl;
		for(int n;n<num;n++)
		{
			int day2=daysOfDate(date[0],student[n].birthday[1],student[n].birthday[2]);
			if(day2-day1>=0&&day2-day1<5)
			{ 
			    cout << "*姓名：" << student[n].name << endl;
				cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				cout << "*电话：" << student[n].phone << endl;
				cout << "*邮箱：" << student[n].email << endl;
				cout << "*关系：";
			    if(student[n].relationship='1') cout<<"同学"<< endl<< "*学校："<< student[n].mm << endl<< endl;
				else if(student[n].relationship='2') cout<<"同事"<< endl<< "*单位："<< student[n].mm << endl<< endl;
				else if(student[n].relationship='3') cout<<"亲戚"<< endl<< "*称呼："<<student[n].mm << endl<< endl;	
				i++;
			}
		}
		if(i==0) cout<<"*没有人在最近五天过生日！"<<endl;
		else cout<<"近五天过生日的有"<<i<<"人"<<endl; 
		cout << "*************************************"<<endl;
	} 

};
			
			int main()
			{
				fstream infile;
		        infile.open(  "个人信息管理系统.txt", ios::in|ios::binary );
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
			    cout << "******欢迎使用学生信息管理系统！******"<<endl;
				cout << "*1.录入信息；" << endl
					 << "*2.修改信息；" << endl
					 << "*3.删除信息；" << endl
					 << "*4.查找信息；" << endl
					 << "*5.列出信息；" << endl
					 << "*6.信息排序；" << endl
					 << "*7.同月出生查询；" << endl
					 << "*8.五天内过生日查询； "<<endl 
					 << "*9.写入文件；" << endl
					 << "*10.退出；" << endl
					 << "*温馨提示：退出程序时记得将信息写入文件哦！ "<<endl 
					 << "*请输入1-10：";
				int n;
				menu eee;
				cin >> n;
				switch (n)
				{
				  case 1:
					eee.add();
					num++;
					break;
				  case 2:
					eee.modification();
					break;
				  case 3:
					eee.deletes();
					break;
				  case 4:
					eee.checkname();
					break;
				  case 5:
				  {
					cout << "*你想列出（1.全部信息；2.按关系列出；）" << endl;
					cout << "*请输入1-2：";
					int m;
					cin >> m;
					switch (m)
					{
					     case 1:
						     eee.ashow();
						     break;
					     case 2:
					     {
						    cout << "*你想列出（1.同学；2.同事；3.亲戚）" << endl;
						    cout << "*请输入1-3：";
					        int l;
						    cin >> l;
						    switch (l)
						    {
						        case 1:
							        eee.bshow();break;
						        case 2:
							        eee.cshow();break;
						        case 3:
							        eee.dshow();break;
						    }
					     }
					     break;
					}
				  }
				  break;
				  case 6:
				     eee.paixu();
					 break;
				  case 7:
				     eee.checktime();
					 break;
				  case 8:
				  	 eee.checkdate();
				  	 break;
				  case 9:
				    eee.outfile();
				    break; 
				  case 10:
				      return 0; 
				}
			}
				cout<<"按回车键返回菜单！"; 
			    getch();
				system("cls");
				goto A;
			}
