#include<iostream>
using namespace std;
class jiaozg
{
	public:
		jiaozg(double jb){base=jb;}
		virtual void showgz()=0;
	protected:
		double base;
};
class teacher:public jiaozg
{
	public:
		teacher(double jb,int times,int zhic):jiaozg(jb){zc(zhic);t=times;}
		void showgz(){cout<<"教师工资："<<base+t*money<<endl;}
		void zc(int zhic)
		{
			if(zhic==1)money=50;
			else if(zhic==2)money=30;
				 else money=20;
		}
	protected:
		int money;
		int t;
};
class guanli:public jiaozg
{
	public:
		guanli(double jb,double zhiwu):jiaozg(jb){zw=zhiwu;}
		void showgz()
		{cout<<"管理人员工资："<<base+zw<<endl;}
	protected:
		double zw;
};
class shiys:public jiaozg
{
	public:
		shiys(double jb,double ributie,double time):jiaozg(jb){rbt=ributie;t=time;}
		void showgz()
		{cout<<"实验室工资:"<<base+t*rbt<<endl;}
	protected:
		double rbt;
		int t;
};
int main()
{
	jiaozg *pt;
	teacher peng(6000,18,1);
	guanli  li(5000,2000);
	shiys  mo(4000,100,28);
	pt=&peng;
	pt->showgz();
	pt=&li;
	pt->showgz();
	pt=&mo;
	pt->showgz();
}
		 
