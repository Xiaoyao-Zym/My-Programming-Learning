#include<iostream>
using namespace std;
//�����C++ָ�룬thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
//thisָ������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
 class Person
{
public:
    Person(int age)           
    {
        age=age;
        //thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
        this->age=age;
    }
    Person &Person_Addage(Person &p)
    {
        this->age+=p.age;
        return *this;
    }
    int age;
};
//this ������Ƴ�ͻ
void test01()
{
    Person p1(18);
    cout<<"p1������Ϊ��"<<p1.age<<endl;
}
//���ض�������*this
void test02()
{
    Person p2(18);
    Person p3(19);
    //��ʽ���˼��
    p2.Person_Addage(p3).Person_Addage(p3).Person_Addage(p3);
    cout<<"p2������Ϊ��"<<p2.age<<endl;
}
int main()
{
    test02();
    system("pause");
    return 0;
}