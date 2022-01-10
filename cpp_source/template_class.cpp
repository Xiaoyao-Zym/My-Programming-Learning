#include<iostream>
#include<string>
using namespace std;
/*********************************��ģ��***********************************
 * ����һ��ͨ���࣬���г�Ա�������Ϳ��Բ�ȷ���������������������
 * **********************��ģ���뺯��ģ�������**************************
 * ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
 * ��ģ����ģ������б��п���Ĭ�ϲ���
 ***************************************************************************/
template <class NameType, class AgeType=int>
class Person1
{
public:
    Person1(NameType name,  AgeType age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    void showPerson()
    {
        cout<<"name��"<<this->m_Name<<"age��"<<this->m_Age;
    }
    NameType m_Name;
    AgeType m_Age;
};
void test01()
{
    Person1<string, int> p1("������", 18);
    p1.showPerson();
}
/***********************��ģ���뺯��ģ�������**************************
 * ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
 * ��ģ����ģ������б��п���Ĭ�ϲ���
 ***************************************************************************/
void test02()
{
    // Person( p1("������", 18);              //��ģ�����Զ������Ƶ�
    Person1<string>p2("����", 18);   //��ȷ����ģ����ģ������б��п�����Ĭ�ϲ���
    p2.showPerson();
}
/*******************��ģ���г�Ա��������ʱ��**************************
 * ��ģ���г�Ա�����ڵ���ʱ�Ŵ���
 ***************************************************************************/
class Person2
{
public:
    void showPerson2()
    {
        cout<<"Person show"<<endl;
    }
};
class Person3
{
public:
    void showPerson3()
    {
        cout<<"Person show"<<endl;
    }
};
template<class T>
class MyClass
{
public:
    T obj;
    //��ģ���г�Ա����,��һ��ʼ�����ᴴ����ֻ�е��òŻᴴ��
    void func1()
    {
        obj.showPerson2();
    }
    void func2()
    {
        obj.showPerson3();
    }
};
void test03()
{
    MyClass<Person2>m1;
    m1.func1();
    MyClass<Person3>m2;
    m2.func2();
}
 int main()
 {
    test01();
    test02();
    test03();
    system("pause");
    return 0;
 }