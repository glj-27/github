#include <iostream>
#include<stdlib.h>
#include<fstream>
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
  int n,i;  
  txrec gzrec;
  char filename[20];
  fstream outfile;
  cout << "请输入通讯录文件名:" ;
  cin >> filename ;		
  outfile.open( filename, ios::out|ios::binary );	
  if ( !outfile )
{
    cerr << "文件不能打开！" << endl ;
    abort();
}
 cout << "请输入职工人数:" ;
 cin >> n;
 for( i=1; i<=n; i++ )
{
cout << "请输入第"<< i <<"个职工的编号:" ;
cin >> gzrec.no ;		
cout << "请输入第"<< i <<"个职工的姓名:" ;
cin >> gzrec.name ;
cout << "请输入第"<< i <<"个职工的电话号码:" ;
cin >> gzrec.tel ;
cout << "请输入第"<< i <<"个职工的邮政编码:" ;
cin >> gzrec.postc ;
cout << "请输入第"<< i <<"个职工的通信地址:" ;
cin >> gzrec.addr ;
outfile.write( ( char* )&gzrec,sizeof( txrec )) ;
}
  outfile.close() ;
}

