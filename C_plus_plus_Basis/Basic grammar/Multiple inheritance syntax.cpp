#include<iostream>
using namespace std;

//多继承语法
class Base1
{
public:
    Base1()
    {
        m_A=100;
    }
    int m_A;
};
//子类 需要继承Base1和Base2
//语法：class 子类：继承方式 父类1，继承方式 父类2……
class Base2
{
public:
    Base2()
    {
        m_B=100;
    }
    int m_B;
};

//子类 需要继承Base1和Base2
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