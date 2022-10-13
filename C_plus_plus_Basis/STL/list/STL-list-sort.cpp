#include<iostream>
#include<list>
using namespace std;
//list����  ������  �����Զ�����������  ������
//������������������������ͬ������߽��н���
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
    //����
    return v1>v2;
}
//ָ���������
bool comparePerson(Person &p1, Person &p2)
{
    //�������䣬����
    if (p1.m_Age==p2.m_Age)
    {
        return p1.m_Height<<p2.m_Height;
    }
    return p1.m_Age<p2.m_Age;
}
void test()
{
    //��ת
    list<Person> L;
   //��������
   Person p1("����", 35, 163);
   Person p2("�ŷ�", 39, 168); 
   Person p3("����", 34, 176);
   Person p4("�ܲ�", 41, 170);
   Person p5("���", 43, 180);
   Person p6("����", 35, 178);
   //��������
   L.push_back(p1);
   L.push_back(p2);
   L.push_back(p3);
   L.push_back(p4);
   L.push_back(p5);
   for (list<Person>:: iterator it=L.begin(); it!=L.end(); it++)
   {
       cout<<"������"<<(*it).m_Name
              <<" ���� ��"<<it->m_Age
              <<" ��� ��"<<it->m_Height<<endl;
   }
   //����
   cout<<"------------------------------------------"<<endl;
   cout<<"-------------------�����---------------"<<endl;
   L.sort(comparePerson);
   for (list<Person>:: iterator it=L.begin(); it!=L.end(); it++)
   {
       cout<<"������"<<(*it).m_Name
              <<" ���� ��"<<it->m_Age
              <<" ��� ��"<<it->m_Height<<endl;
   }
}
int main()
{
    test();
    system("pause");
    return 0;
}