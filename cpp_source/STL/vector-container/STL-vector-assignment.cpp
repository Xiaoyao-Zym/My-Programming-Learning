#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>&v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//vector容器f赋值
void test()
{
   vector<int>v1;                 //默认构造
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   printVector(v1);
   //operator=赋值
   vector<int>v2=v1;
    printVector(v2);
    //通过assign形式赋值
    vector<int>v3;
    v3.assign(v2.begin(), v2.end());       //为左闭右开区间
    printVector(v3);
    //拷贝构造
    vector<int>v4;
    v4.assign(10, 9);;
    printVector(v4);
}
int main()
{
    test();
    system("pause");
    return 0;
}