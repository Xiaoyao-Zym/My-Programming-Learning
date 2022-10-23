#include<iostream>
using namespace std;

const int MaxSize = 100;
template <class T>
class SeqList
{
public:
    SeqList(){length=0;}            
    SeqList(T a[],int n);    
    ~SeqList(){}                    
    int Length(){return length;}    
    T Get(int i);            
    int Locate(T x);         
    void Insert(int i, T x);  
    T Delete(int i);         
    void PrintList();               
private:
    T data[MaxSize];         
    int length;                     
};

template <class T>
SeqList<T>::SeqList(T a[],int n)
{
    if(n>MaxSize) throw "wrong parameter";
    for(int i=0;i<n;i++)
        data[i]=a[i];
    length=n;
}

template <class T>
T SeqList<T>::Get(int i)
{
    if(i<1 && i>length) throw "wrong Location";
    else return data[i-1];
}

template <class T>
int SeqList<T>::Locate(T x)
{
    for(int i=0; i<length; i++)
        if(data[i]==x) return i+1;
    return 0;
}

template <class T>
void SeqList<T>::Insert(int i,T x)
{
    if(length>=MaxSize) throw "Overflow";
    if(i<1 || i>length+1) throw "Location";
    for(int j=length;j>=i;j--)
        data[j]=data[j-1];
    data[i-1]=x;
    length++;
}

template <class T>
T SeqList<T>::Delete(int i)
{
    int x;
    if(length==0) throw "Underflow";
    if(i<1 || i>length) throw "Location";
    x = data[i-1];
    for(int j=i;j<length;j++)
        data[j-1] = data[j];
    length--;
    return x;
}

template <class T>
void SeqList<T>::PrintList()
{
    for(int i=0;i<length;i++)
        cout<<data[i]<<endl;
}

int main()
{
    SeqList<int> p;
    p.Insert(1,5);
    p.Insert(2,9);
    p.PrintList();
    p.Insert(2,3);
    cout<<p.Length()<<endl;
    p.PrintList();
    cout<<p.Get(3)<<endl;
    p.Delete(2);
    p.PrintList();
    return 0;
}