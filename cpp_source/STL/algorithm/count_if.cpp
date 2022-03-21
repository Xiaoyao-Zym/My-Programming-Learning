#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//常用查找算法   count_if
//统计内置数据类型
class Greater
{
public:
    bool operator()(int val)
    {
        return val>20;
    }
};
void test01()
{
        vector<int>v;
    //创建数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int  it=count_if(v.begin(), v.end(), Greater());
    cout<<"元素个数："<<it<<endl;
}
//统计自定义数据类型
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    string m_Name;
    int m_Age;
};
//仿函数
class AgeGreat
{
public:
    bool operator() (const Person & p)
    {
        return p.m_Age>20;
    }
}; 
//查找、自定义数据类型
void test02()
{
    vector<Person>v;
    //创建数据
    Person p1("曹操", 30);
    Person p2("周瑜", 20);
    Person p3("孙权", 30);
    Person p4("小乔", 18);
    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    int num=count_if(v.begin(), v.end(), AgeGreat());
    cout<<"元素个数："<<num<<endl;
}
int main()
{
    test02();
    system("pause");
    return 0;
}