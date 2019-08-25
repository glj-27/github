#include<iostream>
#include<cstdio>
using namespace std; 
int main()
{
	unsigned c=1;
	unsigned bitmask = 1<<31;	
	unsigned number=2;unsigned pow=10;
	while(c<31)		                                                                                                     //溢出判断
	{
		if( number&bitmask ) break;	                                                                                        	//查找最高位的1
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

