#include<iostream>
#include<vector>
#include<string>
using namespace std;
//�Զ�����������
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
    Person p1("�����", 500);
    Person p2("��˽�", 500);
    Person p3("ɳ����", 500);
    Person p4("��  ɮ", 500);
    Person p5("������", 500);
    //���������������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //���������е�����
    for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<"������ "<<(*it).mName<<"  ���䣺"<<(*it).mAge<<endl;
    }
}
//����Զ������ݵ�ָ��
void test02()
{
     vector<Person*>v;
    Person p1("�����", 500);
    Person p2("��˽�", 500);
    Person p3("ɳ����", 500);
    Person p4("��  ɮ", 500);
    Person p5("������", 500);
    //���������������
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
     //���������е�����
    for (vector<Person*>:: iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<"������ "<<(*it)->mName<<"  ���䣺"<<(*it)->mAge<<endl;
    }
}
int main()
{
    //test01();
    test02();
    system("pause");
    return 0;   
}