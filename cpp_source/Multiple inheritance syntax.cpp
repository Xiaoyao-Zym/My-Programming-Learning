#include<iostream>
using namespace std;

//��̳��﷨
class Base1
{
public:
    Base1()
    {
        m_A=100;
    }
    int m_A;
};
//���� ��Ҫ�̳�Base1��Base2
//�﷨��class ���ࣺ�̳з�ʽ ����1���̳з�ʽ ����2����
class Base2
{
public:
    Base2()
    {
        m_B=100;
    }
    int m_B;
};

//���� ��Ҫ�̳�Base1��Base2
class Son :public Base1, public Base2
{
public:
    Son()
    {
         int m_C;
         int m_D;
    }
};
void test01()
{
    Son s;
    cout <<"sizeof Son="<<sizeof(s)<<endl;
    cout<<"m_A="<<s.m_A<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}