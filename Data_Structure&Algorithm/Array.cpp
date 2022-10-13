#include <iostream>
#include  <algorithm>
#include <adserr.h>
using namespace std;
//ð�ݷ�
void bobbleSort(int a[], int n)
{
    //ð������
    bool sorted=false;
    while (!sorted)  //����δȷ��ȫ������ʱ�����н���ɨ�轻��
    {
        sorted=true; //�ٶ��Ѿ�����
        for (int i = 1; i < n; i++)
        {
            if(a[i-1]>a[i])   //�ж��Ƿ�����
            {
                swap(a[i-1], a[i]);    //����֮����
                sorted=false;   //�����������ܱ�֤����Ҫ��������־
            }
        }
        n--;        
    }
}//���������ͱ�־sorted���ɼ�ʱ��ǰ�˳���
// //�������
// int sun(int A[], int lo, int hi)
// {
//     if(lo==hi)
//     {
//         return A[lo];
//     }
//     else
//     {
//         int mi=(lo+hi)>>1; //�����е�ԪΪ�磬��ԭ����һ��Ϊ��
//         return sum(A, lo, mi);+
//     }
// }
typedef int Rank; //��
#define DEFAULT_CAPACITY 3//Ĭ�ϵĳ�ʼ����

template<typename T>class Vector
{
protected:
    Rank _size; int _capacity; T* _elem; //��ģ��������������
    void capForm(T const*  A,   Rank  lo,   Rank  hi);  //������������A[lo, hi]
    void expand(); //�ռ䲻��ʱ����
    void shrink();  //װ�����ӹ�Сʱѹ��
    bool bubble(Rank lo, Rank hi); //ɨ�轻��
    void bubbleSort(Rank lo, Rank hi); //ð�������㷨
    Rank max(Rank lo, Rank hi); //ѡȡ���Ԫ��
    void selectionSort(Rank lo, Rank hi); //ѡ�������㷨
    void merge(Rank lo, Rank hi);   //�鲢�㷨
    void mergeSort(Rank lo, Rank hi);   //�鲢�����㷨
    Rank partition(Rank lo, Rank hi);   //��㹹���㷨
    void quickSort(Rank lo, Rank hi);  //���������㷨
    void heapSort(Rank lo, Rank hi);   //������
public:
    //���캯��
    Vector(int s=0, T v=0, int c=DEFAULT_CAPACITY)
    {
        //����Ϊc����СΪs����ʼԪ��Ϊv
        _elem  =  new   T[_capacity=c];
        for(_size=0; _size<=s;  _elem[_size++]);
    }
    //ֻ������
    Rank size() const  {return _size;}  //��С
    bool empty() const {return !_size;} //�ж������Ƿ�Ϊ��
    int disorder() const;  //�ж������Ƿ�������
    Rank  find(T const& e) const {return find(e, 0, (Rank)_size);} //���������������
    Rank  find(T const& e, Rank lo, Rank hi)const; //���������������
    Rank  search(T const& e) const  {return (0>=_size)?-1 : search(e, (Rank)0, (Rank)_size);}
    Rank search(T const& e, Rank lo, Rank hi) const; //���������������
    //��д���ʽӿ�
    T& operator [](Rank r) const; //���������������
    Vector<T>& operator=(Vector<T>const&);  //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
    int remove(Rank lo, Rank hi);   //ɾ����������[lo: hi]֮�ڵ�Ԫ��
    T remove(Rank r);   //ɾ����Ϊr��Ԫ��
    Rank insert(Rank r, T const& e);   //����Ԫ��
    Rank insert(T const& e) {return insert(_size, e);} //Ĭ����ΪĩԪ�ز���
    void sort(Rank lo, Rank hi); //��[lo, hi]����
    void sort() {sort(0, _size);}  //��������
    void unsort(Rank lo, Rank hi); //��[lo, hi]����
     void unsort() {sort(0, _size);}  //��������
     int deduplicate();   //����ȥ��
     int uniiquify();    //����ȥ��
     //����
     void traverse(void (*)(T&));  //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
     template <typename VST>void traverse(VST&);   //����(ʹ�ú������󣬿�ȫ�����޸�)
    //��������
    ~Vector(){delete [] _elem;} //�ͷſռ�
};