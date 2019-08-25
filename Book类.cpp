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
	cout<<"存书情况："<<endl;
	cout<<"书名:"<<bookname<<'\t'<<"价格："<<price<<'\t'<<"数量："<<number<<endl; 
} 
void Book::borrow()
{
	if(number==0){cout<<"已没有书。"<<endl;}
	else {number=number-1;cout<<"借出一本 现在还有"<<number<<"本"<<endl;}
}
void Book::restore()
{
	number=number+1;cout<<"还回一本 现在还有"<<number<<"本"<<endl;
} 
void Book::setbook(string nam,double pri,int num)
{
	bookname=nam;price=pri;number=num;
}
int main()
{	Book book1;
	book1.setbook("高数下",28.90,49);
	cout<<"是否要借阅/返还书籍（b/r）:";
	char a;
	cin>>a;
	switch(a)
	{
		case 'b':  book1.borrow();break;
		case 'r':  book1.restore();
	}
	book1.display();
}
