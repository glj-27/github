#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
int Enterflag=0;           //�������������ȫ�ֱ���

class person
{
protected:
    int Num;                //ѧ��
    char name[40];          //����
    char sex[10];           //�Ա�
    int age;                //����
    char tel[20];           //�绰
    char email[60];         //����
    person *mynext;         //��һ��ѧ��ָ��
public:
    person();
    person(int pNum,char pname[],char psex[],int page,char ptel[],char pemail[]);
    person(int pNum,char pname[],char psex[],int page,char ptel[],char pemail[],person *next);
    int getNum();
    char *getname();
    char *getsex();
    int getage();
    void getage(int ag);
    char *gettel();
    char *getemail();
    person *getnext();
    void setnext(person *next);
    void output();
};

person::person()
{
    Num=0;
    strcpy(name,"");
    strcpy(sex,"");
    age=0;
    strcpy(tel,"");
    strcpy(email,"");
    mynext=NULL;
}
person::person(int pNum,,char pname[],char psex[],int page,char ptel[],char pemail[])
{
    Num=pNum;
    strcpy(name,pname);
    strcpy(sex,psex);
    age=page;
    strcpy(tel,ptel);
    strcpy(email,pemail);
    mynext=NULL;
}
person::person(int pNum,char pname[],char psex[],int page,char ptel[],char pemail[],person *next)
{
    Num=pNum;
    strcpy(name,pname);
    strcpy(sex,psex);
    age=page;
    strcpy(tel,ptel);
    strcpy(email,pemail);
    mynext=next;
}
int person::getNum()
{
    return Num;
}
char *person::getname()
{
    return name;
}
char *person::getsex()
{
    return sex;
}
int person::getage()
{
    return age;
}
void person::getage(int ag)
{
    age=ag;
}
char *person::gettel()
{
    return tel;
}
char *person::getemail()
{
    return email;
}
person *person::getnext()
{
    return mynext;
}
void person::setnext(person *next)
{
    mynext=next;
} 
void person::output()
{
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(12)<<"ѧ��"<<setw(20)<<"����"<<setw(9)<<"�Ա�"<<;
    cout<<setw(8)<<"����"<<setw(8)<<"�绰"<<setw(22)<<"����"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(14)<<firstname<<setw(4)<<Num<<setw(15)<<name<<setw(7)<<sex<<;
    cout<<setw(8)<<age<<setw(13)<<tel<<setw(26)<<email<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
}
class AddressBook
{
private:
    person *myfirst;            //ָ����ϵ����Ա��ָ��
public:
    AddressBook();
    AddressBook(int npNum,char npname[],char npsex[],int npage,char nptel[],char npemail[]);
    AddressBook();
    void displayRecord();       //��ʾ��¼
    bool queryRecord();         //��ѯ��¼
    bool queryRecord(int  fNum);
    //�вβ�ѯ������ѧ�Ų�ѯ
    void addRecord();           //��ӻ��½���¼
    void input(int number);     //���̶����³�Ա��Ϣ��
    void insert(int npNum,char npname[],char npsex[],int npage,char nptel[],char npemail[]);
    //��Ա��������³�Ա��Ϣ
    bool update();              //�޸ļ�¼
    bool removeRecord();        //ɾ����¼
    void saveRecords();         //�����¼
    void loadRecords();         //��ȡ��¼
    void clear();               //��յ�ǰͨѶ¼
};

AddressBook::AddressBook()
{
    myfirst=NULL;
}

