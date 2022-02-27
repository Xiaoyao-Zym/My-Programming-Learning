#include<iostream>
#include<vector>
using namespace std;
//vector 容器的插入与删除
/*
*push_back(else);                           //尾部插入元素ele
*pop_back();                                  //删除最后一个元素
*insert(const_itrerator pos, ele);   //迭代器指向位置pos插入元素ele
*insert(const_iterator pos, int count,ele); //迭代器指向位置pos插入count个元素ele
*errase(const_iterator pos);        //删除迭代器的元素
*erase(const_iterrator start, const_iterator end); //删除迭代器从start到end之间的元素
*clear();
*/
void printVector(vector<int>&v)
{
    for (vector<int>:: iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    vector<int>v1;
    //尾插法初始化容器
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    //尾删法
    v1.pop_back();
    printVector(v1);
    //尾插入  第一个参数是迭代器
    v1.insert(v1.begin(), 2, 100);
    printVector(v1);
    //删除   参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);
    //清空容器
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}
int main()
{
    test();
    system("pause");
    return 0;
}