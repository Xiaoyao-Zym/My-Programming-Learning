#include<iostream>
using namespace std;
class Perrson
{
public:
    Perrson(int age)
    {
        m_Age=new int(age);
    }
    ~Perrson()
    {
        if (m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
    }
    //���� ��ֵ�����
    Perrson &operator=(Perrson &p)
    {
        //���������ṩǳ����
        //m_Age=p.m_Age;
        //Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ���ٿ���
        if (m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
        m_Age=new int(*p.m_Age);  //���
        return *this; //��������
    }
    int *m_Age;    
};
void test01()
{
    Perrson p1(18);
    Perrson p2(20);
    Perrson p3(30);
    p3=p2=p1;           //��ֵ
    cout<<"p1������Ϊ��"<<*p1.m_Age<<endl;
    cout<<"p2������Ϊ��"<<*p2.m_Age<<endl;
    cout<<"p3������Ϊ��"<<*p3.m_Age<<endl;
}
int main()
{
    // int a=10;
    // int b=20;
    // int c=30;
    test01();
    system("pause");
    return 0;
}