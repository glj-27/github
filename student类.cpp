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
	cout<<"请输入学生人数：";
	cin>>n; 
	student student1;
	for(m=1;m<=n;m++)
	{
		cout<<"请输入第"<<m<<"名学生的成绩：";
		cin>>s;
		student1.scoretotalcount(s);
	}
	cout<<"全班总分数为："<<student::sum()<<endl;
	cout<<"本班平均分为："<<student::average()<<endl; 
}
