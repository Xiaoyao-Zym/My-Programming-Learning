#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//���ò����㷨   count_if
//ͳ��������������
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
    //��������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int  it=count_if(v.begin(), v.end(), Greater());
    cout<<"Ԫ�ظ�����"<<it<<endl;
}
//ͳ���Զ�����������
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
//�º���
class AgeGreat
{
public:
    bool operator() (const Person & p)
    {
        return p.m_Age>20;
    }
}; 
//���ҡ��Զ�����������
void test02()
{
    vector<Person>v;
    //��������
    Person p1("�ܲ�", 30);
    Person p2("���", 20);
    Person p3("��Ȩ", 30);
    Person p4("С��", 18);
    //���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    int num=count_if(v.begin(), v.end(), AgeGreat());
    cout<<"Ԫ�ظ�����"<<num<<endl;
}
int main()
{
    test02();
    system("pause");
    return 0;
}