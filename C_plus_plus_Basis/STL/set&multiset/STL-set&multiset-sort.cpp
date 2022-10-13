#include<iostream>
#include<set>
using namespace std;
//定义set容器排序规则
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        //降序
        return v1>v2;
    }
};
//set容器  排序案例  对于内置数据类型  做排序
void test01()
{
    set<int, MyCompare>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    for (set<int, MyCompare>:: const_iterator  it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//set 容器自定义数据类型进行排序，按照年龄进行升序，如果年龄相同按照身高进行降序
class Person
{
public:
     Person(string name, int age, int height)
     {
         this->m_Name=name;
         this->m_Age=age;
         this->m_Height=height;
     }
     string m_Name;
     int m_Age;
     int m_Height;
};
class ComparePerosn
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        //按照年龄，升序
        return p1.m_Height>p2.m_Height;
    }
};
void test02()
{
   set<Person, ComparePerosn> s;
   //数据填入
   Person p1("刘备", 35, 163);
   Person p2("张飞", 39, 168); 
   Person p3("关羽", 34, 176);
   Person p4("曹操", 41, 170);
   Person p5("周瑜", 43, 180);
   Person p6("赵云", 35, 178);
   //弹入容器
   s.insert(p1);
   s.insert(p2);
   s.insert(p3);
   s.insert(p4);
   s.insert(p5);
      //排序
   cout<<"------------------------------------------"<<endl;
   cout<<"-------------------排序后---------------"<<endl;
   for (set<Person, ComparePerosn>:: iterator it=s.begin(); it!=s.end(); it++)
   {
       cout<<"姓名："<<(*it).m_Name
              <<" 年龄 ："<<it->m_Age
              <<" 身高 ："<<it->m_Height<<endl;
   }
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}