AddressBook::AddressBook(int npNum,char npname[],char npsex[],int npage,char nptel[],char npemail[])
{
    myfirst=new person(npNum,npname,npsex,npage,nptel,npemail);
}
AddressBook::~AddressBook()
{
    person *next=myfirst,*temp;
    while(next!=NULL)
    {
        temp=next;
        next=next->getnext();
        delete temp;
    }
    myfirst=NULL;
}
//��ӻ��½���¼
void AddressBook::addRecord()
{
    int tempnum,number1,number2;
    char flag[5];
    person *per=myfirst;
    if(per==NULL)
    {
        cout<<"Ŀǰû��ѧ��ͨѶ¼��Ϣ��������������(Y)��ֱ�ӷ��س������˵�(N):";
        cin>>flag;
        while(1)
        {
            if(strcmp(flag,"Y\0")==0)
            {
               
                while(1)
                {
                    cout<<"������ѧ����β�ź�4λ:";
                    cin>>tempnum;
                    if(tempnum<1000||tempnum>9999)
                    {
                        cout<<"�����������������!";
                        continue;   
                    }
                    else
                    {
                        input(tempnum,tempfirstname);
                        cout<<"�Ƿ�������(Y/N):";
                        cin>>flag;
                        if((strcmp(flag,"N\0")==0))
                        return; 
                        addRecord();
                    }
                }
            }
            else if((strcmp(flag,"N\0")==0))
            {
                Enterflag=0;
                return;
            }
            else
            {
                cout<<"�������,������������(Y)��ֱ�ӷ��س������˵�(N):";
                cin>>flag;
                continue;
            }   
        }
    }
    else
    {
        cout<<"Ŀǰ���е�ѧ����Ϣ:"<<endl;
        displayRecord();
        cout<<"ѧ��ǰ׺�Ƿ������һ��ͬѧ��ͬ?(Y/N):";
        cin>>flag;
        while(1)
        {
            if(strcmp(flag,"N\0")==0)
            {
                
                while(strcmp(flag,"N\0")==0)
                {
                    cout<<"������ѧ����β�ź�4λ:";
                    cin>>tempnum;
                    if(tempnum<1000||tempnum>9999)
                    {
                        cout<<"�����������������!";
                        continue;   
                    }
                    input(tempnum,tempfirstname);
                    break;      
                }
                break;
            }
            else if(strcmp(flag,"Y\0")==0)
            {
                while(strcmp(flag,"Y\0")==0)
                {
                    cout<<"������ѧ����β�ź�4λ:";
                    cin>>tempnum;
                    if(tempnum<1000||tempnum>9999)
                    {
                        cout<<"�����������������!";
                        continue;   
                    }
                    break;      
                }
               
            }
            break;
        }
    }
}
//��ʾ��¼
void AddressBook::displayRecord()
{
    person *head=myfirst;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<setw(12)<<"ѧ��"<<setw(20)<<"����"<<setw(9)<<"�Ա�"<<setw(8)<<"����";
    cout<<setw(8)<<"�绰"<<setw(22)<<"����"<<setw(16)<<"�ʱ�"<<setw(12)<<"���֤��"<<endl;
    int i=0; 
    while(head!=NULL)
    {
        i++;
        cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<setw(14)<<head->getfirstname()<<setw(4)<<head->getNum()<<setw(15)<<head->getname()<<setw(7)<<head->getsex()<<setw(8)<<head->getage();
        cout<<setw(13)<<head->gettel()<<setw(26)<<head->getemail()<<setw(8)<<head->getpostcode()<<setw(20)<<head->getIDnumber()<<endl;
        head=head->getnext();
    }
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Ŀǰ�ܹ���"<<i<<"��ѧ������"<<endl;
}
//��յ�ǰͨѶ¼
void AddressBook::clear()
{
    person *head=myfirst;
    person *fhead=head;
    ofstream fout("addressbook.txt",ios::trunc);
    while(head!=NULL)
    {
        fhead=head->getnext();
        delete head;
        head=fhead;

    }
    myfirst=NULL;
    fout.close();
    cout<<"����������!\n";
}

