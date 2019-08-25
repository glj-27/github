#include<iostream>
using namespace std;
int Rand(int,int);		    //生成指定范围的随机数

int main()
{ 
	int w,i,r,t = 0;
	char op,answer;
	int a,b,d;
	while(1)		
	{
		cout<<"现在开始？( Y 或 N )\n" ;
		cin>>answer;
		if (answer=='N'||answer=='n') break;
		while(1)
		{ 
			cout << "请输入难度( 1或2 ):";
			cin >> w;
			if ( w != 1 && w != 2 )
				cout << "输入难度错误，重新输入！" << endl;
			else break ;
		}
		while(1)
		{ 
			cout << "请输入运算类型( +,-,*,/ ):" ;  
			cin >> op;
			if ( op != '+' && op != '-' && op != '*' && op != '/' )
				cout << "输入运算符错误，重新输入！" << endl;
			else 
				break;
		}
		t=0;
		for( i=1; i<=10; i++ )
		{ 
			while(1)
			{ 
				if( w == 1 )
					{ a = Rand(0,10); b = Rand(0,10); }
				else
					if( w == 2 )
						{ a = Rand(10,100); b = Rand(10,100); }
				if ( op == '-' )
					if ( a<b ) continue ;	
				if ( op == '/' )
					if ( int( a/b ) != (a / b) ) continue;	
				break;
			}
			cout << a << op << b << '=';
			cin >> d;
			switch ( op )
			{ 
				case '+': r = a + b; break;
				case '-': r = a - b; break;
				case '*': r = a * b; break;
				case '/': r = a / b; break;	    
			}
			if ( r == d )
			{ 
				cout << "你算对了，加10分！" << endl;
				t = t + 10;
			}
			else 
				cout << "你算错了！" << endl;
		}
		cout << "你的成绩是：" << t << "分" << endl;
	}
}

int Rand(int m, int n)
{ 
	static int r;	
	do
	{ 
		r = ( 25173*r + 13849 ) % 65536 ;
	} while (r<m||r>=n);
	return r;
}


