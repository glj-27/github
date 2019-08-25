#include<iostream> 
using namespace std; 
int main()
{    
   char ch[100];     
   int n;      
   cin>>n;         
   int R,W,B,len;     
   cin.get();      
   for(int j=0;j<n;j++)
   {         
    cin.getline(ch,100,'\n');        
    len=strlen(ch);        
    R=0,W=0,B=0;        
    for(int i=0;i<len;i++)
     {         
      if(ch[i]=='R') R++;         
      else{              
           if(ch[i]=='W') W++;         
           else B++;         
          }                
     }      
    for(int i=0;i<R;i++)      
    cout<<"R";      
    for(int i=0;i<W;i++)      
    cout<<"W";       
    for(int i=0;i<B;i++)      
    cout<<"B";      
    cout<<endl;     
   }             
    return 0;       
}
