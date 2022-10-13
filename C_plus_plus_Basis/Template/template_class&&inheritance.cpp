#include<iostream>
#include<string>
using namespace std;
/***********************类模板与继承**************************
 * 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
 * 如果不指定，编译器无法给子类分配内存
 * 如果想灵活指出父类中T的类型，子类也需要变为类模板
 ***************************************************************************/
template<class T>
class Base
{
    T m;
};
// class Son : public Base   //错误，必须知道父类中T的数据类型，才能继承给子类
class Son : public Base<int>
{


};
void test01()
{
    Son s1;
}
//如果想灵活指出父类中T的类型，子类也需要变为类模板
template<class T1, class T2>
class Son2 : public Base<T2>
{ 
    T1 obj;
};
void test02()
{
    Son2<int,char>s2;
}
//类模板成员函数类外实现
template<class T1, class T2>
class Person 
{
public:
    //成员函数类内声明
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};
//构造函数的类外实现
template<class T1, class T2>
Person<T1, T2> :: Person(T1 name, T2 age)
{
    this->m_Name=name;
    this->m_Age=age;
}
//成员函数类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout<<"姓名："<<this->m_Name<<"年龄："<<this->m_Age;
}
int main()
{
    system("pause");
}