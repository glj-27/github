#include<stdio.h>
main()
{
	int x,y,z;
	int i,j;
	for(x=6;x<=200;x++,x++)
	for(y=1;y<x/2;y++)
	{
		for(i=2;i<y;i++)
			if(y%i==0)
				break;
			if(y==i)
			{
				z=x-y;
				for(j=2;j<z;j++)
					if(z%j==0)
						break;
					if(z==j)

	 printf("%d=%d+%d\n",x,y,z);

			}
	}

	printf("\n");


}
