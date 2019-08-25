#include <iostream>
using namespace std;

template <class T> class seqlist
{
private:
    T* aList;  //�洢˳����ʵ��
    int maxSize;  //˳���ʵ������󳤶�
    int curLen;  //˳���ĵ�ǰ����
    int position;//��ǰ����λ��
public:
    seqlist(const int size);
    ~seqlist();
    void clear();       //�ÿ����Ա�
    int length();
    bool isEmpty();     //���Ա�Ϊ��ʱ������true
    bool append(const T value);     //�ڱ�β���һ��Ԫ��value,��ĳ�����1
    bool insert(const int p, const T value);    //��λ��p�ϲ���һ��Ԫ��value����ĳ�����1
    bool delet(const int p);        //ɾ��λ��p�ϵ�Ԫ�أ���ĳ��ȼ�1
    bool getPos(int& p, const T value);     //����ֵΪvalue��Ԫ�ز�������λ��
    bool getValue(const int p, T& value);   //��λ��pԪ��ֵ���ص�����value
    bool setValue(const int p, const T value);      //��value�޸�λ��p��Ԫ��ֵ
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
    if (curLen>=maxSize)  //���˳����Ƿ����
    {
        cout << "The list is overflow" << endl;
        return false;
    }
    aList[curLen]=value;
    curLen++;
    return true;
}

//��Ԫ������ΪT��aList�Ǵ洢˳�������飬maxSize������󳤶ȣ�
//pΪ��Ԫ��value�Ĳ���λ�ã�����ɹ��򷵻�true�����򷵻�false
template <class T> bool seqlist<T>::insert(const int p, const T value)
{
    if (curLen>=maxSize)  //���˳����Ƿ����
    {
        cout << "The list is overflow" << endl;
        return false;
    }
    if (p<0 || p>curLen)  //������λ���Ƿ�Ϸ�
    {
        cout << "Insertion point is illegal" << endl;
        return false;
    }
    for(int i=curLen; i>p; i--)
        aList[i]=aList[i-1];   //�ӱ�βcurLen-1�������ƶ�ֱ��p
    aList[p]=value;  //λ��p��������Ԫ��
    curLen++;    //���ʵ�ʳ�����1
    return true;
}

//��Ԫ�ص�����ΪT��aList�Ǵ洢˳�������飻pΪ����ɾ��Ԫ�ص�λ��
//ɾ���ɹ��򷵻�true, ���򷵻�false
template <class T> bool seqlist<T>::delet(const int p)  
{
    if (curLen<=0)  //���˳����Ƿ�Ϊ��
    {
        cout << "No element to delete" << endl;
        return false;
    }
    if (p<0 || p>curLen-1)  //���ɾ��λ���Ƿ�Ϸ�
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
    if (curLen<=0)  //���˳����Ƿ�Ϊ��
    {
        cout << "No element" << endl;
        return false;
    }
    if (p<0 || p>curLen-1)  //���ɾ��λ���Ƿ�Ϸ�
    {
        cout << "getvalue is illegal" << endl;
        return false;
    }
    value = aList[p];
    return true;
}

template <class T> bool seqlist<T>::setValue(const int p, const T value)
{
    if (curLen<=0)  //���˳����Ƿ�Ϊ��
    {
        cout << "No element" << endl;
        return false;
    }
    if (p<0 || p>curLen-1)  //���ɾ��λ���Ƿ�Ϸ�
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
        del=(del+m-1)%i;   //Ҫɾ����Ԫ�ص�����
        if (del==0) del = i;
        palist.getValue(del-1, w);   //�����del��Ԫ�ص�ֵ
        printf("Out element %d \n", w);   //Ԫ�س���
        palist.delet(del-1);   //ɾ�����е�Ԫ��
    }
}
int main() {
    seqlist<int> jos_alist(100);
    int n, s, m;
    printf("\n please input the values(<100) of n = ");  //������Ϸ������
    scanf("%d", &n);
    printf("please input the values of s = ");   //��ʼ����
    scanf("%d", &s);
    printf("please input the values of m = ");   ///���ʼ���
    scanf("%d", &m);
    for (int i=0; i<n; i++) {
        jos_alist.append(i+1);
    }
    josephus_seq(jos_alist, s, m);
    return 0;
}

