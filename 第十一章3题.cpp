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
  cout << "������ͨѶ¼�ļ���:" ;
  cin >> filename ;		
  outfile.open( filename, ios::out|ios::binary );	
  if ( !outfile )
{
    cerr << "�ļ����ܴ򿪣�" << endl ;
    abort();
}
 cout << "������ְ������:" ;
 cin >> n;
 for( i=1; i<=n; i++ )
{
cout << "�������"<< i <<"��ְ���ı��:" ;
cin >> gzrec.no ;		
cout << "�������"<< i <<"��ְ��������:" ;
cin >> gzrec.name ;
cout << "�������"<< i <<"��ְ���ĵ绰����:" ;
cin >> gzrec.tel ;
cout << "�������"<< i <<"��ְ������������:" ;
cin >> gzrec.postc ;
cout << "�������"<< i <<"��ְ����ͨ�ŵ�ַ:" ;
cin >> gzrec.addr ;
outfile.write( ( char* )&gzrec,sizeof( txrec )) ;
}
  outfile.close() ;
}

