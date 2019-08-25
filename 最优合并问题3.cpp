#include <iostream>
#include <list> 
using namespace std;
 
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int k;//k组序列 
    cin >> k;//输入k 
    list<int> L, p;//定义连个列表 
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        L.push_back(a);
        p.push_back(a);
    }
    int max = 0, min = 0;
    for (int i = 0; i < k - 1; i++)
    {
        L.sort();//对列表L进行排序 
        int mark1 = 0;
        for (int i = 0; i < 2; i++)
        {
            mark1 += *L.begin();//返回开始元素并相加 
            L.pop_front();//删除第一个元素 
        }
        min += mark1-1;
        L.push_back(mark1);
 
        p.sort(cmp);
        int mark2 = 0;
        for (int i = 0; i < 2; i++)
        {
            mark2 += *p.begin();
            p.pop_front();
        }
        max += mark2-1;
        p.push_back(mark2);
    }
    cout << max << " " << min << endl;
}

