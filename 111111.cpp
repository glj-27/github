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
		 cout<<"员工id为：";
		 cin>>id;
		 cout<<"员工姓名为：";
		 cin>>name;
		 cout<<"基本工资为：";
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
		cout<<"每月上班的天数为：";
		cin>>days;
		cout<<"每天绩效为：";
		cin>>dprice;
	}
	double pay()
	{
		return basicSalary+days*dprice;
	}
	void print()
	{
		cout<<"月薪为"<<pay()<<"元"<<endl<<endl;
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
	  cout<<"每月授课的节数为：";
	  cin>>numberofCourse;
	  cout<<"每节课单价为：";
	  cin>>cprice;
  }
  double pay()
  {
	  return basicSalary+numberofCourse*cprice;
  }
  void print()
  {
	  cout<<"月薪为"<<pay()<<"元"<<endl<<endl;
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
	  cout<<"岗位工资为：";
	  cin>>jobSalary;
  }
  double pay()
  {
	  return basicSalary+days*dprice+numberofCourse*cprice+jobSalary;
  }
  void print()
  {
	  cout<<"月薪为"<<pay()<<"元"<<endl<<endl;
  }
  protected:
      double jobSalary;
  };
  
int main()
{
   int i;Person *p;
   do
   {
	   cout<<"请输入员工属性（1..专职行者人员；2.教师；3.双肩挑的人员0.退出）"<<endl;
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
		 cout<<"输入出错！"<<endl;
		 continue;
	   }
	   p->input();
	   p->print();
   }while(i);   
 }

