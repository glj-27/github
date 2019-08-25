#include <iostream>
using namespace std;
class Integer 
{
  private:
    short a;
  public:
    Integer (short n=0){ a=n;}
    Integer operator +(Integer);
    Integer operator -(Integer);
    Integer operator *(Integer);
    Integer operator /(Integer);
    Integer operator =(Integer);
    void display() { cout<<a<<endl; }
};
Integer Integer::operator+(Integer x)
{
 Integer temp;
  if(a+x.a<-32768||a+x.a>32767) 
{ cout<<"Data overflow!"<<endl;}
  temp.a=a+x.a;
  return temp; 
}
Integer Integer::operator-(Integer x)
{
 Integer temp;
if(a-x.a<-32768||a-x.a>32767) 
{ cout<<"Data overflow!"<<endl;}
temp.a=a-x.a;
return temp; 
}
Integer Integer::operator*(Integer x)
{
 Integer temp;
if(a*x.a<-32768||a*x.a>32767)
 {cout<<"Data overflow!"<<endl;}
temp.a=a*x.a;
return temp; 
}
Integer  Integer::operator/(Integer x)
{
 Integer temp;
 if(a/x.a<-32768||a/x.a>32767) 
{ cout<<"Data overflow!"<<endl;}
 temp.a=a/x.a;
 return temp;
}
 Integer Integer::operator=(Integer x)
 {
 a=x.a;
	   return *this;
 }
int main()
{
 Integer a(2),b(7),c;
cout<<"a=";a.display();
cout<<"b=";b.display();
c=a+b;
cout<<"c=a+b="; c.display();
c=a-b;
cout<<"c=a-b="; c.display();
c=a*b;
cout<<"c=a*b="; c.display();
c=a/b;
cout<<"c=a/b="; c.display();
}

