#include<string>
#include<iostream>
using namespace std;
//����
void test01()
{
    string str1="abcdefg";
    //find���Ҵ������ң�
    int pos =str1.find("cd");
    if (pos==-1)
    {
        cout<<"δ�ҵ��ַ���";
    }
    else
    {
        cout<<"�ҵ��Ӵ�λ�ã�"<<pos<<endl;
    }
    //rfind����������
    pos=str1.rfind("cd");
    cout<<"pos="<<pos<<endl; 
}
//�滻
void test02()
{
    string str2="abcdefd";
    str2.replace(2, 3,"12345");
    cout<<"str2="<<str2<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}