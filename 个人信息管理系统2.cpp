#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <iostream>
using namespace std;
 
#define maxlen 15
struct persons
{
    int num;     
    char name[20]; 
    char e_addr[20];
    char tel_no[15];
    char sim_no;
    char arch;
}persons[maxlen];
 
typedef struct lnode{ 
    int num;
    char name[20];
    char e_addr[20];
    char tel_no[15];
    char sim_no;
    char arch;
    struct lnode *next;
}listnode,*linklist;
 
linklist head=NULL,r=NULL; 
listnode *s,*p0,*p1,*p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9;
int i;
char name1[10],ch;char tel_no1[15];char arch1;char sim_no1;char e_addr1[20];
char s1[20];
FILE *fp; 
 
void creat()
{ 
    int j;
    long k;
    fp=fopen("�����ļ�.txt","r t"); 
    if(fp!=NULL)
    {for(i=0;i<=maxlen;i++ )
    { j=fgetc(fp);
    if(j==EOF)
        return;
    k=i;
    fseek(fp,k*sizeof(struct persons),0); 
    fread(&persons[i],sizeof(struct persons),1,fp);
 
    s=(linklist)malloc(sizeof(listnode));
    s->num=persons[i].num;
    strcpy(s->name,persons[i].name);
    strcpy(s->e_addr,persons[i].e_addr);
    strcpy(s->tel_no,persons[i].tel_no);
    s->sim_no=persons[i].sim_no;
    s->arch=persons[i].arch;
    if(head==NULL) 
    {head=s;r=head;head->next=NULL;}
    else
    {r->next=s;
    r=s;r->next=NULL;
    }}fclose(fp);}
    else
    { fp=fopen("�����ļ�.txt","w"); 
    i=1;
    }
}
void ShowA()
{p1=head;
 
while(p1!=NULL)
{if(p1->arch=='A')
{
    cout<<endl;
    cout<<p1->name<<endl;
    cout<<p1->tel_no<<endl;
    cout<<p1->sim_no<<endl;}
p1=p1->next;continue;}
}
void ShowB()
{p1=head;
 
while(p1!=NULL)
{if(p1->arch=='B')
{
    cout<<endl;
    cout<<p1->name<<endl;
    cout<<p1->tel_no<<endl;
    cout<<p1->sim_no<<endl;}
p1=p1->next;continue;}
}
void ShowC()
{p1=head;
 
while(p1!=NULL)
{if(p1->arch=='C')
{
    cout<<endl;
    cout<<p1->name<<endl;
    cout<<p1->tel_no<<endl;
    cout<<p1->sim_no<<endl;}
p1=p1->next;continue;}
}
void Show()
{char ch1;
printf("                 Which arch do you want to show?\n");
cout<<"                  A:ͬѧͬ��"<<"B:����"<<"C:����"<<endl;
cout<<"��ѡ��:"<<endl;
cin>>ch1;
switch(ch1)
{case'A':ShowA();break;
case'B':ShowB();break;
case'C':ShowC();break;
default:cout<<"error"<<endl;
}
}
 
void Delete() 
{ printf("\n\n\t          ������Ҫɾ���û�������:");
 
cin>>name1;
p4=head;
if(strcmp(p4->name,name1)==0)
{ p4=p4->next; 
head=p4;
}
else
{ while(strcmp(p4->next->name,name1)!=0)
p4=p4->next;
p5=p4->next;
p4->next=p5->next;
free(p5);
}
} 
void Input() 
{ s=(linklist)malloc(sizeof(listnode));
 
printf("\n\n\t            ��������û�����Ϣ:");
 
cout<<"name:";
cin>>s->name;
cout<<"tel_no:";
cin>>s->tel_no;
cout<<"sim_no:";
cin>>s->sim_no;
cout<<"e_addr:";
cin>>s->e_addr;
cout<<"arch:";
cin>>s->arch;
 
if(head==NULL)printf("\n\n");
else
{p8=head;
while(p8!=NULL&&strcmp(s->name,p8->name)!=0&&strcmp(s->tel_no,p8->tel_no)!=0)
p8=p8->next;
if(p8!=NULL)
{printf("                 ����ӵ��û��Ѵ���!");
free(s);}}
 
if(head==NULL)
{head=s;head->next=NULL;}
else
{r->next=s;
r=s;r->next=NULL;}
}
 
