#include<iostream>
#include<string>
using namespace std;

//��Ա����˽�л�
class Person
{
private:
    /* ���� , �ɶ���д*/  
    string m_Name;
    /* ����*�� ֻ��*/
    int m_Age;
    /* ����*/
    string m_Lover;

public:
    //��������
    void setName(string name)
    {
       m_Name=name;
    }
    //��ȡ����
    string getName()
    {
       return m_Name;
    }
   //��������
    void getAge(int age)
    {
       m_Age=22;
       if (age<<0||age>30)
       {
           cout<<"������������㲻����ң������"<<endl;
           return;
       }
       m_Age=age;
    }
    //��ȡ����
    int getAge()
    {
       m_Age=22;
       return m_Age;
    }
    //���ð�����Ϣ
    void setLover(string name)
    {
       m_Lover=name;
    }
    //��ȡ������Ϣ
    string getLover()
    {
       return m_Lover;
    }
};
int main()
{
   Person s;
   int a;
   cin>>a;
   s.getAge(a);
   s.setName("��ң��");
   s.setLover("������");
   cout<<"������"<<s.getName()<<endl;
   cout<<"���䣺"<<s.getAge()<<endl;
   cout<<s.getName()<<"�����İ�����"<<s.getLover()<<"С��"<<endl;
   system("pause");
   return 0;
}