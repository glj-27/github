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
	data stu[ ] = {"С��",90,"С��",66,"С��",87,"С��",93,"С��",78,
             "С��",81,"СĪ",85,"С��",55,"С��",68,"С��",93};
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

