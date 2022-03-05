#include<iostream>
using namespace std;
#include<string>
//2��ȫ�ֺ�������ʵ��
//��Ҫ�ñ�������ǰ֪�������Ĵ���
template<class T1, class T2>
class Person;
template<class T1, class T2>
void printPerson2(Person<T1, T2> p2)
{
    cout<<"������"<<p2.m_Name<<"���䣺"<<p2.m_Age<<endl;
}
//ͨ��ȫ�ֺ�������ӡPerson��Ϣ
template<class T1, class T2>
class Person
{
public: 
    //ȫ�ֺ���������ʵ��
    friend void printPerson1(Person<T1, T2> p1)
    {
        cout<<"������"<<p1.m_Name<<"���䣺"<<p1.m_Age<<endl;
    }
    //ȫ�ֺ���  ����ʵ��
    //�ӿ�ģ������б�
    //��Ҫ�ñ�������ǰ֪�������Ĵ���
    friend void printPerson2<>(Person<T1, T2> p2);
    Person(T1 name, T2 age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};
//1��ȫ�ֺ���������ʵ��
void test01()
{
    Person<string, int>p1("Ҷ��÷",24);
    printPerson1(p1);
}

void test02()
{
    Person<string, int>p2("��ң��",24);
    printPerson2(p2);
}
int main()
{
    test02();
    system("pause");
}