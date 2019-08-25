#include<iostream>
#include<cstring>
using namespace std;
class Person 
{ 
   public:
   Person(char *i="\0",char *n="\0",double a=0.0):basicSalary(a)
   {
	   strcpy_s(id,i);
	   strcpy_s(name,n);
   }
   virtual void input()
   {
		 cout<<"Ա��idΪ��";
		 cin>>id;
		 cout<<"Ա������Ϊ��";
		 cin>>name;
		 cout<<"��������Ϊ��";
		 cin>>basicSalary;
   }
  virtual double pay()=0;
  virtual void print()=0;
protected:
	char id[20], name[20];
	double basicSalary;
};
class Manager : virtual public Person
 {
   public:
	   Manager(char *i="\0",char *n="\0",double a=0.0,double b=0.0,double c=0):Person(i,n,a),days(c),dprice(b){}
void input()
  {
	  Person::input();
      Manager::inputM();
  }
    void inputM()
	{
		cout<<"ÿ���ϰ������Ϊ��";
		cin>>days;
		cout<<"ÿ�켨ЧΪ��";
		cin>>dprice;
	}
	double pay()
	{
		return basicSalary+days*dprice;
	}
	void print()
	{
		cout<<"��нΪ"<<pay()<<"Ԫ"<<endl<<endl;
	}
protected:
      double days; 
	  double dprice;
 };

 class Teacher : virtual public Person
 {
 public:
	 Teacher::Teacher(char *i="\0",char *n="\0",double a=0.0, double b=0.0,double c=0):Person(i,n,a),numberofCourse(c),cprice(b){}
  void input()
  {
	  Person::input();
	  Teacher::inputT();
  }
  
  void inputT()
  {
	  cout<<"ÿ���ڿεĽ���Ϊ��";
	  cin>>numberofCourse;
	  cout<<"ÿ�ڿε���Ϊ��";
	  cin>>cprice;
  }
  double pay()
  {
	  return basicSalary+numberofCourse*cprice;
  }
  void print()
  {
	  cout<<"��нΪ"<<pay()<<"Ԫ"<<endl<<endl;
  }
 protected:
      double numberofCourse;
	  double cprice;
  };

  class ManagerTeacher :  public Manager,public Teacher 
  {
  public:
	  ManagerTeacher::ManagerTeacher(char *i="\0",char *n="\0",double a=0.0,double b=0.0, double c=0,double d=0.0, double  e=0,double f=0.0):Teacher(i,n,a,c,b),Manager(i,n,a,e,d)
	  {
		  jobSalary=f;
	  }
	  void input()
	  {
		  Person::input();
		  inputT();
		  inputM();
		  inputTM();
	  }
  void inputTM()
  {
	  cout<<"��λ����Ϊ��";
	  cin>>jobSalary;
  }
  double pay()
  {
	  return basicSalary+days*dprice+numberofCourse*cprice+jobSalary;
  }
  void print()
  {
	  cout<<"��нΪ"<<pay()<<"Ԫ"<<endl<<endl;
  }
  protected:
      double jobSalary;
  };
  
int main()
{
   int i;Person *p;
   do
   {
	   cout<<"������Ա�����ԣ�1..רְ������Ա��2.��ʦ��3.˫��������Ա0.�˳���"<<endl;
	   cin>>i;
	   if (i==0) return 0;
	   switch(i)
	   {
	   case 1:
		   Manager b; 
		   p=&b;		  
		   break;
	 case 2:
		  Teacher c;
		  p=&c;
		  break;
	 case 3:
		  ManagerTeacher d;
		  p=&d;
		  break;
	 default:
		 cout<<"�������"<<endl;
		 continue;
	   }
	   p->input();
	   p->print();
   }while(i);   
 }

