#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//count
//ͳ�Ƹ���
//1.������������
void test()
{
    vector<int>v;
    //��������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int  it=count(v.begin(), v.end(), 20);
    cout<<"Ԫ�ظ�����"<<it<<endl;
}
//2. �Զ�����������
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
    Person p1("bbb", 20);
    Person p2("bbb", 20);
    Person p3("ccc",  30);
    Person p4("ddd", 40);
    //���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb", 20);
    int num=count(v.begin(), v.end(), pp);
    cout<<"Ԫ�ظ�����"<<num<<endl;
}
int main()
{
    test02();
    system("pause");
    return 0;
}
