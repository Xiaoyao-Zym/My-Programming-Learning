#include<iostream>
#include<vector>
#include<string>
using namespace std;
//自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->mName=name;
        this->mAge= age;
    }
    string  mName;
    int mAge;
};
void test01()
{
    vector<Person>v;
    Person p1("孙悟空", 500);
    Person p2("猪八戒", 500);
    Person p3("沙和尚", 500);
    Person p4("唐  僧", 500);
    Person p5("白龙马", 500);
    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //遍历容器中的数据
    for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<"姓名： "<<(*it).mName<<"  年龄："<<(*it).mAge<<endl;
    }
}
//存放自定义数据的指针
void test02()
{
     vector<Person*>v;
    Person p1("孙悟空", 500);
    Person p2("猪八戒", 500);
    Person p3("沙和尚", 500);
    Person p4("唐  僧", 500);
    Person p5("白龙马", 500);
    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
     //遍历容器中的数据
    for (vector<Person*>:: iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<"姓名： "<<(*it)->mName<<"  年龄："<<(*it)->mAge<<endl;
    }
}
int main()
{
    //test01();
    test02();
    system("pause");
    return 0;   
}