#include<iostream>
#include<cstring> 
using namespace std;
class goods
{
	public:
		double price,number;string place,colour;
		goods(double a,double b,string c,string d)
		{
			price=a;number=b;place=c;colour=d;
		}
};
int main()
{
	
	double a,b;string c,d;int m,n=0,s=0;
	cin>>a>>b>>c>>d;
	goods shirt(a,b,c,d);
	cin>>a>>b>>c>>d;
	goods cap(a,b,c,d);
	cin>>a>>b>>c>>d;
	goods cupboard(a,b,c,d);
	cin>>m;
	switch(m)
	{
		case 1:
		    if(shirt.place=="南部"){s=s+shirt.price*shirt.number;}else {n=n+shirt.price*shirt.number;}
		    if(cap.place=="南部"){s=s+cap.price*cap.number;}else {n=n+cap.price*cap.number;}
		    if(cupboard.place=="南部"){s=s+cupboard.price*cupboard.number;}else {n=n+cupboard.price*cupboard.number;}
		    cout<<s<<endl<<n<<endl;
		    break;
		case 2:
			if(shirt.colour=="红色"){s=s+shirt.price*shirt.number;}else {n=n+shirt.price*shirt.number;}
		    if(cupboard.colour=="红色"){s=s+cupboard.price*cupboard.number;}else {n=n+cupboard.price*cupboard.number;}
		    cout<<s<<endl<<n<<endl;
		    break;
		case 3: if(cap.colour=="平顶"){n=cap.price*cap.number;}else {s=cap.price*cap.number;}
		  
		     cout<<n<<endl<<s<<endl;
		    break;
	}
}
