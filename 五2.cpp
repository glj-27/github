#include<iostream>
#include<cstdio>
using namespace std; 
int main()
{
	unsigned c=1;
	unsigned bitmask = 1<<31;	
	unsigned number=2;unsigned pow=10;
	while(c<31)		                                                                                                     //����ж�
	{
		if( number&bitmask ) break;	                                                                                        	//�������λ��1
		c++;
		bitmask>>=1;
	}
	if(pow<c)
		cout<< (number<<pow);
	else
	{ 
		cout<<"overflow!\n";
		return 0;
	}
}

