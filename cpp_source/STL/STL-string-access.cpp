#include<iostream>
#include<string>
using namespace std;
//string �ַ���ȡ
void test01()
{
   //ͨ��[]��ʽȡ�ַ�
   string str1="hello";
   for (int i = 0; i < str1.size(); i++)
   {
       cout<<str1[i]<<" ";
   }
   cout<<endl;
   //ͨ��at������ȡ�ַ�
   for (int i = 0; i < str1.size(); i++)
   {
       cout<<str1.at(i)<<" ";
   }
   cout<<endl;
   //�޸ĵ����ַ�
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