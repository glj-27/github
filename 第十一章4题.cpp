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
cout << "������ͨѶ¼�ļ���:";
cin >> filename ;		
infile.open( filename, ios::in|ios::binary );	
if ( !infile )
{  cerr << "�ļ����ܴ򿪣�" << endl;
abort();
}
infile.seekg( 0,ios::end );
long posend = infile.tellp();
infile.seekg( 0,ios::beg );
cout << "������ְ�����:" ;
cin >> num;
do 
{
    infile.read(( char * )&gzrec,sizeof( txrec ));
} while ( strcmp( gzrec.no,num ) != 0 && long(infile.tellp()) != posend );
if ( strcmp( gzrec.no,num ) == 0 )
{
cout << "��ְ���ļ�¼�ҵ��ˣ�" << endl;
cout << "���:" << gzrec.no << endl;		
cout << "����:"<< gzrec.name << endl;
cout << "�绰����:"<< gzrec.tel << endl;
cout << "��������:" << gzrec.postc << endl;
cout << "ͨ�ŵ�ַ:" << gzrec.addr << endl;
}
else
{ 
cout << "��ְ���ļ�¼�Ҳ�����" << endl;
}
infile.close();
}

