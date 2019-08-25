#include <iostream>
using namespace std;

template <class T> class seqlist
{
private:
    T* aList;  //存储顺序表的实例
    int maxSize;  //顺序表实例的最大长度
    int curLen;  //顺序表的当前长度
    int position;//当前处理位置
public:
    seqlist(const int size);
    ~seqlist();
    void clear();       //置空线性表
    int length();
    bool isEmpty();     //线性表为空时，返回true
    bool append(const T value);     //在表尾添加一个元素value,表的长度增1
    bool insert(const int p, const T value);    //在位置p上插入一个元素value，表的长度增1
    bool delet(const int p);        //删除位置p上的元素，表的长度减1
    bool getPos(int& p, const T value);     //查找值为value的元素并返回其位置
    bool getValue(const int p, T& value);   //把位置p元素值返回到变量value
    bool setValue(const int p, const T value);      //用value修改位置p的元素值
};

template <class T> seqlist<T>::seqlist(const int size)
{
    maxSize=size;
    aList = new T[maxSize];
    curLen=position=0;
}


template <class T> seqlist<T>::~seqlist()
{
    delete []aList;
}

template <class T> void seqlist<T>::clear()
{
    delete [] aList;
    curLen=position=0;
    aList=new T[maxSize];
}

template <class T> int seqlist<T>::length()
{
    return curLen;
}

template <class T> bool seqlist<T>::isEmpty()
{
    if (curLen==0) {
        return true;
    }
    else {
        return false;
    }
}

template <class T> bool seqlist<T>::append(const T value)
{
    if (curLen>=maxSize)  //检查顺序表是否溢出
    {
        cout << "The list is overflow" << endl;
        return false;
    }
    aList[curLen]=value;
    curLen++;
    return true;
}

//设元素类型为T，aList是存储顺序表的数组，maxSize是其最大长度；
//p为新元素value的插入位置，插入成功则返回true，否则返回false
template <class T> bool seqlist<T>::insert(const int p, const T value)
{
    if (curLen>=maxSize)  //检查顺序表是否溢出
    {
        cout << "The list is overflow" << endl;
        return false;
    }
    if (p<0 || p>curLen)  //检查插入位置是否合法
    {
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    for(int i=curLen; i>p; i--)
        aList[i]=aList[i-1];   //从表尾curLen-1起往右移动直到p
    aList[p]=value;  //位置p处插入新元素
    curLen++;    //表的实际长度增1
    return true;
}

//设元素的类型为T；aList是存储顺序表的数组；p为即将删除元素的位置
//删除成功则返回true, 否则返回false
template <class T> bool seqlist<T>::delet(const int p)  
{
    if (curLen<=0)  //检查顺序表是否为空
    {
        cout << "No element to delete" << endl;
        return false;
    }
    if (p<0 || p>curLen-1)  //检查删除位置是否合法
    {
        cout << "deletion is illegal" << endl;
        return false;
    }
    for(int i=p; i<curLen; i++)
        aList[i]=aList[i+1];
    curLen--;
    return true;
}

template <class T> bool seqlist<T>::getPos(int& p, const T value)
{
    for(int i=0; i<curLen; i++) 
        if (aList[i]==value) {
            p=i;
            return true;
        }           
        cout << "can not find element: " << value << endl;
        return false;
}

template <class T> bool seqlist<T>::getValue(const int p, T& value)
{
    if (curLen<=0)  //检查顺序表是否为空
    {
        cout << "No element" << endl;
        return false;
    }
    if (p<0 || p>curLen-1)  //检查删除位置是否合法
    {
        cout << "getvalue is illegal" << endl;
        return false;
    }
    value = aList[p];
    return true;
}

template <class T> bool seqlist<T>::setValue(const int p, const T value)
{
    if (curLen<=0)  //检查顺序表是否为空
    {
        cout << "No element" << endl;
        return false;
    }
    if (p<0 || p>curLen-1)  //检查删除位置是否合法
    {
        cout << "setvalue is illegal" << endl;
        return false;
    }
    aList[p] = value;
    return true;
}

void josephus_seq(seqlist<int>& palist, int s, int m)
{
    int del = s;  
    int w=0;
    for(int i=palist.length(); i>0; i--) {
        del=(del+m-1)%i;   //要删除的元素的索引
        if (del==0) del = i;
        palist.getValue(del-1, w);   //求出第del个元素的值
        printf("Out element %d \n", w);   //元素出列
        palist.delet(del-1);   //删除出列的元素
    }
}
int main() {
    seqlist<int> jos_alist(100);
    int n, s, m;
    printf("\n please input the values(<100) of n = ");  //参与游戏的人数
    scanf("%d", &n);
    printf("please input the values of s = ");   //开始的人
    scanf("%d", &s);
    printf("please input the values of m = ");   ///单词计数
    scanf("%d", &m);
    for (int i=0; i<n; i++) {
        jos_alist.append(i+1);
    }
    josephus_seq(jos_alist, s, m);
    return 0;
}

