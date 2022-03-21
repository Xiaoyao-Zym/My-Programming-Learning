#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//count
//统计个数
//1.内置数据类型
void test()
{
    vector<int>v;
    //创建数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int  it=count(v.begin(), v.end(), 20);
    cout<<"元素个数："<<it<<endl;
}
//2. 自定义数据类型
//类
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    //重载 ==底层find知道如何对比person数据类型
    bool operator== (const Person & p)
    {
        if (this->m_Name==p.m_Name&& this->m_Age==p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
//查找、自定义数据类型
void test02()
{
    vector<Person>v;
    //创建数据
    Person p1("bbb", 20);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb", 20);
    int num=count(v.begin(), v.end(), pp);
    cout<<"元素个数："<<num<<endl;
}
int main()
{
    test02();
    system("pause");
    return 0;
}
