#include <iostream> 
#include <stdlib.h>
using namespace std; 
  
typedef int DataType; 
  
class SeqList 
{ 
public: 
  SeqList() 
    :_a(NULL) 
    , _size(0) 
    , _capacity(0) 
  {} 
  
  SeqList(const SeqList& s) 
    :_a(new DataType[s._size]) 
    , _size(s._size) 
    , _capacity(s._capacity) 
  { 
    memcpy(_a, s._a, sizeof(DataType)*s._size); 
  } 
  
  SeqList& operator=(const SeqList& s) 
  { 
    if (this != &s) 
    { 
      DataType* tmp = new DataType[s._size]; 
      delete[] _a; 
      _a = tmp; 
      memcpy(_a, s._a, sizeof(DataType)*s._size); 
      _size = s._size; 
      _capacity = s._capacity; 
    } 
      
    return *this; 
  }    
  ~SeqList() 
  { 
    if (_a) 
    { 
      delete[] _a; 
    } 
  } 
  
  void PushBack(DataType d) 
  { 
    CheckCapacity(); 
    _a[_size] = d; 
    _size++; 
  } 
  
  void PopBack() 
  { 
    if (_size > 0) 
    { 
      _size--; 
    } 
    else
    { 
      cout << "顺序表为空" << endl; 
    } 
  } 
  
  void PushFront(DataType d) 
  { 
    CheckCapacity(); 
  
    int i = (int)_size; 
    for (; i > 0; i--) 
    { 
      _a[i] = _a[i - 1]; 
    } 
    _a[0] = d; 
    ++_size; 
  } 
  
  void PopFront() 
  { 
    if (_size > 0) 
    { 
      int i = 0; 
      for (; i < (int)_size; i++) 
      { 
        _a[i] = _a[i + 1]; 
      } 
      _size--; 
    } 
    else
    { 
      cout << "顺序表为空" << endl; 
    } 
  } 
  
  void Print() 
  { 
    if (_size > 0) 
    { 
      int i = 0; 
      for (; i < (int)_size; i++) 
      { 
        cout << _a[i] << " "; 
      } 
      cout << endl; 
    } 
    else
    { 
      cout << "顺序表为空" << endl; 
    } 
  } 
  
  void Insert(size_t pos, DataType d) //在pos之前插入一个数据 
  { 
    CheckCapacity(); 
  
    if (_size > 0) 
    { 
      if (pos <= 0 || pos > _size)  
      { 
        cout << "pos位置非法" << endl; 
      } 
      else
      { 
        int i = 0; 
        for (i = (int)_size + 1; i > pos - 1; i--) 
        { 
          _a[i] = _a[i - 1]; 
        } 
        _a[pos - 1] = d; 
        _size++; 
      } 
    } 
    else
    { 
      PushFront(d); 
    } 
      
  } 
  
  void Erase(size_t pos) //删除pos位置的数据 
  { 
    if (_size > 0) 
    { 
      if (pos <= 0 || pos > _size) 
      { 
        cout << "pos位置非法" << endl; 
      } 
      else
      { 
        int i = pos - 1; 
        for (; i < (int)_size; i++) 
        { 
          _a[i] = _a[i + 1]; 
        } 
        _size--; 
      } 
    } 
    else
    { 
      cout << "顺序表为空,无法进行删除" << endl; 
    } 
  } 
  
  int Find(DataType d) 
  { 
    int i = 0; 
      
    for (; i < (int)_size; i++) 
    { 
      if (_a[i] == d) 
      { 
        return i + 1; 
      } 
    } 
    return 0; 
  } 
  
private: 
  void CheckCapacity() 
  { 
    if (_size == _capacity) 
    { 
      _capacity = _capacity * 2 + 3; 
      _a = (DataType*)realloc(_a, sizeof(DataType)*_capacity); 
    } 
  } 
  
private: 
  DataType* _a; 
  size_t _size; 
  size_t _capacity; 
};
void Test1() 
{ 
  SeqList s1; 
  s1.PushBack(1); 
  s1.PushBack(2); 
  s1.PushBack(3); 
  s1.PushBack(4); 
  s1.Print(); 
  SeqList s2(s1); 
  s2.Print(); 
  s2.PopBack(); 
  s2.PopBack(); 
  s2.PopBack(); 
  s2.PopBack(); 
  s2.PopBack(); 
  s2.Print(); 
  s2.PushFront(4); 
  s2.PushFront(3); 
  s2.PushFront(2); 
  s2.PushFront(1); 
  s2.Print(); 
  s2.PopFront(); 
  s2.Print(); 
  s2.PopFront(); 
  s2.PopFront(); 
  s2.PopFront(); 
  s2.PopFront(); 
  s2.PopFront(); 
  SeqList s3; 
  s3 = s1; 
  s3.Print(); 
}
int main() 
{ 
  Test1();
  return 0; 
}
