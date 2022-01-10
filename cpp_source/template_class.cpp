#include<iostream>
#include<string>
using namespace std;
/*********************************类模板***********************************
 * 建立一个通用类，类中成员数据类型可以不确定，用虚拟的类型来代表
 * **********************类模板与函数模板的区别**************************
 * 类模板没有自动类型推导的使用方式
 * 类模板在模板参数列表中可以默认参数
 ***************************************************************************/
template <class NameType, class AgeType=int>
class Person1
{
public:
    Person1(NameType name,  AgeType age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    void showPerson()
    {
        cout<<"name："<<this->m_Name<<"age："<<this->m_Age;
    }
    NameType m_Name;
    AgeType m_Age;
};
void test01()
{
    Person1<string, int> p1("孙行者", 18);
    p1.showPerson();
}
/***********************类模板与函数模板的区别**************************
 * 类模板没有自动类型推导的使用方式
 * 类模板在模板参数列表中可以默认参数
 ***************************************************************************/
void test02()
{
    // Person( p1("孙行者", 18);              //类模板无自动类型推导
    Person1<string>p2("猪悟净", 18);   //正确，类模板在模板参数列表中可以有默认参数
    p2.showPerson();
}
/*******************类模板中成员函数创建时机**************************
 * 类模板中成员函数在调用时才创建
 ***************************************************************************/
class Person2
{
public:
    void showPerson2()
    {
        cout<<"Person show"<<endl;
    }
};
class Person3
{
public:
    void showPerson3()
    {
        cout<<"Person show"<<endl;
    }
};
template<class T>
class MyClass
{
public:
    T obj;
    //类模板中成员函数,，一开始并不会创建，只有调用才会创建
    void func1()
    {
        obj.showPerson2();
    }
    void func2()
    {
        obj.showPerson3();
    }
};
void test03()
{
    MyClass<Person2>m1;
    m1.func1();
    MyClass<Person3>m2;
    m2.func2();
}
 int main()
 {
    test01();
    test02();
    test03();
    system("pause");
    return 0;
 }