#include <fstream>
#include <iostream>
using namespace std;
bool isPrime(int n)
{
     if(n==1) return false;
     if(n!=2&&n%2==0) return false;
     for(int i=3;i*i<=n;i=i+2)
     {
         if(n%i==0) return false;
     }
     return true;
}
bool isSym(int n)
{
     if(n<12&&n!=10) return true;
     if(n>100&&n<1000&&n/100==n%10) return true;
     if(n>10000&&n/1000==n%10*10+n/10%10) return true;
     return false;
}
int main(int argc,char * argv[])
{
    int n;
    while(cin>>n)
    {
        cout<<(n<100000&&isSym(n)&&isPrime(n)?"Yes\n":"No\n");
    }
  
    return 0;
}




/*#include<iostream>  
#include<string>  
#include<sstream>  
#include<vector>  
#include<cmath>  
using namespace std;  
class Int
{  
   public:  
    int dataInt;  
    int  check()  
    {  
        if(dataInt/10000.0<1 &&   
            this->isSym()==1 && this->isPrime() ==1) return 1;  
        return 0;  
    }  
    Int(int i)  
    {  
        dataInt = i;  
    }   
   private:  
    int isSym()  
    {  
        int n = dataInt;  
        if(n<12 && n!=10) return 1;  
        if(n>100 && n<1000 && n/100== n%10)  return 1;  
        if(n>1000 && n<10000 && n/1000 == n%10 && n%100-10 == (n/10)%10) return 1;  
        return 0;  
    }  
    int isPrime()  
    {  
        int n = dataInt;  
        if(n==1)return 0;  
        if(n!= 2 && n%2 == 0) return 0;  
        for(int i=3;i*i<n;i+=2)  
        {  
            if(n%i==0)return 0;  
        }  
        return 1;  
    }  
      
};  
  
int main()  
{  
    string s;
	while(getline(cin,s))  
{
    int n=1;   
    for(int i=0;i<s.size();i++)  
    {  
        if(s[i]==' ')n++;  
    }  
    stringstream ss(s);  
    int a[n];  
    for(int i=0;i<n;i++)  
    {  
        ss>>a[i];  
    }  
    for(int i=0;i<n;i++)  
    {  
        Int r(a[i]);  
        if(r.check())  
            cout<<"Yes\n";  
        else cout<<"No\n";   
    }
}
} */ 
