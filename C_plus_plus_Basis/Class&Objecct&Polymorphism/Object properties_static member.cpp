#include<iostream>
using namespace std;

//静态成员指在成员变量和函数前加上关键字static，称为静态成员
/****************************
**静态成员变量：
**所有对象共享同一份数据
**在编译阶段分配内存
**类外声明，类外初始化*
****************************/
/****************************
**静态成员函数
**所有对象共享同一个函数
**静态成员函数只能访问静态成员变量
****************************/
class Person
{
public:
    //静态函数调用
    static void func1()
    {
        m_A=100; //静态成员函数可以访问 静态成员变量
        // m_B=200; //静态成员函数 不可以访问 非静态成员变量，无法区分是哪个对象的成员
        cout<<"static void func1调用"<<endl;
    }  
    //静态成员变量
    static int m_A;
    //非静态成员变量
    int m_B;
private:
    static void func2()
    {
        cout<<"static void func2调用"<<endl;
    }
};
void  test01()
{
    //1.通过对象访问
    Person p;
    p.func1();
    //2.通过类名访问
    Person::func1();
    // Person::func2(); 类外访问不到静态成员函数
}
int main()
{
    system("pause");
    return 0;
}