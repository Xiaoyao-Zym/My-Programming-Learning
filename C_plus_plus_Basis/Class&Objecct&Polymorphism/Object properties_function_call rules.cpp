#include<iostream>
using namespace std;
 //调用规则1：如果用户定义有参构造函数， C++不在提供默认无参构造，但是会提供默认拷贝构造
 // 如果用户定义拷贝构造函数，C++不会提供其他函数
 //默认构造（空实现）
 //析构函数（空实现）
 //拷贝构造（值拷贝）

//2.如果用户创建多个有参构造函数，编译器就不再提供默认构造，依然提供拷贝构造
 class Person
 {
public:
        Person()
    {
        cout<<"Person 默认构造函数调用"<<endl;
    }
    int m_Age;
    Person(int age)
    {
        cout<<"Person有参构造函数调用"<<endl;
        m_Age = age;
    }
    Person(const Person &p)
    {
        cout<<"Person拷贝构造函数调用"<<endl;
        m_Age = p.m_Age;
    }
    ~Person()
    {
        cout<<"Person析构函数调用"<<endl;
    }
 };

 void test01()
 {
     Person p;
     p.m_Age=18;
     Person p2(p);
     cout<<"p2的年龄为："<<p2.m_Age<<endl;
 }

int main()
{
    test01();
    system("pause");
    return 0;
}