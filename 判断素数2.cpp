#include<stdio.h>  
#include<math.h>
int main()  
{  
    //cout<<"100���ڵ�ȫ��������"<<endl;  
      printf("100���ڵ�ȫ������: \n");
      
    int i,j,k;  
    int a[101];  
    for(i=1;i<=100;i++)   a[i]=i;    
    a[1]=0;               //���ڵ�a[1]  
  
    for(i=2;i<sqrt(100);i++){  
        for(j=i+1;j<=100;j++){  
            if(a[i]!=0&&a[j]!=0){  
                if(a[j]%a[i]==0){  
                    a[j]=0;           //�ѷ������ڵ�,���������Ķ���ֵΪ0  
                }  
            }  
        }  
    }  
    printf("\n"); 
    for(i=1,k=0;i<=100;i++){  
        if(a[i]!=0){              //ѡ��ֵ��Ϊ0����  ������   
            //cout<<" "<<a[i];  
            printf("%d ",a[i]);
            k++;  
        }  
  
        if(k==10){      //���10��������  
            printf("\n"); 
            k=0;  
        }  
    }  
    printf("\n"); 
  
    return 0;  
}
