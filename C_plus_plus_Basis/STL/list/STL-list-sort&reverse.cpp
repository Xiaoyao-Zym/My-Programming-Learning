#include<iostream>
#include<list>
using namespace std;
//list 反转和排序
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
bool myCompare(int v1, int v2)
{
    //降序
    return v1>v2;
}
void test()
{
    //反转
    list<int> L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(30);
    cout<<"反转前："<<endl;
    L1.reverse();
    cout<<"反转后："<<endl; 
    printList(L1);
    //排序
    cout<<"排序前："<<endl;
    printList(L1);
    L1.sort();   //默认升序
    cout<<"排序后："<<endl;
    printList(L1);
    //所有不支持随机访问迭代器的容器，不可以用标准算法
    //不支持随机访问迭代器的容器，内部会提供对应一些算法
    L1.sort(myCompare);
    cout<<"排序后："<<endl;
    printList(L1);
}
int main()
{
    test();
    system("pause");
    return 0;
}