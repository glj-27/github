#include<iostream>
#include<ctime> 
#include<cstdlib> 
using namespace std;   
bool mazeGenerator(char **&b,int v,int u,int m,int n) 
{  
	 for(int x=0;x<v;x++)  
	{for(int y=0;y<u;y++ ){b[x][y]='#';} }    
	 for(int x=1;x<v-1;x++)  
	{for(int y=1;y<u-1;y++)
	{if(rand()%3==1)b[x][y]='#';
	 else b[x][y]='.';}b[m][0]='X',b[m][1]='.';b[n][u-1]='.',b[n][u-2]='.';}   
	 for(int x=0;x<v;x++)
	{for(int y=0;y<u;y++)
	{cout<<b[x][y]<<" ";}
	 cout<<endl;}
	 cout<<"入口坐标为（"<<m+1<<","<<1<<")" <<endl;
     cout<<"出口坐标为（"<<n+1<<","<<u<<")" <<endl; 
}    

bool mazeTraverse(char **&b,int p,int v,int u) 
{
    int x,y,d=2,q=0;char l;  
    do{
		if(d==2) 
		{ 
		    if(b[p+1][q]=='#') 
		  { if(b[p][q+1]=='#') 
		  { if(b[p-1][q]!='#') 
		  { b[p-1][q]='X'; p=p-1; d=1; } 
		  else { b[p][q-1]='X'; q=q-1; d=4; } }
		  else { b[p][q+1]='X'; q=q+1; d=2; } } 
		  else { b[p+1][q]='X'; p=p+1; d=3; };    
		  do { cin.get(l); }
		  while(l!='\n'); 
		  system("cls"); 
		    for(x=0; x<v; x++)
		  { for(y=0; y<u; y++) 
		  { cout<<b[x][y]<<" "; } 
		    cout<<endl; } l=NULL; 
		}
		 
		if (d==1) 
		{ 
		    if(b[p][q+1]=='#') 
		  { if(b[p-1][q]=='#') 
		  { if(b[p][q-1]!='#') 
		  { b[p][q-1]='X';q=q-1;d=4;}
		  else { b[p+1][q]='X'; p=p+1; d=3; } }
		  else { b[p-1][q]='X'; p=p-1; d=1; } } 
		  else { b[p][q+1]='X'; q=q+1; d=2; }   
		  do { cin.get(l); } 
		  while(l!='\n'); 
		  system("cls"); 
		    for(x=0; x<v; x++)    
		  { for(y=0; y<u; y++) 
		  { cout<<b[x][y]<<" "; } 
		    cout<<endl; } l=NULL;
		}
		  
		if (d==4) 
		{ 
		    if(b[p-1][q]=='#') 
		  { if(b[p][q-1]=='#') 
		  { if(b[p+1][q]!='#') 
		  { b[p+1][q]='X'; p=p+1; d=3; } 
		  else { b[p][q+1]='X'; q=q+1; d=2; } }     
		  else { b[p][q-1]='X'; q=q-1; d=4; } } 
		  else { b[p-1][q]='X'; p=p-1; d=1; }    
		  do { cin.get(l); } 
		  while(l!='\n'); 
		  system("cls");  
		    for(x=0; x<v; x++)    
		  { for(y=0; y<u; y++) 
		  { cout<<b[x][y]<<" "; } 
		  cout<<endl; } l=NULL;
		}
		   
		if (d==3) 
		{ 
		    if(b[p][q-1]=='#')  
		  { if(b[p+1][q]=='#') 
		  { if(b[p][q+1]!='#') 
		  { b[p][q+1]='X'; q=q+1; d=2; } 
		  else { b[p-1][q]='X'; p=p-1; d=1; } }     
		  else { b[p+1][q]='X'; p=p+1; d=3; } } 
		  else { b[p][q-1]='X'; q=q-1; d=4; }    
		  do { cin.get(l); }    
		  while(l!='\n');system("cls");    
		    for(x=0;x<v;x++)  
	      { for(y=0;y<u;y++)  
		  { cout<<b[x][y]<<" "; }  
		    cout<<endl;  }l=NULL;   
	    }     
     }    
	while((q<u-1)&&(q>0));   
	if(q==0)    
	cout<<"没有路径通往出口！"<<endl;   
	else if(q==u-1)    
	cout<<"走出迷宫！"<<endl;   
} 

int main() 
{  
    srand (int (time (0)));
    int v,u;
	cout<<"请输入迷宫的长宽：";
	cin>>v>>u;     
	char **b;
	b=new char*[v];   
	for(int x=0;x<v;x++)
	{b[x]=new char[u];}    
	int m=rand()%(v-2)+1,n=rand()%(v-2)+1;
	int p=m;     
	mazeGenerator(b,v,u,m,n);   
	mazeTraverse(b,p,v,u);   
	return 0; 
}   

