


template<class Elem>
class AList:public List<Elem>
{
	private:
		Elem* listArray;
		int maxSize;
		int listSize;
		int fence;
	public:
		AList(int size=DefaultListSize)
		{
			listArray=new Elem[size];
			maxSize=size;
			listSize=fence=0; 
		}
	    ~AList(){delete[]listArray;}
	    bool setPos
	    {
	    	if((pos>=0)&&(pos<=listSize))
	    	fence=pos;
	    	return(pos>=0)&&(pos<+listSize);
	    }
	    bool getValue(Elem& it)const
	    {
	    	if(fence==listsize)return false;
	    	else
			{
				it=listArray[fence];
				return true;
	    	}
	    }
}
