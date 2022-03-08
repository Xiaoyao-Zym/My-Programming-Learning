#include<iostream>
#include<list>
using namespace std;
//list容器  排序案例  对于自定义数据类型  做排序
//按照年龄进行升序，如果年龄相同按照身高进行降序
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
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
bool myCompare(int v1, int v2)
{
    //降序
    return v1>v2;
}
//指定排序规则
bool comparePerson(Person &p1, Person &p2)
{
    //按照年龄，升序
    if (p1.m_Age==p2.m_Age)
    {
        return p1.m_Height<<p2.m_Height;
    }
    return p1.m_Age<p2.m_Age;
}
void test()
{
    //反转
    list<Person> L;
   //数据填入
   Person p1("刘备", 35, 163);
   Person p2("张飞", 39, 168); 
   Person p3("关羽", 34, 176);
   Person p4("曹操", 41, 170);
   Person p5("周瑜", 43, 180);
   Person p6("赵云", 35, 178);
   //弹入容器
   L.push_back(p1);
   L.push_back(p2);
   L.push_back(p3);
   L.push_back(p4);
   L.push_back(p5);
   for (list<Person>:: iterator it=L.begin(); it!=L.end(); it++)
   {
       cout<<"姓名："<<(*it).m_Name
              <<" 年龄 ："<<it->m_Age
              <<" 身高 ："<<it->m_Height<<endl;
   }
   //排序
   cout<<"------------------------------------------"<<endl;
   cout<<"-------------------排序后---------------"<<endl;
   L.sort(comparePerson);
   for (list<Person>:: iterator it=L.begin(); it!=L.end(); it++)
   {
       cout<<"姓名："<<(*it).m_Name
              <<" 年龄 ："<<it->m_Age
              <<" 身高 ："<<it->m_Height<<endl;
   }
}
int main()
{
    test();
    system("pause");
    return 0;
}