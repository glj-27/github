#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>
using namespace std;
struct txrec
{
char no[6];
char name[20];
char tel[9];
char postc[7];
char addr[30];
};
int main()
{
struct txrec gzrec;  int i;
char filename[20], num[6];
fstream infile;
cout << "请输入通讯录文件名:";
cin >> filename ;		
infile.open( filename, ios::in|ios::binary );	
if ( !infile )
{  cerr << "文件不能打开！" << endl;
abort();
}
infile.seekg( 0,ios::end );
long posend = infile.tellp();
infile.seekg( 0,ios::beg );
cout << "请输入职工编号:" ;
cin >> num;
do 
{
    infile.read(( char * )&gzrec,sizeof( txrec ));
} while ( strcmp( gzrec.no,num ) != 0 && long(infile.tellp()) != posend );
if ( strcmp( gzrec.no,num ) == 0 )
{
cout << "该职工的记录找到了！" << endl;
cout << "编号:" << gzrec.no << endl;		
cout << "姓名:"<< gzrec.name << endl;
cout << "电话号码:"<< gzrec.tel << endl;
cout << "邮政编码:" << gzrec.postc << endl;
cout << "通信地址:" << gzrec.addr << endl;
}
else
{ 
cout << "该职工的记录找不到！" << endl;
}
infile.close();
}

