#include<iostream>
#include<vector>
using namespace std;
//vector容器数据存取
void printVector(vector<int>v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    printVector(v);
    //利用[]方式访问数组元素
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //利用at方式访问元素
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    //访问第一个元素
    cout<<"第一个元素为："<<v.front()<<endl;
    //获取最后一个元素
    cout<<"最后一个元素为："<<v.front()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}