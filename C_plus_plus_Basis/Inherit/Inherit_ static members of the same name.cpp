#include<iostream>
using namespace std;
//�̳�ͬ����̬��Ա����ʽ
//��������ͬ����Ա  ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա  ��Ҫ��������
class Base
{
public:
    static int m_A; 
    static void func()
    {
        cout<<"Base-static void func()"<<endl;
    }
};
int Base::m_A=100;
class Son :public Base
{
public:
     static int m_A;
     static void func()
    {
        cout<<"Son-static void func()"<<endl;
    }
};
int Son::m_A=200;
//ͬ����̬��Ա����
void test01()
{
    //ͨ���������
    Son s;
    cout<<"Son��m_A="<<s.m_A<<endl;
    cout<<"Base��m_A="<<s.Base::m_A<<endl;
    //ͨ����������
    cout<<"ͨ���������ʣ�"<<endl;
    cout<<"Son��m_A="<<Son::m_A<<endl;
    //��һ��˫ð��ָ��������ʽ���ʣ��ڶ���˫ð��ָ���ʸ�����������
    cout<<"Base��m_A="<<Son::Base::m_A<<endl;
}
//ͬ����̬��Ա����
void test02()
{
    //ͨ���������
    Son s;
    s.func();
    s.Base::func();
    //ͨ����������
    cout<<"ͨ���������ʣ�"<<endl;
    Son::func();
    //��һ��˫ð��ָ��������ʽ���ʣ��ڶ���˫ð��ָ���ʸ�����������
    Son::Base::func();
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}