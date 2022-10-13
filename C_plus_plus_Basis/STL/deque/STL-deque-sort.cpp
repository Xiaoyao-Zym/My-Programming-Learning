#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
//deque排序
void printDeque(const deque<int>d)    //限定容器为只读状态
{
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    deque<int>d;
    for (int i = 10; i > 0; i--)
    {
        d.push_back(i);
    }
    cout<<"排序前"<<endl;;
    printDeque(d);
    //排序，默认升序规则
    //对于支持随机访问的迭代器的容器，都可以利用sort算法
    sort(d.begin(), d.end());
    cout<<"排序后"<<endl;
    printDeque(d);
}
int main()
{
    test();
    system("pause");
    return 0;
}