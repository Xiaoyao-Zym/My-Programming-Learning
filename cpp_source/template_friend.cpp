#include<iostream>
using namespace std;
#include<string>
//2、全局函数类外实现
//需要让编译器提前知道函数的存在
template<class T1, class T2>
class Person;
template<class T1, class T2>
void printPerson2(Person<T1, T2> p2)
{
    cout<<"姓名："<<p2.m_Name<<"年龄："<<p2.m_Age<<endl;
}
//通过全局函数，打印Person信息
template<class T1, class T2>
class Person
{
public: 
    //全局函数，类内实现
    friend void printPerson1(Person<T1, T2> p1)
    {
        cout<<"姓名："<<p1.m_Name<<"年龄："<<p1.m_Age<<endl;
    }
    //全局函数  类外实现
    //加空模板参数列表
    //需要让编译器提前知道函数的存在
    friend void printPerson2<>(Person<T1, T2> p2);
    Person(T1 name, T2 age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};
//1、全局函数在类内实现
void test01()
{
    Person<string, int>p1("叶宇梅",24);
    printPerson1(p1);
}

void test02()
{
    Person<string, int>p2("逍遥张",24);
    printPerson2(p2);
}
int main()
{
    test02();
    system("pause");
}