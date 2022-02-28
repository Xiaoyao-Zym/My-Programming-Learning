#include<iostream>
#include<deque>
using namespace std;
void printDeque(const deque<int>d)    //限定容器为只读状态
{
    for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//deque 构造函数
void test()
{
    deque<int>d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int>d2(d1.begin(), d1.end());
    printDeque(d1);
    deque<int>d3(10,10);
    printDeque(d3);
    deque<int>d4(d3);
    printDeque(d4);
}
int main()
{
    test();
    system("pause");
    return 0;
}