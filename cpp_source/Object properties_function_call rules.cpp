#include<iostream>
using namespace std;
 //���ù���1������û������вι��캯���� C++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ�������
 // ����û����忽�����캯����C++�����ṩ��������
 //Ĭ�Ϲ��죨��ʵ�֣�
 //������������ʵ�֣�
 //�������죨ֵ������

//2.����û���������вι��캯�����������Ͳ����ṩĬ�Ϲ��죬��Ȼ�ṩ��������
 class Person
 {
public:
        Person()
    {
        cout<<"Person Ĭ�Ϲ��캯������"<<endl;
    }
    int m_Age;
    Person(int age)
    {
        cout<<"Person�вι��캯������"<<endl;
        m_Age = age;
    }
    Person(const Person &p)
    {
        cout<<"Person�������캯������"<<endl;
        m_Age = p.m_Age;
    }
    ~Person()
    {
        cout<<"Person������������"<<endl;
    }
 };

 void test01()
 {
     Person p;
     p.m_Age=18;
     Person p2(p);
     cout<<"p2������Ϊ��"<<p2.m_Age<<endl;
 }

int main()
{
    test01();
    system("pause");
    return 0;
}