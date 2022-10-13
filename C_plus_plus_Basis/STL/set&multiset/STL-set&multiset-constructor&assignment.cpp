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
//set容器构造和赋值
void test()
{
    set<int>s;
    //插入数据，只能用insert方式
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    //遍历容器
    //set容器特点，所有元素插入时候自动排序
    //set容器不允许插入重复值
    printSet(s);
    //拷贝构造
    set<int>s2(s);
    printSet(s2);
    //赋值
    set<int>s3;
    s3=s2;
    printSet(s3);
}
int main()
{
    test();
    system("pause");
    return 0;
}