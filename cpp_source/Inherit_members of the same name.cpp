#include<iostream>
using namespace std;
class Base
{
public:
    Base()
    {
         m_A=100;
    }
    int m_A;
    void func()
    {
        cout<<"Base-funcd"<<endl;
    }
};
class Son : public Base
{
public:
    Son()
    {
         m_A=200;
    }
    void func()
    {
        cout<<"Son-funcd"<<endl;
    }
};
//ͬ����Ա���Դ���
void test01()
{
    Son s;
    cout<<"Son��m_A="<<s.m_A<<endl;
    //���ͨ��������� ���ʵ�������ͬ����Ա����Ҫ��������
    cout<<"Base��m_A="<<s.Base::m_A<<endl;
}
//ͬ����������
void test02()
{
    Son s;
    s.func();               //ֱ�ӵ��ã������������е�ͬ����Ա
    s.Base::func();      //���ø�����ͬ���������������
    //��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}