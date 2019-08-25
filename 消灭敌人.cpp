#include<iostream>  
#include<string>  
#include<sstream>  
#include<vector>  
#include<cmath>  
 using namespace std;  
   
 class Enemy
 {  
   public:  
    int x,y;  
    int l;  
      
    static int number;  
      
    Enemy(int a,int b,int c)  
    {  
        x=a;y=b;l=c;  
        number+=2;  
    }  
    ~Enemy()  
    {  
        number--;  
    }  
      
      
 };  
   
 int Enemy::number = 0;  
  
 int main()  
 {  
    string str;  
    vector<Enemy> e;  
    while(getline(cin,str))  
    {  
        stringstream ss(str);  
        string s;  
        int x,y,l;  
        ss>>s>>x>>y>>l;  
      
        if(s==string("New"))  
        {  
            e.push_back(Enemy(x,y,l));  
        }  
        else if(s==string("Bom"))  
        {  
            int killnum = 0;  
            for(int i=0;i<e.size();i++)  
            {  
                if(sqrt( (e[i].x-x)*(e[i].x-x)+  
                    (e[i].y-y)*(e[i].y-y))<=10)  
                {  
                    e[i].l-=l;  
                    if(e[i].l<=0)   
                    {  
                        e.erase(e.begin()+i);   
                        killnum++;  
                    }  
                }   
            }  
            cout<<killnum<<" "<<Enemy::number+3<<endl;   
        }  
        else break;  
    }  
} 
