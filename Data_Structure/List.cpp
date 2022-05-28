#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define ElementType int
const int UnionSize = sizeof(ElementType);
const int increase = 100;
 
template<class T>
class equal
{
public:
	virtual void* find(T f)
	{
		return NULL;
	}
};
 
template<class T>
class CStash:public equal<T>
{
private:
	char *storage;
	int quantity;
	int next;
	int size;
	void inflate()
	{
		int newQuantity = quantity + increase;
		int newBytes = (quantity + increase) * size;
         
		int oldBytes = next * size;
		char *e = new char[newBytes];
		for(int i = 0; i < oldBytes; i++)
			e[i] = storage[i];
		delete storage;
		storage = e;
		quantity = newQuantity;
	}
public:
	CStash()
	{
		storage   = 0;
		quantity  = 0;
		next	  = 0;
		size      = UnionSize;
	}
    
	void push_back(T *element)
	{
		if(next >= quantity)
			inflate();
		int startBytes = next * size;
		unsigned char *e =(unsigned char *) element;
		for(int i = 0; i < size; i++)
			storage[startBytes + i] = e[i];
		next++;
	}

	void * fetch(int index)
	{
		if(index > next || index < 0)
			return 0;
		else
			return &storage[index * size];
	}

	virtual void* find(T f)                    //²éÕÒÔªËØ
	{
		unsigned char * e = (unsigned char *) &f;
		for(int i = 0; i < next * size; i += size)
		{
			bool ok = true;
			for(int j = 0; j < sizeof(f); j++)
			{
				if(storage[i + j] != e[j])
				{
					ok = false;
					break;
				}
			}
			if(ok)
			{
				return &storage[i];
			}
		}
		return NULL;
	}
	void cleanup()
	{
		next = 0;
		quantity = 0;
		delete[] storage;
		storage = 0;
	}
};
 
int main()
{
	ElementType t = 120;
	ElementType *p = &t;
	CStash<ElementType> *cs = new CStash<ElementType>();
	
	cs->push_back(p);
	t = 20;
	cs->push_back(p);
	t = 33;
	cs->push_back(p);
	t =12;
	cs->push_back(p);
	ElementType *tt = (ElementType *)cs->fetch(1);
	printf("%d\n", *tt);
	tt = (ElementType *)cs->find(33);
	printf("%d\n", *tt);
	tt = (ElementType *)cs->find(11);
	if(tt == NULL)
		puts("NULL");
	cs->cleanup();
    system("pause");
	return 0;
}