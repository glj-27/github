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
			cout<<"*****¼�������Ϣ*****"<<endl;
			
			cout<<"����������������";
			cin>>student[num].name;cout<<endl;
			
			cout<<"������������Ĺ�ϵ��";
			cin>>student[num].relationship;cout<<endl;
			if(student[num].relationship=="ͬѧ")cout<<"���������ǵ�ѧУ��";
			cin>>student[num].mm;cout<<endl;
			if(student[num].relationship=="ͬ��")cout<<"���������ǵĵ�λ��";
			cin>>student[num].mm;cout<<endl;
			if(student[num].relationship=="����")cout<<"������������ĳƺ���";
			cin>>student[num].mm;cout<<endl;
			
			cout<<"�������������գ�";
			cin>>student[num].birthday[0]>>student[num].birthday[1]>>student[num].birthday[2];cout<<endl;
			
			cout<<"���������ĵ绰��";
			cin>>student[num].phone;cout<<endl;
			
			cout<<"�������������䣺";
			cin>>student[num].email;
			num++;
			cout<<endl<<"**********************";
		}

		void modification()
		{
			int n;string m;
			system("cls");
			
			cout<<"******�޸ĸ�����Ϣ*****"<<endl;
			
			if(num!=0)
			{
			  cout<<"Ҫ�޸ĵ���������"<<endl;
			  cin>>m;
			  for(n=0;n<num;n++)
			  {
				if(student[n].name==m)
                {
				  int i;
				  cout<<"��Ҫ�޸ģ�1.�绰��2.���䣩��"; 
				  cin>>i;
				  switch(i)
				  {
				  	case 1:
				  		double p;
				  		cout<<"������Ҫ�޸ĵĵ绰��";
				  		cin>>p;
				  		student[n].phone=p;
				  	case 2:
				  		string e;
				  		cout<<"������Ҫ�޸ĵ����䣺";
				  		cin>>e;
				  		student[n].email=e;
				  }
				}
			  }
			}
			else cout<<"�޼�¼��"<<endl<<"����������������˵���"; 
			getch();
			return 0;
		}
		
		void deletes()
		{
			system("cls");
			cout<<"******ɾ��������Ϣ*****"<<endl;
			if(num!=0)
			{
				cout<<"Ҫɾ������������";
				int n;string m;
				for(n=0;n<num;n++)
				{
					cout<<"������"<<student[n].name<<endl;
					cout<<"���գ�"<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
					cout<<"�绰��"<<student[n].phone<<endl;
					cout<<"���䣺"<<student[n].email<<endl;
					cout<<"��ϵ��"<<student[n].relationship<<endl;
					if(student[n].relationship=="ͬѧ")cout<<"ѧУ��";
			    	cout<<student[n].mm<<endl;
			    	if(student[n].relationship=="ͬ��")cout<<"��λ��";
			    	cout<<student[n].mm<<endl;
			    	if(student[n].relationship=="����")cout<<"�ƺ���";
			    	cout<<student[n].mm<<endl;
			    	cout<<"ȷ��Ҫɾ���𣿣�y/n����";
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
				cout<<"������"<<student[n].name<<endl;
				cout<<"���գ�"<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				cout<<"�绰��"<<student[n].phone<<endl;
				cout<<"���䣺"<<student[n].email<<endl;
				cout<<"��ϵ��"<<student[n].relationship<<endl;
				if(student[n].relationship=="ͬѧ")cout<<"ѧУ��";
			    cout<<student[n].mm<<endl;
			    if(student[n].relationship=="ͬ��")cout<<"��λ��";
			    cout<<student[n].mm<<endl;
			    if(student[n].relationship=="����")cout<<"�ƺ���";
			    cout<<student[n].mm<<endl;
			    if(n+1<num)
	            {
		             system("pause");
	            }
			}
			else cout<<"�޼�¼��"<<endl<<"����������������˵���";
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
				if(student[n].relationship=="ͬѧ")
				cout<<"������"<<student[n].name<<endl;
				cout<<"���գ�"<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				cout<<"�绰��"<<student[n].phone<<endl;
				cout<<"���䣺"<<student[n].email<<endl;
				cout<<"ѧУ��"<<student[n].mm<<endl;
				if(n+1<num)
	            {
		             system("pause");
	            }
				else cout<<"�޼�¼��"<<endl<<"����������������˵���";
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
				if(student[n].relationship=="ͬ��")
				cout<<"������"<<student[n].name<<endl;
				cout<<"���գ�"<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				cout<<"�绰��"<<student[n].phone<<endl;
				cout<<"���䣺"<<student[n].email<<endl;
				if(n+1<num)
	            {
		             system("pause");
	            }
				else cout<<"�޼�¼��"<<endl<<"����������������˵���";
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
				if(student[n].relationship=="����")
				cout<<"������"<<student[n].name<<endl;
				cout<<"���գ�"<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				cout<<"�绰��"<<student[n].phone<<endl;
				cout<<"���䣺"<<student[n].email<<endl;
				if(n+1<num)
	            {
		             system("pause");
	            }
				else cout<<"�޼�¼��"<<endl<<"����������������˵���";
			    getch();
			    return 0; 	
		    }
	    }
	    
	    void checkname()
		{
			int n;string m;
			system("cls");
			if(num!=0)
			cout<<"������Ҫ����������";
			cin>>m;
			for(n=0;n<num;n++)
			{
				if(student[n].name==m)
				{
				 cout<<"������"<<student[n].name<<endl;
				 cout<<"���գ�"<<student[n].birthday[0]<<"/"<<student[n].birthday[1]<<"/"<<student[n].birthday[2]<<endl;
				 cout<<"�绰��"<<student[n].phone<<endl;
				 cout<<"���䣺"<<student[n].email<<endl;
			 	 cout<<"��ϵ��"<<student[n].relationship<<endl;
				 if(student[n].relationship=="ͬѧ")cout<<"ѧУ��";
			     cout<<student[n].mm<<endl;
			     if(student[n].relationship=="ͬ��")cout<<"��λ��";
			     cout<<student[n].mm<<endl;
			     if(student[n].relationship=="����")cout<<"�ƺ���";
			     cout<<student[n].mm<<endl;
			    }
		    } 
        }
};
int main()
{
	cout<<"��ӭʹ��ѧ����Ϣ����ϵͳ��" ;
	cout<<"1.¼����Ϣ��"<<endl
	    <<"2.�޸���Ϣ��"<<endl
		<<"3.ɾ����Ϣ��"<<endl
		<<"4.������Ϣ��"<<endl
		<<"5.�г���Ϣ��"<<endl
		<<"������1-5��";
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
					cout<<"�����г���1.ȫ����Ϣ��2.����ϵ�г�����"<<endl;
					cout<<"������1-2��";
					int m;
					cin>>m;
					switch(m)
					{
						case 1:
							eee.ashow();
						case 2:
							{
							    cout<<"�����г���1.ͬѧ��2.ͬ�£�3.���ݣ�"<<endl;
					            cout<<"������1-3��";
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

