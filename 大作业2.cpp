#include<iostream>
#include<cstdio>
#include<cstring>
#include <conio.h>
#include<stdlib.h>
using namespace std; 
class people
{
	public:
		string name;
		double birthday[3];
		double phone;
		string email;
		string relationship;
		string mm;                                       
};

class menu:public people
{
    public:
    	int num;
		people student[100];
		
		void add()
		{
			cout<<"*****录入个人信息*****"<<endl;
			
			cout<<"请输入他的姓名：";
			cin>>student[num].name;cout<<endl;
			
			cout<<"请输入他与你的关系：";
			cin>>student[num].relationship;cout<<endl;
			if(student[num].relationship=="同学")cout<<"请输入你们的学校：";
			cin>>student[num].mm;cout<<endl;
			if(student[num].relationship=="同事")cout<<"请输入你们的单位：";
			cin>>student[num].mm;cout<<endl;
			if(student[num].relationship=="亲戚")cout<<"请输入你对他的称呼：";
			cin>>student[num].mm;cout<<endl;
			
			cout<<"请输入他的生日：";
			cin>>student[num].birthday[0]>>student[num].birthday[1]>>student[num].birthday[2];cout<<endl;
			
			cout<<"请输入他的电话：";
			cin>>student[num].phone;cout<<endl;
			
			cout<<"请输入他的邮箱：";
			cin>>student[num].email;
			num++;
			cout<<endl<<"**********************";
		}

		void modification()
		{
			int n;string m;
			system("cls");
			
			cout<<"******修改个人信息*****"<<endl;
			
			if(num!=0)
			{
			  cout<<"要修改的人姓名："<<endl;
			  cin>>m;
			  for(n=0;n<num;n++)
			  {
				if(student[n].name==m)
                {
				  int i;
				  cout<<"你要修改（1.电话；2.邮箱）："; 
				  cin>>i;
				  switch(i)
				  {
				  	case 1:
				  		double p;
				  		cout<<"请输入要修改的电话：";
				  		cin>>p;
				  		student[n].phone=p;
				  	case 2:
				  		string e;
				  		cout<<"请输入要修改的邮箱：";
				  		cin>>e;
				  		student[n].email=e;
				  }
				}
			  }
			}
			else cout<<"无记录！"<<endl<<"输入任意键返回主菜单；"; 
			getch();
			return 0;
		}
		
		void deletes()
		{
			system("cls");
			cout<<"******删除个人信息*****"<<endl;
			if(num!=0)
			{
				cout<<"要删除的人姓名：";
				int n;string m;
				for(n=0;n<num;n++)
				{
					cout<<"姓名："<<student[n].name<<endl;
					cout<<"生日："<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
					cout<<"电话："<<student[n].phone<<endl;
					cout<<"邮箱："<<student[n].email<<endl;
					cout<<"关系："<<student[n].relationship<<endl;
					if(student[n].relationship=="同学")cout<<"学校：";
			    	cout<<student[n].mm<<endl;
			    	if(student[n].relationship=="同事")cout<<"单位：";
			    	cout<<student[n].mm<<endl;
			    	if(student[n].relationship=="亲戚")cout<<"称呼：";
			    	cout<<student[n].mm<<endl;
			    	cout<<"确定要删除吗？（y/n）：";
				    if (getch()=='y'||'Y')
					{
					   student[n].name="";student[n].birthday[0]=0;student[n].birthday[1]=0;student[n].birthday[2]=0;student[n].relationship="";student[n].mm="";
					}
					else terurn 0 ; 
				}
				
				
			} 
		}
		
		void ashow()
		{
			int n;
			system("cls");
			if(num!=0)
			for(n=0;n<num;n++)
			{
				cout<<"姓名："<<student[n].name<<endl;
				cout<<"生日："<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				cout<<"电话："<<student[n].phone<<endl;
				cout<<"邮箱："<<student[n].email<<endl;
				cout<<"关系："<<student[n].relationship<<endl;
				if(student[n].relationship=="同学")cout<<"学校：";
			    cout<<student[n].mm<<endl;
			    if(student[n].relationship=="同事")cout<<"单位：";
			    cout<<student[n].mm<<endl;
			    if(student[n].relationship=="亲戚")cout<<"称呼：";
			    cout<<student[n].mm<<endl;
			    if(n+1<num)
	            {
		             system("pause");
	            }
			}
			else cout<<"无记录！"<<endl<<"输入任意键返回主菜单；";
			getch();
			return 0; 
		}
		
