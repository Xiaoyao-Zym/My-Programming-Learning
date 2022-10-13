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
//vector容器f容量和大小
void test()
{
   vector<int>v1;                 //默认构造
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   //判断容器是否为空
   if (v1.empty())
   {
       cout<<"v1容器为空"<<endl;
   }
   else
   {
       cout<<"v1不为空"
              <<"v1的容量为："<<v1.capacity()
              <<"  v1的大小为"<<v1.size()<<endl;
   }
   v1.resize(18, 10);  //如果重新指定过长，默认用0填充，也可指定替换对象
   v1.resize(9);       //如果重新指定过短，则删除超出部分
   printVector(v1);
}
int main()
{
    test();
    system("pause");
    return 0;
}