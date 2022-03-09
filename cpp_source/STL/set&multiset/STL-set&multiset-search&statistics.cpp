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
//set容器查找和统计
void test01()
{
    set<int>s;
    //插入数据，只能用insert方式
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //查找
    set<int>:: iterator pos =s.find(30);
    if (pos!=s.end())
    {
        cout<<"找到元素："<<endl;
    }
}
void test02()
{
    //查找
    set<int>s;
    //插入数据
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //统计30的个数
    int num=s.count(30);
    cout<<"个数："<<num<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}