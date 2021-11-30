#include<iostream>
using namespace std;
//特殊的C++指针，this指针指向被调用的成员函数所属的对象
//this指针隐含每一个非静态成员函数内的一种指针
 class Person
{
public:
    Person(int age)           
    {
        age=age;
        //this指针指向被调用的成员函数所属的对象
        this->age=age;
    }
    Person &Person_Addage(Person &p)
    {
        this->age+=p.age;
        return *this;
    }
    int age;
};
//this 解决名称冲突
void test01()
{
    Person p1(18);
    cout<<"p1的年龄为："<<p1.age<<endl;
}
//返回对象本身用*this
void test02()
{
    Person p2(18);
    Person p3(19);
    //链式编程思想
    p2.Person_Addage(p3).Person_Addage(p3).Person_Addage(p3);
    cout<<"p2的年龄为："<<p2.age<<endl;
}
int main()
{
    test02();
    system("pause");
    return 0;
}