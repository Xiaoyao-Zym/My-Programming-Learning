#include<iostream>
#include<string>
using namespace std;
/***********************��ģ����̳�**************************
 * ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
 * �����ָ�����������޷�����������ڴ�
 * ��������ָ��������T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��
 ***************************************************************************/
template<class T>
class Base
{
    T m;
};
// class Son : public Base   //���󣬱���֪��������T���������ͣ����ܼ̳и�����
class Son : public Base<int>
{


};
void test01()
{
    Son s1;
}
//��������ָ��������T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��
template<class T1, class T2>
class Son2 : public Base<T2>
{ 
    T1 obj;
};
void test02()
{
    Son2<int,char>s2;
}
//��ģ���Ա��������ʵ��
template<class T1, class T2>
class Person 
{
public:
    //��Ա������������
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};
//���캯��������ʵ��
template<class T1, class T2>
Person<T1, T2> :: Person(T1 name, T2 age)
{
    this->m_Name=name;
    this->m_Age=age;
}
//��Ա��������ʵ��
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout<<"������"<<this->m_Name<<"���䣺"<<this->m_Age;
}
int main()
{
    system("pause");
}