void Alter() 
{
 
    printf("\n\n\t             ����������:");
 
    cin>>name1;
    p3=head;
    while(p3!=NULL&&strcmp(name1,p3->name)!=0)
        p3=p3->next;
    if(p3==NULL)
        printf("\n\n\t             ��ѡ����û�������!");
    else
    { printf("\n\n\t           ��������û�������Ϣ!"); 
 
    cout<<"name:";
    cin>>name1;
    cout<<"tel_no:";
    cin>>tel_no1;
    cout<<"e_addr:";
    cin>>e_addr1;
    cout<<"sim_no:";
    cin>>sim_no1;
    cout<<"arch:";
    cin>>arch1;
    while(p9!=NULL&&strcmp(name1,p9->name)!=0&&strcmp(tel_no1,p9->tel_no)!=0)
        p9=p9->next;
    if(p9==NULL)
    {strcpy(p3->name,name1);
    strcpy(p3->tel_no,tel_no1);
    strcpy(p3->e_addr,e_addr1);
    p3->sim_no=sim_no1;
    p3->arch=arch1;
    }
    else
        printf("                    ����ӵ��û��Ѵ���!");
 
    }
}
void Dial()
{int a;char b;
cout<<"1.�����û�:"<<endl;
cout<<"2.ʹ�õ�������:"<<endl;
cin>>a;
p0=head;
if(a==1)
{cout<<"                    �����벦���û�������:";
cin>>name1;
while(strcmp(name1,p0->name)!=0&&p0!=NULL)
p0=p0->next;
if(p0==NULL)
cout<<"                     ��ѡ����û�������!";
else 
/*for(c=0;c<15;c++)
{cout<<endl;
cout<<(*p0).tel_no[c];}*/
{cout<<endl;
cout<<p0->tel_no;
cout<<endl;}
}
else 
{cout<<"�����뵥������:";
cin>>b;
while(p0!=NULL&&b!=p0->sim_no)
p0=p0->next;
if(p0==NULL)
cout<<"                     ������ĵ������벻����!";
else
{cout<<endl;
cout<<p0->name<<endl;
cout<<p0->tel_no;
cout<<endl;}
}
}
 
void Save() 
{ int j;
fp=fopen("�����ļ�.txt","w");
for(p2=head,j=0;p2!=NULL;j++ ,p2=p2->next)
{ 
    strcpy(persons[j].name,p2->name);
    strcpy(persons[j].tel_no,p2->tel_no);
    persons[j].sim_no=p2->sim_no;
    strcpy(persons[j].e_addr,p2->e_addr);
    persons[j].arch=p2->arch;
    fwrite(&persons[j],sizeof(struct persons),1,fp);
}
}
 
int main()
{ creat();
do
{
    printf("          **********************************************************");
    printf("\n\n\n\n\t                         ��ӭ����ͨѶ¼��");
    printf("\n\n\t\t                  ��ѡ�����:");
    printf("\n\t\t1.                ��ʾͨѶ¼");
    printf("\n\t\t2.                ɾ��ͨѶ¼");
 
    printf("\n\t\t3.                ���ͨѶ¼");
    printf("\n\t\t4.                �༭ͨѶ¼");
    printf("\n\t\t5.                ���Ź���");
    printf("\n\t\t6.                ����ղŵĲ������˳�\n");
    printf("          **********************************************************");
    printf("\n\n\n");
    printf("\t        ѡ������Ҫ�Ĳ���:");
    cin>>ch;
    switch(ch)
    { case '1': Show(); 
    break;
    case '2': Delete();
        break;
    case '3': Input();
        break;
    case '4': Alter();
        break;
    case '5': Dial();
        break;
    case '6': Save();
        fclose(fp);
        exit(0);
        break;
    default:
        printf("\n\t*********************************\n");
        printf("\n\t The num should 1-6!!! \n");
        printf("\n\t**********************************");
        break;
    }
}while(1);
}
