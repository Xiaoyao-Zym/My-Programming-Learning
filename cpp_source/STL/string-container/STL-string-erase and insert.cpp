#include<iostream>
#include<string>
using namespace std;
//string 字符
void test01()
{
   //通过[]方式取字符
   string str1="hello";
   str1.insert(2,"xxx");
   cout<<"str1="<<str1<<endl;
   //删除
   str1.erase(2, 3);
   cout<<"str1="<<str1<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}