#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    bool  operator==(Person &p)   //相等重载
    {
        if (this->m_Name==p.m_Name&&this->m_Age==p.m_Age)
        {
            return true;
        }
        return false;
    }
    bool  operator !=(Person &p)  //不相等重载
    {
        if (this->m_Name!=p.m_Name&&this->m_Age==p.m_Age)
        {
            return true;
        }
        return false;
    }
    string m_Name;
    int m_Age;
};
void test01()
{
    Person p1("Tom",18);
    Person p2("Tom",18);
    if (p1==p2)
    {
        cout<<"p1和p2是相等的！"<<endl;
    }
    else
    {
         cout<<"p1和p2是不相等的！"<<endl;
    }
    if (p1!=p2)
    {
        cout<<"p1和p2是不相等的！"<<endl;
    }
    else
    {
         cout<<"p1和p2是相等的！"<<endl;
    }
}
int main()
{
    test01();
    system("pause");
    return 0;
}