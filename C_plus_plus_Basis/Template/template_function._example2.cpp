#include<iostream>
using namespace std;
/************************************
**实现通用对数组进行排序的函数
**规则：从小到大
**算法：选择排序
**测试：char数组，int 数组
***********************************/
template<typename T>  //typename可以替换成class
void mySwap(T&a, T&b)
{
    T temp=a;
    a=b;
    b=temp;
}
//排序s数组
template <typename T>
void mySort(T arry[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max=i; //认定最大值的下标
        for (int j = i+1; j < len;  j++)
        {
            if (arry[max] > arry[j])
            {
                max=j;  //更新最大值下标
            }
        }
        if (max!=i)
        {
            mySwap(arry[max], arry[i]);   //交换数组元素
        }
    }
}
//提供打印数组模板
template<typename T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len;  i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}
//测试
void test01()
{
    //测试char数组  
    char charArray[]="bacdfe";
    mySort(charArray, sizeof(charArray)/sizeof(char));
    cout<<"排序后"<<endl;
    printArray(charArray, sizeof(charArray)/sizeof(char));
    //测试 int 数组
    int intArray[]={0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
     mySort(intArray, sizeof(intArray)/sizeof(int));
    cout<<"排序后"<<endl;
    printArray(intArray, sizeof(intArray)/sizeof(int));
}
int main()
{
    test01();
    system("pause");
}
