#include<iostream>
#include<string>
using namespace std;
//string �ַ�
void test01()
{
   //ͨ��[]��ʽȡ�ַ�
   string str1="hello";
   str1.insert(2,"xxx");
   cout<<"str1="<<str1<<endl;
   //ɾ��
   str1.erase(2, 3);
   cout<<"str1="<<str1<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}