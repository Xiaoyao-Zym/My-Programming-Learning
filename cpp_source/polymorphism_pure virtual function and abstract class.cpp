#include<iostream>
using namespace  std;
//���麯���﷨�� virtual ����ֵ����  ������ �������б�=0�������д��ڴ��麯������������Ϊ������
//�������ص㣺�޷�ʵ�������� �����������д�������еĴ��麯��������Ҳ���ڳ�����
class Base
{
public:
    //���麯��
    //������
    //1.�޷�ʵ��������2.�����������  ������д�����еĴ��麯��������Ҳ���ڳ�����
    virtual void func()=0;
};
class Son : public Base
{
public:
    virtual void func()
    {
        cout<<"func��������"<<endl;
    }
};
void test01()
{
    // Base a;
    // new Base;  //���������޷�ʵ��������
    //Son s;  //���������д�����еĴ��麯���������޷�ʵ��������
    Base *base=new Son;
    base->func();
}
int main()
{
    test01();
    system("pause");
    return 0;
}