#include<iostream>
using namespace std;
class student
{
	public:
		void scoretotalcount(double s)
		{
			score=s;
			total=total+score;
			count++;
		}
		static double sum()
		{
			return total;
		}
		static double average()
		{
			return total/count;
		}
	private:
		double score;static double total;static int count;
} ;
double student::total=0;int student::count=0;
int main()
{
	int n,m;double s;
	cout<<"������ѧ��������";
	cin>>n; 
	student student1;
	for(m=1;m<=n;m++)
	{
		cout<<"�������"<<m<<"��ѧ���ĳɼ���";
		cin>>s;
		student1.scoretotalcount(s);
	}
	cout<<"ȫ���ܷ���Ϊ��"<<student::sum()<<endl;
	cout<<"����ƽ����Ϊ��"<<student::average()<<endl; 
}
