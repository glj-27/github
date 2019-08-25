#include <assert.h>
#include <iostream>
using namespace std;
typedef int Datatype;
class SeqList
{
   public:
    SeqList()
        :_array(NULL)
        ,_size(0)
        ,_capacity(0)
    {}
    SeqList(const SeqList& s)
    {
        _array = (Datatype*)malloc(s._size*(sizeof(Datatype)));
        memcpy(_array, s._array, s._size*(sizeof(Datatype)));
        _size = _capacity = s._size;
    }
    SeqList& operator=(SeqList& s)
    {
        free(_array);
        Swap(s);
        return *this;
    }
    void Swap(SeqList& s)
    {
        _array = s._array;
        _size = s._size;
        _capacity = s._capacity;
    }
    ~SeqList()
    {
        if (_array)
        {
            free(_array);
            _array = NULL;
            _size = _capacity = 0;
        }
    }
    void Print()
    {
        for (size_t i = 0; i < _size; i++)
        {
            cout << _array[i] << " ";
        }
        cout << endl;
    }
    void CheckCapcacity()
    {
        if (_size == _capacity)
        {
            _capacity = 2 * _capacity + 3;
            _array = (Datatype*)realloc(_array, _capacity*sizeof(Datatype));
            assert(_array);
        }
    }
    void PushBack(Datatype x)
    {
        Insert(_size, x);
    }
    void PushFront(Datatype x)
    {
        Insert(0, x);
    }
    void PopBack()
    {
        Erase(_size);
    }
    void PopFront()
    {
        Erase(0);
    }
    Datatype& operator[](size_t pos)
    {
        assert(pos < _size);
        return _array[pos];
    }
    void Insert(size_t pos, Datatype x)
    {
        assert(pos <= _size);
        CheckCapcacity();
        int end = (int)_size - 1;
        if (pos == 0)
        {
            while (end >= 0)
            {
                _array[end + 1] = _array[end];
                end--;
            }
            _array[0] = x;
        }
        else
        {
            while (end >= (int)pos)
            {
                _array[end + 1] = _array[end];
                end--;
            }
            _array[pos] = x;
        }
        _size++;
    }
    void Erase(size_t pos)
    {
        assert(pos < _size);
        if (_size > 0)
        {
            if (pos == 0)
            {
                int end = 0;
                while (end < (int)_size - 1)
                {
                    _array[end] = _array[end + 1];
                    end++;
                }
                _size--;
            }
            else if (pos == _size)
            {
                _size--;
            }
            else
            {
                int end = pos;
                while (end < (int)_size - 1)
                {
                    _array[end] = _array[end + 1];
                    end++;
                }
                _size--;
            }
        }
        return; 
    }
   private:
    Datatype* _array;
    size_t  _size;
    size_t _capacity;
};
