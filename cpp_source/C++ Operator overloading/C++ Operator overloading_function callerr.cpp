#include<iostream>
#include<string>
using namespace std;
//�����������������
//��ӡ�����
class MyPrint
{
public:
    void operator()(string text)
    {
        cout<<text<<endl;
    }
};
void MyPrint02(string test)
{
    cout<<test<<endl;
}
class MyAdd
{
public:
    int  operator()(int a, int b)
    {
        return a+b;
    }
};
void test01()
{
    //���ص�()������Ҳ��Ϊ�º���
    MyPrint myFunc;
    MyPrint02("hello world");
    myFunc("hello world");  //���ƺ�������
}
//�º���ʮ�����޹̶���д��
void test02()
{
    MyAdd myAdd;
    int ret=myAdd(100,100);
    cout<<"ret="<<ret<<endl;
    //������������
    cout<<"ret="<<MyAdd()(100,100)<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}