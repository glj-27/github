#include<iostream> 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std; 
int share_ver=0;
int main()
{
	pid_t pid;
    pid = fork();
    
	if (pid<0)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid>0)
	{
		while(1)
		{
			share_ver++;
			cout<<"parent:"<<share_ver<<endl;
			usleep(10000);
		}
	}
	else if(pid==0)
	{
		while(1)
		{
			share_ver--;
			cout<<"child:"<<share_ver<<endl;
			usleep(10000);
		}
	}
    return 0;
}
