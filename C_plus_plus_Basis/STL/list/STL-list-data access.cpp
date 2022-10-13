#include<iostream>
#include<list>
using namespace std;
//list容器插入和删除
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
     list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //L1(0)   不可以用[]访问list容器中的元素
    //L1.at(0);   不可以用at方式访问list容器中的元素
    //原因是list本质链表，不是用连续性空间存储数据，迭代器也是不支持随机访问的
    cout<<"第一个元素为："<<L1.front()<<endl;
    cout<<"最后一个元素为："<<L1.back()<<endl;
    //验证迭代器是不支持随机访问
    list<int>::iterator it=L1.begin();
    //it=it+2;  报错
    it++;      //正确
    it--;       //不支持随机访问
}
int main()
{
    test();
    system("pause");
    return 0;
}