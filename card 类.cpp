#include<iostream>
using namespace std;
class card
{
	public:
		 
	    void buy(double c,int p)
	    { b=p*c;cout<<b;}
	    virtual void show_balance()const=0;
	private:
		int p;int b;int c;
		
};
int main()
{
	double oc,sc,cc;int n,p;int oa=100,sa=100,ca=100;
	cin>>oc>>sc>>cc>>p>>n;
	card OLDER;card STUDENT;card COMMON;
	while(n--)
	{
		oa=oa-p*oc;cout<<"OLDER  ";
		if(oa>0) {OLDER.buy(oc,p);cout<<endl;}
	   	else cout<<"Please recharge!"<<endl;
	   	sa=sa-p*sc;cout<<"STUDENT  ";
	    if(sa>0) {STUDENT.buy(sc,p);cout<<endl;}
	   	else cout<<"Please recharge!"<<endl;
		ca=ca-p*cc;cout<<"COMMON  ";
		if(ca>0) {COMMON.buy(cc,p);cout<<endl;}
		else cout<<"Please recharge!"<<endl;
	}
}
