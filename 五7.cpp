#include <iostream>
using namespace std;
struct data
{
  char name[12];
  double score;
};
double searchMax(data *a, int n );

int main()
{
	data stu[ ] = {"小明",90,"小红",66,"小刘",87,"小辰",93,"小张",78,
             "小李",81,"小莫",85,"小吴",55,"小王",68,"小峰",93};
	double max;
	int n=sizeof(stu) / sizeof(data);
	max=searchMax(stu, n);
	for( int i=0; i<n; i++ )
		if( stu[i].score == max ) 
			cout <<stu[i].name <<'\t'<< stu[i].score<<endl;
}

double searchMax(data *a, int n )
{
	int i;
	double max=a[0].score;
	for( i=1; i<n; i++ )
	  if( a[i].score > max ) max = a[i].score;
	return max;
}

