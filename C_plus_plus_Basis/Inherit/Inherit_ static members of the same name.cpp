#include<iostream>
using namespace std;
//继承同名静态成员处理方式
//访问子类同名成员  直接访问即可
//访问父类同名成员  需要加作用域
class Base
{
public:
    static int m_A; 
    static void func()
    {
        cout<<"Base-static void func()"<<endl;
    }
};
int Base::m_A=100;
class Son :public Base
{
public:
     static int m_A;
     static void func()
    {
        cout<<"Son-static void func()"<<endl;
    }
};
int Son::m_A=200;
//同名静态成员属性
void test01()
{
    //通过对象访问
    Son s;
    cout<<"Son下m_A="<<s.m_A<<endl;
    cout<<"Base下m_A="<<s.Base::m_A<<endl;
    //通过类名访问
    cout<<"通过类名访问："<<endl;
    cout<<"Son下m_A="<<Son::m_A<<endl;
    //第一个双冒号指以类名方式访问，第二个双冒号指访问父类作用域下
    cout<<"Base下m_A="<<Son::Base::m_A<<endl;
}
//同名静态成员函数
void test02()
{
    //通过对象访问
    Son s;
    s.func();
    s.Base::func();
    //通过类名访问
    cout<<"通过类名访问："<<endl;
    Son::func();
    //第一个双冒号指以类名方式访问，第二个双冒号指访问父类作用域下
    Son::Base::func();
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}