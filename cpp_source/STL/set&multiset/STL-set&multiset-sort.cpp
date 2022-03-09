#include<iostream>
#include<set>
using namespace std;
//����set�����������
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        //����
        return v1>v2;
    }
};
//set����  ������  ����������������  ������
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
//set �����Զ����������ͽ������򣬰�����������������������ͬ������߽��н���
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
        //�������䣬����
        return p1.m_Height>p2.m_Height;
    }
};
void test02()
{
   set<Person, ComparePerosn> s;
   //��������
   Person p1("����", 35, 163);
   Person p2("�ŷ�", 39, 168); 
   Person p3("����", 34, 176);
   Person p4("�ܲ�", 41, 170);
   Person p5("���", 43, 180);
   Person p6("����", 35, 178);
   //��������
   s.insert(p1);
   s.insert(p2);
   s.insert(p3);
   s.insert(p4);
   s.insert(p5);
      //����
   cout<<"------------------------------------------"<<endl;
   cout<<"-------------------�����---------------"<<endl;
   for (set<Person, ComparePerosn>:: iterator it=s.begin(); it!=s.end(); it++)
   {
       cout<<"������"<<(*it).m_Name
              <<" ���� ��"<<it->m_Age
              <<" ��� ��"<<it->m_Height<<endl;
   }
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}