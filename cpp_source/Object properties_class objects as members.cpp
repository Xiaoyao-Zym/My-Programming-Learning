#include<iostream>
#include<string>
using namespace std;

//类对象作为类成员
class Phone
{
public:
    Phone(string PID)
    {
        m_PID=PID;
    }
    string  m_PID;
};
class Person
{
public:
    Person (string name,string pName): m_Name(name), m_Phone(pName)  //Phone m_Phone=pName; 隐式转换法
    {

    }
    //姓名
    string m_Name;
    //手机·
    Phone m_Phone;
};  
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
//析构顺序与构造顺序相反
void test01()
{
    Person p("张三", "iPhone 13 Pro Max");
    cout<<p.m_Name<<"拿着"<<p.m_Phone.m_PID<<endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}