#include <iostream>
#include  <algorithm>
#include <adserr.h>
using namespace std;
//冒泡法
void bobbleSort(int a[], int n)
{
    //冒泡排序
    bool sorted=false;
    while (!sorted)  //在尚未确定全局排序时，逐行进行扫描交换
    {
        sorted=true; //假定已经排序
        for (int i = 1; i < n; i++)
        {
            if(a[i-1]>a[i])   //判断是否逆序
            {
                swap(a[i-1], a[i]);    //交换之，并
                sorted=false;   //因整体排序不能保证，需要清楚排序标志
            }
        }
        n--;        
    }
}//借助布尔型标志sorted，可及时提前退出。
// //二分求和
// int sun(int A[], int lo, int hi)
// {
//     if(lo==hi)
//     {
//         return A[lo];
//     }
//     else
//     {
//         int mi=(lo+hi)>>1; //将居中单元为界，将原区间一分为二
//         return sum(A, lo, mi);+
//     }
// }
typedef int Rank; //秩
#define DEFAULT_CAPACITY 3//默认的初始容量

template<typename T>class Vector
{
protected:
    Rank _size; int _capacity; T* _elem; //规模、容量、数据区
    void capForm(T const*  A,   Rank  lo;   Rank  hi);  //复制数组区间A[lo, hi]
    void expand(); //空间不足时扩容
    void shrink();  //装填因子过小时压缩
    bool bubble(Rank lo, Rank hi); //扫描交换
    void bubbleSort(Rank lo, Rank hi); //冒泡排序算法
    Rank max(Rank lo, Rank hi); //选取最大元素
    void selectionSort(Rank lo, Rank hi); //选择排序算法
    void merge(Rank lo, Rank hi);   //归并算法
    void mergeSort(Rank lo, Rank hi);   //归并排序算法
    Rank partition(Rank lo, Rank hi);   //轴点构造算法
    void quickSort(Rank lo, Rank hi);  //快速排序算法
    void heapSort(Rank lo, Rank hi);   //堆排序
public:
    //构造函数
    Vector(int s=0, T v=0, int c=DEFAULT_CAPACITY)
    {
        //容量为c，大小为s，初始元素为v
        _elem  =  new   T[_capacity=c];
        for(_size=0; _size<=s; _elem[_size++];)
    }
    //只读函数
    Rank size() const  {return _size;}  //大小
    bool empty() const {return !_size;} //判断向量是否为空
    int disorder() const;  //判断向量是否已排序
    Rank  find(T const& e) const {return find(e, 0, (Rank)_size);} //无序向量整体查找
    Rank  find(T const& e, Rank lo, Rank hi)const; //无序向量区间查找
    Rank  search(T const& e) const  {return (0>=_size)?-1 : search(e, (Rank)0, (Rank)_size);}
    Rank search(T const& e, Rank lo, Rank hi) const; //有序向量区间查找
    //可写访问接口
    T& operator [](Rank r) const; //有序向量整体查找
    Vector<T>& operator=(Vector<T>const&);  //重载赋值操作符，以便直接克隆向量
    int remove(Rank lo, Rank hi);   //删除秩在区间[lo: hi]之内的元素
    T remove(Rank r);   //删除秩为r的元素
    Rank insert(Rank r, T const& e);   //插入元素
    Rank insert(T const& e) {return insert(_size, e);} //默认作为末元素插入
    void sort(Rank lo, Rank hi); //对[lo, hi]排序
    void sort() {sort(0, _size);}  //整体排序
    void unsort(Rank lo, Rank hi); //对[lo, hi]置乱
     void unsort() {sort(0, _size);}  //整体置乱
     int deduplicate();   //无序去重
     int uniiquify();    //有序去重
     //遍历
     void traverse(void (*)(T&));  //遍历（使用函数指针，只读或局部性修改）
     template <typename VST>void traverse(VST&);   //遍历(使用函数对象，可全局性修改)
    //析构函数
    ~Vector(){delete [] _elem;} //释放空间
};