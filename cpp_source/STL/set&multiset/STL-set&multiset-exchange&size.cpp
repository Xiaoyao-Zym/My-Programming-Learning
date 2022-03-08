#include<iostream>
#include<set>
using namespace  std;
void printSet(set<int>&s)
{
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//set容器大小和交换
//大小
void size()
{
    set<int>s;
    //插入数据，只能用insert方式
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //打印容器
    printSet(s);
    //判断是否为空
    if (s.empty())
    {
        cout<<"s为空"<<endl;
    }
    else
    {
        cout<<"s不为空"<<endl;
        cout<<"s的大小"<<s.size()<<endl;
    }
}
//交换
void exchange()
{
    set<int>s;
    //插入数据，只能用insert方式
    set<int>s1;
    //插入数据，只能用 insert方式
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s1.insert(60);
    s1.insert(70);
    s1.insert(80);
    s1.insert(90);
    s1.insert(100);
    cout<<"交换前："<<endl;
    printSet(s);
    printSet(s1);
    s1.swap(s);
    cout<<"交换后："<<endl;
    printSet(s);
    printSet(s1);
}
int main()
{
    size();
    exchange();
    system("pause");
    return 0;
}