#include<iostream>
using namespace std;
#define M 9
int main()
{
    int i, j, data[M]={4, 2, 3, 5, 1, 9, 7, 8, 6};
    cout<<"排序前："<<endl;
    for (i = 0; i < M; i++)
    {
        cout<<data[i];
    }
    //开始冒泡排序
    //排序轮数：元素个数-1
    for (i = 0; i < M-1; i++)
    {
    //内层循环对比次数：元素个数-当前轮数-1
        for (j = 0; j <M-i-1 ; j++)
        {
            if (data[j]>data[j+1])
            {
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }
    cout<<"排序后："<<endl;
    for (i = 0; i < M; i++)
    {
        cout<<data[i];
    }
    system("pause");
}