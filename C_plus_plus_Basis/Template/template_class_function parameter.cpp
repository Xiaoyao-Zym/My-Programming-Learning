#include<iostream>
using namespace std;
#include<string>
/************************类模板做函数参数****************************
 * 1、指定传入类型
 * 2、参数模板化
 * 3、整个类模板化
 ***********************************************************************/
template<class T1, class T2>
class Person
{
public: 
    Person(T1 name, T2 age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    void showPerson()
    {
        cout<<"姓名："<<this->m_Name<<"年龄："<<this->m_Age<<endl;
    }
    T1 m_Name;
    T2 m_Age;
};
//1、指定传入类型
void printPerson1(Person<string, int >&p1)
{
    p1.showPerson();
}
void test01()
{
    Person<string, int >p1("孙悟空", 100);
    printPerson1(p1);
}
//2.、参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>&p2)
{
    p2.showPerson();
    cout<<"T1的类型为："<<typeid(T1).name()<<endl;
    cout<<"T2的类型为："<<typeid(T2).name()<<endl;
}
void test02()
{
    Person<string, int>p2("猪八戒", 90);
    printPerson2(p2);
}
//3、整个类模板化
template <class T>
void printPerson3(T &p3)
{
    p3.showPerson();
    cout<<"T的类型为："<<typeid(T).name()<<endl;
}
void test03()
{
    Person<string, int>p3("唐僧", 100);
    printPerson3(p3);
}
int main()
{
    test03();
    system("pause");
}