		void bshow()
		{
			int n;
			system("cls");
			if(num!=0)
			for(n=0;n<num;n++)
			{
				if(student[n].relationship=="同学")
				cout<<"姓名："<<student[n].name<<endl;
				cout<<"生日："<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				cout<<"电话："<<student[n].phone<<endl;
				cout<<"邮箱："<<student[n].email<<endl;
				cout<<"学校："<<student[n].mm<<endl;
				if(n+1<num)
	            {
		             system("pause");
	            }
				else cout<<"无记录！"<<endl<<"输入任意键返回主菜单；";
			    getch();
			    return 0;
		    }
		}
		void cshow()
		{
			int n;
			system("cls");
			if(num!=0)
			for(n=0;n<num;n++)
			{
				if(student[n].relationship=="同事")
				cout<<"姓名："<<student[n].name<<endl;
				cout<<"生日："<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				cout<<"电话："<<student[n].phone<<endl;
				cout<<"邮箱："<<student[n].email<<endl;
				if(n+1<num)
	            {
		             system("pause");
	            }
				else cout<<"无记录！"<<endl<<"输入任意键返回主菜单；";
			    getch();
			    return 0;
		    }
		}		
		void dshow()
		{
			int n;
			system("cls");
			if(num!=0)
			for(n=0;n<num;n++)
			{
				if(student[n].relationship=="亲戚")
				cout<<"姓名："<<student[n].name<<endl;
				cout<<"生日："<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				cout<<"电话："<<student[n].phone<<endl;
				cout<<"邮箱："<<student[n].email<<endl;
				if(n+1<num)
	            {
		             system("pause");
	            }
				else cout<<"无记录！"<<endl<<"输入任意键返回主菜单；";
			    getch();
			    return 0; 	
		    }
	    }
	    
	    void checkname()
		{
			int n;string m;
			system("cls");
			if(num!=0)
			cout<<"请输入要查找姓名：";
			cin>>m;
			for(n=0;n<num;n++)
			{
				if(student[n].name==m)
				{
				 cout<<"姓名："<<student[n].name<<endl;
				 cout<<"生日："<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				 cout<<"电话："<<student[n].phone<<endl;
				 cout<<"邮箱："<<student[n].email<<endl;
			 	 cout<<"关系："<<student[n].relationship<<endl;
				 if(student[n].relationship=="同学")cout<<"学校：";
			     cout<<student[n].mm<<endl;
			     if(student[n].relationship=="同事")cout<<"单位：";
			     cout<<student[n].mm<<endl;
			     if(student[n].relationship=="亲戚")cout<<"称呼：";
			     cout<<student[n].mm<<endl;
			    }
		    } 
        }
};
int main()
{
	cout<<"欢迎使用学生信息管理系统！" ;
	cout<<"1.录入信息；"<<endl
	    <<"2.修改信息；"<<endl
		<<"3.删除信息；"<<endl
		<<"4.查找信息；"<<endl
		<<"5.列出信息；"<<endl
		<<"请输入1-5：";
		int n;
		menu eee;
		cin>>n;
		switch(n)
		{
			case 1:
				eee.add();
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
					cout<<"你想列出（1.全部信息；2.按关系列出；）"<<endl;
					cout<<"请输入1-2：";
					int m;
					cin>>m;
					switch(m)
					{
						case 1:
							eee.ashow();
						case 2:
							{
							    cout<<"你想列出（1.同学；2.同事；3.亲戚）"<<endl;
					            cout<<"请输入1-3：";
					            int l;
					            cin>>l;
					            switch(l)
					            {
					            	case 1:
					            	  eee.bshow();
					            	case 2:
					            	  eee.cshow();
					            	case 3:
					            	  eee.dshow();
							    }
							}
					} 
				}
				break;
		} 
}

