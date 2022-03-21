#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//find_if
// 1.内置数据类型
//谓词
class  sss
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //查找容器中，是否有5这个元素
    vector<int>::iterator it=find_if(v.begin(), v.end( ), sss() );
    if (it==v.end())
    {
        cout<<"没有找到！"<<endl;
    }
    else
    {
        cout<<"找到："<<*it<<endl;
    }
}
//自定义数据类型
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
// 1.内置数据类型
//谓词
class  sss20
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age>20;
    }
};
//查找、自定义数据类型
void test02()
{
    vector<Person>v;
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //找到年龄大于20的人
    vector<Person>::iterator it=find_if(v.begin(), v.end(), sss20());
    if (it==v.end())
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到元素 姓名："<<it->m_Name<<"年龄："<<it->m_Age<<endl;
    }
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}