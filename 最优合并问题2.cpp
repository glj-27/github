#include<stdio.h>
#include<string.h>
 
int *sort(int *arr,int start,int end)
{
	int i,j,temp;
	for(i=start;i<end;i++)
		for(j=i+1;j<=end;j++)
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
	return arr;
}
 
int main()
{
 
	int i,j,k,count=0;
	int list[10]={0};
	char s[50];
 
	scanf("%d",&k);
	getchar();
 
	//���ÿ�����еĳ���
	for(i=0;i<k;i++)
	{
		gets(s);
		for(j=0;j<strlen(s);j++)
			if(s[j]==' ')
				continue;
			else
				list[i]++;
	}
	
	sort(list,0,k-1);//����
	//ÿ�κϲ����ٽ������򣬺ϲ������������С�������ٺϲ���
	for(i=0;i<k-1;i++)//k��Ԫ����Ҫk-1�κϲ�
	{
		list[i+1]=list[i]+list[i+1];
		count+=list[i+1];
		sort(list,i+1,k-1);
	}
	printf("%d\n",count);
	return 0;
}
