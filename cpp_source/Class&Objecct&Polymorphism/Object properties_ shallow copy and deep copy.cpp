#include<iostream>
using namespace std;
//ǳ�������򵥵ĸ��ƿ���
//������ڶ���������ռ䣬���п�������
class Person
{
public:
     Person()
    {
        cout<<"Person Ĭ�Ϲ��캯������"<<endl;
    }
    
    Person(int age, int height)
    {
        cout<<"Person�вι��캯������"<<endl;
        m_Age = age;
        m_Height=new int(height);
    }
    Person(const Person &p)
    {
        cout<<"Person�������캯������"<<endl;
        m_Age = p.m_Age;
        //m_Height=p.m_Height; ������Ĭ��ʵ�ֵľ������д���
        //�������
        m_Height=new int(*p.m_Height);

    }
    ~Person()
    {
        //��������ɽ��������ٵ������ͷŲ���
        if (m_Height !=NULL)
        {
            delete m_Height;
            m_Height=NULL;
        }
        
        cout<<"Person������������"<<endl;
    }
    int m_Age;
    int * m_Height;
};

void test01()
{
    Person p1(18, 176);    //ջ���ϵ����ݣ�����ִ����Ϻ��ͷ��ڴ�
    cout<<"p1������Ϊ��"<<p1.m_Age<<"����Ϊ��"<<*p1.m_Height<<endl;
    Person p2(p1);
    cout<<"p2������Ϊ��"<<p2.m_Age<<"����Ϊ��"<<*p1.m_Height<<endl;

}
int main()
{
    test01();
    system("pause");
    return 0;
}