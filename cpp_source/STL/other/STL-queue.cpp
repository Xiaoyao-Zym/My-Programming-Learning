#include<iostream>
#include<queue>
using namespace std;
//����queue����
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
    string m_Name;
    int m_Age;
};
void test()
{
    //��������
    queue<Person>q;
    //��ջ
    Person p1("������", 100);
    Person p2("�����", 500);
    Person p3("��˽�", 400);
    Person p4("ɳ����", 300);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"���еĴ�С��"<<q.size()<<endl;
    //ֻҪ���в�Ϊ�գ��鿴��ͷ�Ͷ�β������ִ�г��Ӳ���
    while (!q.empty())
    {
        //�鿴��ͷԪ��
        cout<<"��ͷԪ��Ϊ--������"<<q.front().m_Name
               <<"--���䣺"<<q.front().m_Age<<endl
               <<"��βԪ��Ϊ--������"<<q.back().m_Name
               <<"--���䣺"<<q.back().m_Age<<endl;
        //����
        q.pop();
    }
    cout<<"���еĴ�С��"<<q.size()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}