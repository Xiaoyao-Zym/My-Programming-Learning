#include<iostream>
using namespace std;
//����ĳ�ʼ��������
//���캯�����༰����
//����
// ���ղ�������   �޲κ�������    �вκ�������
//�������ͷ���    ��ͨ����           ��������
class Person
{
    //���캯��
    //û�з���ֵ������дvoid
    //��������������ͬ
    //���캯�������в��������Է�������
    //���������ʱ�򣬹��캯�����Զ����ã�����ֻ����һ�Ρ�
public:
    Person()
    {
        cout<<"Person���޲ι��캯������"<<endl;
    }
     int age;
    Person(int a)
    {
        age=a;
        cout<<"Person���вι��캯������"<<endl;
    }
    //�������캯��
    Person(const Person&p)
    {
        //������������ϵ��������ԣ���������
        cout<<"Person�Ŀ������캯������"<<endl;
        age =p.age;

    }
    //�������� ���������Ĳ�����
    //û�з���ֵ������дvoid
    //��������������ͬ
    //���캯�������в��������Է�������
    //���������ʱ�򣬹��캯�����Զ����ã�����ֻ����һ�Ρ�
    ~Person()
    {
        cout<<"Person ������������"<<endl;
    }
};

//����
void test01()
{
    //1.���ŷ�
    //Person p1;          //�����޲κ���
    //Person p2(10);   //�����вκ���
   // Person p3(p2);   //�������캯������
    //cout<<"p2������Ϊ��"<<p2.age<<endl;
    //cout<<"p3������Ϊ��"<<p3.age<<endl;
    //ע������
    //����Ĭ�Ϲ��캯�������ܼ� ()

    //��ʾ��
    //Person p1;
    //Person p2=Person(10);
    //Person p3=Person(p2);
    //ע������2
    //Person(10);  //���������ص㣺��ǰ��ִ�н�����ϵͳ����������յ���������
    
    //��ʽת����
    Person p4=10;  //�൱�� д����Person  p4=Person(10);
}
int main()
{
    test01();
    system("pause");
    return 0;
}