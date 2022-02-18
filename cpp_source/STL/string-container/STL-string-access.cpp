#include<iostream>
#include<string>
using namespace std;
//string 字符存取
void test01()
{
   //通过[]方式取字符
   string str1="hello";
   for (int i = 0; i < str1.size(); i++)
   {
       cout<<str1[i]<<" ";
   }
   cout<<endl;
   //通过at方法获取字符
   for (int i = 0; i < str1.size(); i++)
   {
       cout<<str1.at(i)<<" ";
   }
   cout<<endl;
   //修改单个字符
   str1[0]='x';
   str1.at(1)='x';
   cout<<"str1="<<str1<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}