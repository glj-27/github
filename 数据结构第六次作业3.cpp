#include<bits/stdc++.h>
using namespace std;
template <typename Key,typename Elem>
class Pair{
    public:
        Key key;
        Elem elem;
        bool flag;
        int collusion;
};
template <typename Key,typename Elem>
class Hashtable : public Pair<Key,Elem>{
    public :
        Pair<Key,Elem> *pair;
        int *pos;
        int *step;
        int len;
        Hashtable(int x){
            len = x;
            pair = new Pair<Key,Elem>[x];
            pos = new int[x];
            step = new int[x];
            for (int i =0 ;i<x;i++) {
				pair[i].flag=false;
				pair[i].collusion=0;
			};
            for (int i = 0;i<len;i++){
                step[i] = rand()%len;
            }
        }
        ~Hashtable(){
            delete pair;
            delete pos;
            delete step;
        }
        int h(int x){
            return x%len;
        }
        int h(char  *x){
            int tmp=0;
            for (int i = 0;i<strlen(x);i++){
                tmp = tmp*10+x[i];
                tmp = tmp%len;
            }
            return tmp;
        }
        int getPos(Key x){
            int tmp = h(x);
            int i = 1;
            while ( pair[tmp].flag ) { tmp=(tmp+step[i])%len;i=i+1; }
            return tmp;
        }
        int findPos(Key x){
            int tmp = h(x);
            int i = 0;
            while ( pair[tmp].key!=x && pair[tmp].flag ) {tmp = ( tmp+step[i] )%len;i=i+1;}
            if ( pair[tmp].flag==true && pair[tmp].key==x ) return tmp;
            return -1;
        }
        void addValue(Key key,Elem elem){
            int x = getPos(key);
            pair[ x ].key = key;
            pair[ x ].elem = elem;
            pair[ x ].flag = true;
            pair[ x ].collusion = (h(key)!=x);
        }
        void deleteValue(Key key){
            int tmp = findPos(key);
            pair[ tmp ].flag=false;
            pair[ tmp ].collusion=0;
        }
        bool hasValue(Key key){
            if ( findPos(key)!=-1 ) return true;
            return false;
        }
        int getCollution(){
            int sum=0;
            for (int i = 0 ;i<len;i++) sum+=pair[i].collusion;
            return sum;
        }
};
int main()
{
    int sum = 0;
    srand( (unsigned int)time(0) );
    Hashtable<int ,int > ht(1000);
    for (int i=0;i<500;i++){
        int k = rand()%10000;
        int e = rand()%100;
        if ( !ht.hasValue(k) ) {
            ht.addValue(k,e);
            printf("插入键值对< %d , %d > 在hash表中  槽: %d \n",k,e,ht.findPos(k) );
            sum ++ ;
        }
    }
    printf("共插入 %d 个元素 , 发生冲突 %d 次\n",sum,ht.getCollution() );
}
