#include<iostream>
#include<string>
using namespace std;
//string ���Ӵ�
void test01()
{
   string str="abcdef";
   string subStr=str.substr(1, 2);
   cout<<"subStr="<<subStr<<endl;
}
void test02()
{
    string email="zym@qq.com";
    //��ȡ�û���
    int pos= email.find("@");
    string userName=email.substr(0, pos);
    cout<<"userName="<<userName<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}