#include<iostream>
#include<cstring>
using namespace std;
class Book
{
	private:
		string bookname;double price;int number;
	public:
		void display(); 
		void borrow();
		void restore();
		void setbook(string,double,int);
};
void Book::display()
{
	cout<<"���������"<<endl;
	cout<<"����:"<<bookname<<'\t'<<"�۸�"<<price<<'\t'<<"������"<<number<<endl; 
} 
void Book::borrow()
{
	if(number==0){cout<<"��û���顣"<<endl;}
	else {number=number-1;cout<<"���һ�� ���ڻ���"<<number<<"��"<<endl;}
}
void Book::restore()
{
	number=number+1;cout<<"����һ�� ���ڻ���"<<number<<"��"<<endl;
} 
void Book::setbook(string nam,double pri,int num)
{
	bookname=nam;price=pri;number=num;
}
int main()
{	Book book1;
	book1.setbook("������",28.90,49);
	cout<<"�Ƿ�Ҫ����/�����鼮��b/r��:";
	char a;
	cin>>a;
	switch(a)
	{
		case 'b':  book1.borrow();break;
		case 'r':  book1.restore();
	}
	book1.display();
}