//��ѯ��¼���вΣ�ѧ��
bool AddressBook::queryRecord(int stufirstid,int foNum)
{
    person *head=myfirst;
    person *fhead=head;
    while(head!=NULL)
    {

        if(head->getfirstname()==stufirstid&&head->getNum()==foNum)
        {   
            head->output();
            return true;
        }
        else
        {
            fhead=head;
            head=head->getnext();
        }
    }
    return false;
}
//��ѯ��¼���޲�
bool AddressBook::queryRecord()
{
    int stuid,stufirstid,k;
    char stustr[60];
    person *head=myfirst;
    person *fhead=head;
    while(1)
    {
        cout<<"��ȷ��ʹ�ú��ַ�������ѧ����Ϣ.\n1.���� 2.ѧ��:";
        cin>>k;
        if(k!=1&&k!=2)
        {   
            cout<<"�����������������!";
            continue;
        }
        switch(k)
        {
        case 1:
            {
                cout<<"������ѧ��������:";
                cin>>stustr;
                if(head==NULL)
                {
                    cout<<"��У����ѧ����Ϣ!"<<endl;
                    return false;
                }
                else
                {
                    while(head!=NULL)
                    {
                        if(strcmp(head->getname(),stustr)==0)
                        {
                            head->output();
                            if(head->getnext()==NULL)
                            return true;
                        }
                            fhead=head;
                            head=head->getnext();
                    }
                    cout<<"��У�޴�ѧ����Ϣ!"<<endl;
                    return false;
                }
            }
            break;
        case 2:
            {
                cout<<"������ѧ����ѧ��ǰ׺:";
                cin>>stufirstid;
                cout<<"������ѧ����ѧ��β�ź�4λ:";
                cin>>stuid;
                if(head==NULL)
                {
                    cout<<"��У����ѧ����Ϣ!"<<endl;
                    return false;
                }
                else
                {
                    while(head!=NULL)
                    {
                        if(head->getfirstname()==stufirstid&&head->getNum()==stuid)
                        {
                            head->output();
                            return true;
                        }
                        else
                        {
                            fhead=head;
                            head=head->getnext();
                        }
                    }
                    cout<<"��У�޴�ѧ����Ϣ!"<<endl;
                    return false;
                }
            }
            break;
        }
    }
}
//���̶����³�Ա��Ϣ��
void AddressBook::input(int number,int firstname)
{
    int page;
    char pname[40],psex[10],ptel[20],pemail[60],ppostcode[10],pIDnumber[30];
    cout<<"������ѧ��Ϊ"<<firstname<<number<<"����Ϣ:"<<endl;
    cout<<"����:";
    cin>>pname;
    cout<<"�Ա�:";
    cin>>psex;
    cout<<"����:";
    cin>>page;
    cout<<"�绰����:";
    cin>>ptel;
    cout<<"����:";
    cin>>pemail;
    cout<<"�ʱ�:";
    cin>>ppostcode;
    cout<<"���֤��:";
    cin>>pIDnumber;
    insert(number,firstname,pname,psex,page,ptel,pemail,ppostcode,pIDnumber);
}
//��Ա��������³�Ա��Ϣ
void AddressBook::insert(int npNum,int npfirstname,char npname[],char npsex[],int npage,char nptel[],char npemail[],char nppostcode[],char npIDnumber[])
{
    person *pers=myfirst;
    if(pers==NULL)
        myfirst=new person(npNum,npfirstname,npname,npsex,npage,nptel,npemail,nppostcode,npIDnumber);
    else
    {
        while(pers->getnext()!=NULL)
            pers=pers->getnext();
        pers->setnext(new person(npNum,npfirstname,npname,npsex,npage,nptel,npemail,nppostcode,npIDnumber,pers->getnext()));
    }
}
//�޸ļ�¼
bool AddressBook::update()
{
    int number,number2;
    char flag[5];
    person *head=myfirst;
    person *fhead=head;
    cout<<"������Ҫ�޸ĵ�ѧ��ѧ��ǰ׺:";
    cin>>number;
    cout<<"������Ҫ�޸ĵ�ѧ��ѧ��β�ź�4λ:";
    cin>>number2;
    if(head==NULL)
    {
        cout<<"��УĿǰû��ѧ��!"<<endl;
        return false;
    }
    else 
        while(head!=NULL)
        {
            if(head->getfirstname()==number&&head->getNum()==number2)
            {
                cout<<"��Ҫ�޸ĵ�ѧ����Ϣ����:"<<endl;
                head->output();
                while(1)
                {
                    int i;
                    float newnumber;
                    char newtxt[60];
                    cout<<"������Ҫ�޸ĵ���Ϣ���.����ʾ����:";
                    cout<<"1.���� 2.�Ա� 3.���� 4.�绰 5.���� 6.�ʱ� 7.���֤��\n";
                    cout<<".";
                    cin>>i;
                    switch(i)
                    {
                    case 1:
                        {
                            cout<<"������ѧ������:\n";
                            cout<<".";
                            cin>>newtxt;
                            strcpy(head->getname(),newtxt);
                            queryRecord(number,number2);
                        }
                        break;
                    case 2:
                        {
                            cout<<"������ѧ���Ա�:\n";
                            cout<<".";
                            cin>>newtxt;
                            strcpy(head->getsex(),newtxt);
                            queryRecord(number,number2);
                        }
                        break;
                    case 3:
                        {
                            cout<<"������ѧ������:\n";
                            cout<<".";
                            cin>>newnumber;
                            head->getage(newnumber);
                            queryRecord(number,number2);
                        }
                        break;
                    case 4:
                        {
                            cout<<"������ѧ���µĵ绰:\n";
                            cout<<".";
                            cin>>newtxt;
                            strcpy(head->gettel(),newtxt);
                            queryRecord(number,number2);
                        }
                        break;
                    case 5:
                        {
                            cout<<"������ѧ���µ�����:\n";
                            cout<<".";
                            cin>>newtxt;
                            strcpy(head->getemail(),newtxt);
                            queryRecord(number,number2);
                        }
                        break;
                    case 6:
                        {
                            cout<<"������ѧ���µ��ʱ�:\n";
                            cout<<".";
                            cin>>newtxt;
                            strcpy(head->getpostcode(),newtxt);
                            queryRecord(number,number2);
                        }
                        break;
                    case 7:
                        {
                            cout<<"������ѧ����ȷ�����֤��:\n";
                            cout<<".";
                            cin>>newtxt;
                            strcpy(head->getIDnumber(),newtxt);
                            queryRecord(number,number2);
                        }
                        break;
                    default:
                        return false;
                    }
                    cout<<"�Ƿ�����޸�(Y/N):";
                    cin>>flag;
                    if(strcmp(flag,"Y\0")==0)
                        continue;
                    else
                    {
                        return true;
                    }

                }

            }
            else
            {
                head=head->getnext();
                fhead=head;
            }
        }
        cout<<"��Уû������һ��ѧ��!"<<endl;
        return false;
}
//ɾ����¼
bool AddressBook::removeRecord()
{
    int stuid,stufirstid;
    person *head=myfirst;
    person *fhead=head;
    cout<<"������ѧ����ѧ��ǰ׺:";
    cin>>stufirstid;
    cout<<"������ѧ����ѧ��β�ź�4λ:";
    cin>>stuid;
    if(head==NULL)
    {
        cout<<"����!��ѧ������ɾ��!"<<endl;
        return false;
    }
    else if(head->getfirstname()==stufirstid&&head->getNum()==stuid)
    {
        myfirst=myfirst->getnext();
        cout<<"ѧ��Ϊ"<<stufirstid<<stuid<<"��ѧ����ɾ���ɹ�!"<<endl;
        delete head;
        return true;
    }
    else
    {
        head=head->getnext();
        while(head!=NULL)
        {
            if(head->getfirstname()==stufirstid&&head->getNum()==stuid)
            {
                fhead->setnext(head->getnext());
                cout<<"ѧ��Ϊ"<<stufirstid<<stuid<<"��ѧ���ѱ�ɾ��\n";
                delete head;
                return true;
            }
            fhead=head;
            head=head->getnext();
        }
        cout<<"Ҫɾ����ѧ�������ڣ��޷�ɾ��!"<<endl;
        return false;
    }
}
//�����¼
void AddressBook::saveRecords()
{
    ofstream fout("addressbook.txt");
    person *pe=myfirst;
    while(pe)
    {
        fout<<pe->getfirstname()<<"\t"<<pe->getNum()<<"\t"<<pe->getname()<<"\t"<<pe->getsex()<<"\t"<<pe->getage()<<"\t"<<pe->gettel()<<"\t"<<pe->getemail()<<"\t"<<pe->getpostcode()<<"\t"<<pe->getIDnumber()<<"\n";
        pe=pe->getnext();
    }
    fout.close();
    cout<<"���ݱ������!\n";  
}
//��ȡ��¼
void AddressBook::loadRecords()
{
    int Num,age,firstname;                //ѧ��
    char name[40],sex[10],tel[20],email[60],postcode[10],IDnumber[30];
    ifstream fin("addressbook.txt");
    int i=0;
    while(fin>>firstname>>Num>>name>>sex>>age>>tel>>email>>postcode>>IDnumber)
    {
        insert(Num,firstname,name,sex,age,tel,email,postcode,IDnumber);
        i++;
    }
    if(i==0)
    {
        cout<<"����ʧ��,Ŀǰ�ĵ���û������!"<<endl;
        fin.close();
    }
    else
    {
        fin.close();
        cout<<"�ѳɹ�����"<<i<<"������"<<endl;
        displayRecord();
    }

}


