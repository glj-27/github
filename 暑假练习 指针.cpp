#include<iostream>
using namespace std;
int main()
{
	int big=5;
	double small=1.5;
	cout<<"big value="<<big<<endl;
	cout<<"big address="<<&big<<endl;
	cout<<"small value="<<small<<endl;
	cout<<"small address="<<&small<<endl<<endl;
	
	int* bigbig;
	bigbig=&big;
	cout<<"big value="<<big<<endl;
	cout<<"*bigbig value="<<* bigbig<<endl;
	cout<<"big address="<<&big<<endl;
	cout<<"*bigbig address="<<bigbig<<endl;
	*bigbig=* bigbig+1;
	cout<<"Now *bigbig value="<<* bigbig<<endl;
	cout<<"Now big value="<<big<<endl<<endl;
	
	int* normal;
	*normal=5;
	cout<<"* normal value="<<* normal<<endl;
	cout<<"* normal address="<<normal<<endl<<endl; 
	//先定义指针，系统只会分配给指针地址，不会给指针所指向的值分配地址，容易出现无法查找的bug.
	
	int a=100;double b=50;
	b=(double)a;
	cout<<"b value="<<b<<endl;
	//强制转换数据类型。
	int* c;
	c=&a;
	cout<<"c value="<<* c<<endl;
	cout<<"*c address="<<c<<endl; 
	c=(int*)0xb5fd5c;
	//将上面big的地址强制赋值给c. 
	cout<<"NOW *c address="<<c<<endl;
	cout<<"NOW c value="<<* c<<endl<<endl;  
	/*虽然c为整型指正，但不能直接把整数赋值给c，虽然都是整数，但却不是相同的概念，但可以通过强制转
	换数据类型类给指针赋值；*/ 
	
	int* pt=new int;
	//在程序运行时才对数据对象分配内存。 
	*pt=1001;
	double* pd=new double;
	*pd= 10001.1;
	cout<<"int value="<<*pt<<";location="<<pt<<endl;
	cout<<"double value="<<*pd<<";location="<<pd<<endl;
	cout<<"location of pointer pt="<<&pt<<endl;
	cout<<"location of pointer pd="<<&pd<<endl;
	cout<<"size of pt="<<sizeof(pt)<<";size of *pt="<<sizeof(*pt)<<endl;
	cout<<"size of pd="<<sizeof(pd)<<";size of *pt="<<sizeof(*pt)<<endl<<endl;
	
	int* ab=new int;
	*ab=100;
	cout<<"int value="<<*ab<<";location of int="<<ab<<";location of pointer ab="<<&ab<<endl;
	delete ab;
	//为了防止内存泄漏，用delete释放指正所指向的内存，但不会删除指针本身。 
	cout<<"int value="<<*ab<<";location of int="<<ab<<";location of pointer ab="<<&ab<<endl<<'\n';
	
	double* sz=new double [3];
	sz[0]=0.27;
	sz[1]=2.7;
	sz[2]=27;
	cout<<"sz[0]="<<sz[0]<<'\t'<<"sz[1]="<<sz[1]<<'\t'<<"sz[2]"<<sz[2]<<endl;
	sz=sz+1;
	cout<<"sz[0]="<<sz[0]<<'\t'<<"sz[1]="<<sz[1]<<'\t'<<"sz[2]"<<sz[2]<<'\t'<<"sz[-1]"<<sz[-1]<<endl;
	sz=sz-1;
	cout<<"pointer notation of array sz[]:"<<endl;
	//new运算符直接返回未命名的内存地址。 
	cout<<&sz[0]<<'\t'<<&sz[1]<<'\t'<<&sz[2]<<'\n'<<'\n';
	delete [] sz;
	
	/*指针小结：给指针赋值时，应当将内存地址赋给指针，没有使用new时，应用&获得内存地址，使用new时，
	  new运算符会直接返回未命名的内存地址。*/ 
	
	 
}
