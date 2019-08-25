#include<stdio.h>  
#include<math.h>
int main()  
{  
    //cout<<"100以内的全部素数："<<endl;  
      printf("100以内的全部素数: \n");
      
    int i,j,k;  
    int a[101];  
    for(i=1;i<=100;i++)   a[i]=i;    
    a[1]=0;               //先挖掉a[1]  
  
    for(i=2;i<sqrt(100);i++){  
        for(j=i+1;j<=100;j++){  
            if(a[i]!=0&&a[j]!=0){  
                if(a[j]%a[i]==0){  
                    a[j]=0;           //把非素数挖掉,不是素数的都赋值为0  
                }  
            }  
        }  
    }  
    printf("\n"); 
    for(i=1,k=0;i<=100;i++){  
        if(a[i]!=0){              //选出值不为0的数  即素数   
            //cout<<" "<<a[i];  
            printf("%d ",a[i]);
            k++;  
        }  
  
        if(k==10){      //输出10个数后换行  
            printf("\n"); 
            k=0;  
        }  
    }  
    printf("\n"); 
  
    return 0;  
}