int main()
{
    AddressBook target;
    int i;
    //system("color e");
    while(1)
    {
        cout<<"    =======================��ӭʹ��ѧ��ͨѶ¼����ϵͳ======================"<<endl;
        cout<<"    ������һ������ѡ�������,��.��ʾ���룬�Իس����Ž�����            ����     "<<endl;
        cout<<"    1.��ӻ��½�ѧ����ͨѶ��ϵ��ʽ��Ϣ��  addRecord()           ��  ���޲���!"<<endl;
        cout<<"    2.��ʾѧ����ͨѶ��ϵ��ʽ�ļ�¼��      displayRecord()        ��  �޲���!"<<endl;
        cout<<"    3.�޸�һ��ѧ����ͨѶ��ϵ��ʽ��Ϣ��    update()               ��  �޲���!"<<endl;
        cout<<"    4.ɾ��һ��ѧ����ͨѶ��ϵ��ʽ��Ϣ��    removeRecord()          �� �޲���!"<<endl;
        cout<<"    5.��ѯָ��ѧ����ͨѶ��ϵ��ʽ��Ϣ��    queryRecord()          ��  �޲���!"<<endl;
        cout<<"    6.�����ļ���ѧ��ͨѶ��ϵ��ʽ��Ϣ��    loadRecords()           �� �޲���!"<<endl;
        cout<<"    7.�����¼��                       saveRecords()           �� �޲���!"<<endl;
        cout<<"    8.������м�¼��                    clear()                 �� �޲���!"<<endl;
        cout<<"    9.�˳�ѧ��ͨѶ¼����ϵͳ!            Exit()                   ���޲���!"<<endl;
        cout<<"    ======================================================================="<<endl;
        cout<<".";
        cin>>i;
        if(i<1||i>9)
        {
            cout<<"�����������������!"<<endl;
            continue;
        }
        if(!(i==9||i==6||i==1)&&Enterflag==0)         // �����һ�����뺯�����ǽ������򿪻��˳�������������
        {
            cout<<"���Ƚ������ߴ��ļ�����һ����ϵ��ʽ��Ϣ!"<<endl;
            continue;
        }
        Enterflag=1;
        switch(i)
        {
        case 1: target.addRecord();
            break;
        case 2: target.displayRecord();
            break;
        case 3: target.update();
            break;
        case 4: target.removeRecord();
            break;
        case 5: target.queryRecord();
            break;
        case 6: target.loadRecords();
            break;
        case 7: target.saveRecords();
            break;
        case 8: target.clear();
            break;
        //case 9:
           // exit(1);
        }       
    }
}
