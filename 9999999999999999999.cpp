#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include <conio.h>
#include<stdlib.h>
#include<fstream>
#include<algorithm>
using namespace std;
class people //定义一个people类用于存储个人信息 
{
  public:
	char name[20]; //名字 
	int birthday[3]; //生日 年/月/日 
	char phone[20]; //电话 
	char email[30]; //邮箱 
	char relationship; //关系 
	char mm[30]; //学校/单位/称呼 
};
int num; //定义一个全局变量记录人数 
people student[200]; //假设最大人数为200人 
bool comparename(people a , people b) //定义一个比较函数，比较姓名用于排序 
{
	return strcmp( a.name ,b.name ) < 0; //从小到大排序 
}
bool comparebirthday(people a , people b) //定义一个比较函数，比较姓名用于排序 
{
	return a.birthday <b.birthday  ; //从小到大排序 
}
class menu :public people //定义一个菜单类实现程序所有功能 
{
public:
	
	void add() //录入信息函数 
	{
		system("cls");
		cout << "*****录入个人信息*****" << endl;
		cout << "*请输入他的姓名：";
		cin >> student[num].name; cout << endl;
		cout << "*请输入他与你的关系(1.同学,2.同事,3.亲戚,4.朋友)：";
		cin >> student[num].relationship; cout << endl;
		if (student[num].relationship == '1'){cout << "*请输入你们的学校：";
		cin >> student[num].mm; cout << endl;}
		else if (student[num].relationship == '2'){cout << "*请输入你们的单位：";
		cin >> student[num].mm; cout << endl;}
		else if (student[num].relationship == '3'){cout << "*请输入你对他的称呼：";
		cin >> student[num].mm; cout << endl;}
		else if (student[num].relationship == '4'){cout << "*请输入你们的认识地点：";
		cin >> student[num].mm; cout << endl;}
		cout << "*请输入他的生日( 年 月 日)：";
		cin >> student[num].birthday[0] >> student[num].birthday[1] >> student[num].birthday[2]; cout << endl;
		cout << "*请输入他的电话：";
		cin >> student[num].phone; cout << endl;
		cout << "*请输入他的邮箱：";
		cin >> student[num].email;
		cout << endl << "**********************"<<endl;
	}
	void modification() //修改信息函数 
	{
		int n; string m;int l=0;
		system("cls");
		cout << "******修改个人信息*****" << endl;
		if (num != 0)
		{
			cout << "*要修改的人姓名：" ; //查找修改人姓名 
			cin >> m;
			for (n = 0; n < num; n++)
			{
				if (student[n].name == m)
				{
					l=1;
					int i;
					cout << "*你要修改（1.电话；2.邮箱; 3.关系; ）："; //提供修改 电话 邮箱 关系等功能 
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
						cout<<  "*请输入要修改为什么关系(1.同学；2.同事；3.亲戚；4.朋友)：";
						cin >> r;
						student[n].relationship=r;
						char m[30];
						if(student[n].relationship=='1') 
						{
						    cout<<"输入要修改为什么共同学校：";
							cin>>m;
							strcpy(student[n].mm,m); 
						} 
				        else if(student[n].relationship=='2') 
						{
						    cout<<"输入要修改为什么共事单位：";
							cin>>m;
							strcpy(student[n].mm,m); 
						}
						else if(student[n].relationship=='3') 
						{
						    cout<<"输入要修改为什么他的称呼：";
							cin>>m;
							strcpy(student[n].mm,m); 
						}  
						else if(student[n].relationship=='4') 
						{
						    cout<<"输入要修改为什么相识地点：";
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
		if(l==0)cout<< "*没有记录此人！" << endl;
		cout << "***********************"<<endl; 
	}

	void deletes() //删除信息函数 
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
				  else if(student[n].relationship=='4') cout<<"朋友"<< endl<< "*地点："<<student[n].mm << endl<< endl;
				  cout << "*确定要删除吗？（y/n）：";        //确认是否删除 
				  
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
					cout<<endl<<"*未删除！"<<endl; 
				  }
				}
			}
            
		}
		else cout << "*无记录！" << endl;
		if(i==0)cout<< "*没有记录此人！" << endl;
		cout << "***********************"<<endl;
	}

	void show() //列出所有信息 
	{
		int n;int i=0;
		cout << "*你想列出（1.全部信息；2.按关系列出；）" << endl;
		cout << "*请输入1-2：";
		int x;cin>>x;
		switch(x)
		{
		  case 1:
		  system("cls");
		  cout << "******列出全部个人信息*****" << endl;
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
				else if(student[n].relationship=='4') cout<<"朋友"<< endl<< "*地点："<<student[n].mm << endl<< endl;
		    }
		  else cout << "*无记录！" << endl;
		  cout << "***************************"<<endl;
		  break;
		  case 2:
		  	cout << "*你想列出（1.同学；2.同事；3.亲戚；4.朋友）" << endl;
			cout << "*请输入1-4：";
		  	int y;cin>>y;
			switch(y)
			{
				case 1:
				   system("cls");
		           cout << "******列出同学的个人信息*****" << endl;
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
		           if(i==0)cout<< "*记录中没有同学的信息！" << endl;
		           cout << "*****************************"<<endl;
				   break;
				case 2:
				   system("cls");
		           cout << "******列出同事的个人信息*****" << endl;
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
		           if(i==0)cout<< "*记录中没有同事的信息！" << endl;
		           cout << "*****************************"<<endl;
				   break;
				case  3:
				   system("cls");
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
		           if(i==0)cout<< "*记录中没有亲戚的信息！" << endl;
		           cout << "*****************************"<<endl;
				   break;
				case 4:
				   system("cls");
		           cout << "******列出朋友的个人信息*****" << endl;
		           if (num != 0)
			       for (n = 0; n < num; n++)
			       {
				        if (student[n].relationship == '4')
				        {
			                  cout << "*姓名：" << student[n].name << endl;
				              cout << "*生日：" << student[n].birthday[0] << "/" << student[n].birthday[1] << "/" << student[n].birthday[2] << endl;
				              cout << "*电话：" << student[n].phone << endl;
				              cout << "*邮箱：" << student[n].email << endl;
				              cout << "*地点：" << student[n].mm << endl;
				              cout <<endl;
				              i=1;
			            }
			       }
		           else cout << "*无记录！" << endl;
		           if(i==0)cout<< "*记录中没有朋友的信息！" << endl;
		           cout << "*****************************"<<endl;
		           break;
			}
			
		} 
	}

	void checkname()  //按姓名查找信息 
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
			    if(student[n].relationship=='1') cout<<"同学"<< endl<< "*学校："<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='2') cout<<"同事"<< endl<< "*单位："<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='3') cout<<"亲戚"<< endl<< "*称呼："<<student[n].mm << endl<< endl;
				else if(student[n].relationship=='4') cout<<"朋友"<< endl<< "*地点："<<student[n].mm << endl<< endl;
				i=1;
			}
		  }
	    }
		else cout << "*无记录！" << endl;
		if(i==0)cout<< "*没有记录此人！" << endl;
		cout << "***********************"<<endl;
	}
	
	void outfile() //将所有信息存入txt文件中 
	{
	   system("cls");
	   cout << "******将个人信息存入文件*****" << endl;
		if (num != 0)
		{
		  {fstream outfile;
		  outfile.open( "个人信息管理系统.txt", ios::out|ios::binary );
		  outfile<<num;
		  for(int n = 0; n < num; n++)
		  { outfile.write( ( char* )&student[n],sizeof( people )) ;}
		  outfile.close() ;} 
		  
		  {fstream outfile;
		  outfile.open( "个人信息管理系统1.txt", ios::out|ios::binary );
		  for(int n = 0; n < num; n++)
		  { 
		     if(student[n].relationship=='1') 
		     outfile.write( ( char* )&student[n],sizeof( people )) ;
		  }
		  outfile.close() ;} 
		  
		  {fstream outfile;
		  outfile.open( "个人信息管理系统2.txt", ios::out|ios::binary );
		  for(int n = 0; n < num; n++)
		  { 
		     if(student[n].relationship=='2') 
		     outfile.write( ( char* )&student[n],sizeof( people )) ;
		  }
		  outfile.close() ;} 
		  
		  {fstream outfile;
		  outfile.open( "个人信息管理系统3.txt", ios::out|ios::binary );
		  for(int n = 0; n < num; n++)
		  { 
		     if(student[n].relationship=='3') 
		     outfile.write( ( char* )&student[n],sizeof( people )) ;
		  }
		  outfile.close() ;} 
		  
		  {fstream outfile;
		  outfile.open( "个人信息管理系统4.txt", ios::out|ios::binary );
		  for(int n = 0; n < num; n++)
		  { 
		     if(student[n].relationship=='4') 
		     outfile.write( ( char* )&student[n],sizeof( people )) ;
		  }
		  outfile.close() ;} 
		  cout<<endl<<"*所有信息写入文件成功！"<<endl; 
	    }
		else cout << "*无记录！" << endl;
		cout << "*****************************"<<endl;
	}
	
	void paixu() //按照姓名排序 
	{
		system("cls");
		cout << "******排序个人信息*****" << endl;
		if (num != 0)
		{ 
		   cout<<"按照1.姓名排序；2.出生日期排序：";
		   int i;cin>>i;
		   switch(i)
		   {
		      case 1:
			     sort(student,student+num,comparename);break; //利用sort函数进行排序 
		      case 2:
		      	 sort(student,student+num,comparebirthday);break;//利用sort函数进行排序 
			}
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
			 else if(student[n].relationship=='4') cout<<"朋友"<< endl<< "*地点："<<student[n].mm << endl<< endl;
		   }
		}
		else cout<< "*无记录！" ; 
		cout << "***********************"<<endl;
	}
	
	void checktime() //同月出生信息查询 
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
			    if(student[n].relationship=='1') cout<<"同学"<< endl<< "*学校："<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='2') cout<<"同事"<< endl<< "*单位："<< student[n].mm << endl<< endl;
				else if(student[n].relationship=='3') cout<<"亲戚"<< endl<< "*称呼："<<student[n].mm << endl<< endl;
				else if(student[n].relationship=='4') cout<<"朋友"<< endl<< "*地点："<<student[n].mm << endl<< endl;
				x++;
			}
			 
		  }
	    }
		else cout << "*无记录！" << endl;
		if(x==0)cout<< "*无此月生日记录！" << endl;
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
	
	void CaculateWeekDay(int y, int m, int d)  //判断星期几 
    {  
       if(m==1||m==2) //把一月和二月换算成上一年的十三月和十四月  
       {  
           m+=12;  
           y--;  
       }  
       int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;  
       switch(Week)  
       {  
        case 0: cout << "（星期一）" << endl; break;  
        case 1: cout << "（星期二）" << endl; break;  
        case 2: cout << "（星期三）" << endl; break;  
        case 3: cout << "（星期四）" << endl; break;  
        case 4: cout << "（星期五）" << endl; break;  
        case 5: cout << "（星期六）" << endl; break;  
        case 6: cout << "（星期日）" << endl; break;  
       }  
    }
	  
	void checkdate() //查找指定日期内过生日的信息 
	{
		system("cls");
		cout << "********查找五天内过生日的个人信息********" << endl;
		int date[3];int i=0;
		cout<<"*请输入要查找的日期（年 月 日）：";
		cin>>date[0]>>date[1]>>date[2];
		int day1=daysOfDate(date[0],date[1],date[2]);
		cout << "*五天内过生日的人如下："<<endl;
		for(int n=0;n<num;n++)
		{
			int day2=daysOfDate(date[0],student[n].birthday[1],student[n].birthday[2]);
			
			
			if(day2-day1>=0&&day2-day1<5)
			{ 
			    if(student[n].relationship=='1') cout<<"*同学:";
				else if(student[n].relationship=='2') cout<<"*同事:";
				else if(student[n].relationship=='3') cout<<"*"<<student[n].mm<<":";
				else if(student[n].relationship=='4') cout<<"*朋友";
			    cout << student[n].name << endl;
				cout << "*生日：" << student[n].birthday[1] << "月" << student[n].birthday[2] <<"日";
				CaculateWeekDay(date[0],student[n].birthday[1],student[n].birthday[2]); 
				cout << "*电话：" << student[n].phone << endl;
				cout << "*邮箱：" << student[n].email << endl<<endl;	
				i++;
				char a[20]=".txt";
				char b[20];
				strcpy(b,student[n].name);
                strcat(b,a);
				fstream outfile;
		        outfile.open(b, ios::out|ios::binary );
		        outfile<<student[n].name<<":"<<"     "<<"祝生日快乐，健康幸福。"<<"     "<<"莫离\n";
				outfile.close();   
			}
			day2=daysOfDate(date[0]+1,student[n].birthday[1],student[n].birthday[2]);
			if(day2-day1>=0&&day2-day1<5)
			{
			    if(student[n].relationship=='1') cout<<"*同学:";
				else if(student[n].relationship=='2') cout<<"*同事:";
				else if(student[n].relationship=='3') cout<<"*"<<student[n].mm<<":";
				else if(student[n].relationship=='4') cout<<"*朋友";
			    cout << student[n].name << endl; 
				cout << "*生日：" << student[n].birthday[1] << "月" << student[n].birthday[2] <<"日";
				CaculateWeekDay(date[0]+1,student[n].birthday[1],student[n].birthday[2]);
				cout << "*电话：" << student[n].phone << endl;
				cout << "*邮箱：" << student[n].email << endl<<endl;	
				i++;
				char a[20]=".txt";
				char b[20];
				strcpy(b,student[n].name);
				cout<<b;
                strcat(b,a);
                fstream outfile;             //将过生日的人的贺卡信息写入文本文档 
		        outfile.open(b,ios::out|ios::binary);
		        outfile<<student[n].name<<":"<<'\t'<<"     "<<"祝生日快乐，健康幸福。"<<'\t'<<"                      "<<"莫离\n";
				outfile.close(); 
			}
		}
		if(i==0) cout<<"*没有人在最近五天过生日！"<<endl;
		else cout<<"*近五天过生日的有"<<i<<"人"<<endl; 
		cout << "******************************************"<<endl;
	} 

};
			
			int main()
			{
				fstream infile;   //读取txt文件中存储的信息 
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
			    cout << "***********欢迎使用学生信息管理系统！************"<<endl;   //主页显示的菜单栏 
				cout << "*                *1.录入信息；                  *" << endl
					 << " *               *2.修改信息；                 *" << endl
					 << "  *              *3.删除信息；                *" << endl
					 << "   *             *4.查找信息；               *" << endl
					 << "    *            *5.列出信息；              *" << endl
					 << "     *           *6.信息排序；             *" << endl
					 << "    *            *7.同月出生查询；          *" << endl
					 << "   *             *8.五天内过生日查询；       *"<<endl 
					 << "  *              *9.存入通讯录文件；          *" << endl
					 << " *               *10.退出；                    *" << endl
					 << "*温馨提示：退出程序时记得将信息存入通讯录文件哦！*"<<endl
					 << "**************************************************"<<endl
					 << "*请输入1-10：";
				int n;
				menu eee;
				cin >> n;
				switch (n)
				{
				  case 1: //录入功能 
					eee.add();
					num++;
					break;
				  case 2:  //修改功能 
					eee.modification();
					break;
				  case 3:  //删除功能 
					eee.deletes();
					break;
				  case 4: //姓名查找功能 
					eee.checkname();
					break;
				  case 5:  //输出信息功能
				    eee.show();
					break; 
				  case 6:  //排序功能 
				     eee.paixu();
					 break;
				  case 7:  //同月生日查询功能 
				     eee.checktime();
					 break;
				  case 8:  //指定日期五天内生日信息查询功能 
				  	 eee.checkdate();
				  	 break;
				  case 9:  //存入通讯录文件功能 
				    eee.outfile();
				    break; 
				  case 10:  //退出程序 
				      return 0; 
				}
			  }
				cout<<"按回车键返回菜单！"; 
			    getch();
				system("cls");
				goto A;  //按键返回主菜单 
			}
