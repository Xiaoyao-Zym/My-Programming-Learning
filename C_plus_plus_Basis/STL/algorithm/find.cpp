#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//find
//���� ������������
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //���������У��Ƿ���5���Ԫ��
    vector<int>::iterator it=find(v.begin(), v.end( ), 2 );
    if (it==v.end())
    {
        cout<<"û���ҵ���"<<endl;
    }
    else
    {
        cout<<"�ҵ���"<<*it<<endl;
    }
}
//��
class Person
{
public:
    Person(string m_Name, int m_Age)
    {
        this->m_Age=m_Age;
        this->m_Name=m_Name;
    }
    //���� ==�ײ�find֪����ζԱ�person��������
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
//���ҡ��Զ�����������
void test02()
{
    vector<Person>v;
    //��������
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb", 20);
    vector<Person>::iterator it=find(v.begin(), v.end(), pp);
    if (it==v.end())
    {
        cout<<"û���ҵ�"<<endl;
    }
    else
    {
        cout<<"�ҵ�Ԫ�� ������"<<it->m_Name<<"���䣺"<<it->m_Age<<endl;
    }
}
int main()
{
    test02();
    system("pause");
    return 0;
}