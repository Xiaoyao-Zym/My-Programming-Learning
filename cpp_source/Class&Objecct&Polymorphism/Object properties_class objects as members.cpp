#include<iostream>
#include<string>
using namespace std;

//�������Ϊ���Ա
class Phone
{
public:
    Phone(string PID)
    {
        m_PID=PID;
    }
    string  m_PID;
};
class Person
{
public:
    Person (string name,string pName): m_Name(name), m_Phone(pName)  //Phone m_Phone=pName; ��ʽת����
    {

    }
    //����
    string m_Name;
    //�ֻ���
    Phone m_Phone;
};  
//�������������Ϊ�����Ա������ʱ���ȹ���������ٹ�������
//����˳���빹��˳���෴
void test01()
{
    Person p("����", "iPhone 13 Pro Max");
    cout<<p.m_Name<<"����"<<p.m_Phone.m_PID<<endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}