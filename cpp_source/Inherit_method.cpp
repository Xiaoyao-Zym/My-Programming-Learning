#include<iostream>
using namespace std;
//�̳з�ʽ

//�����̳�
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1 : public Base1
{
public:
    void func()
    {
        m_A=10;   //�����еĹ���Ȩ�޳�Ա����������Ϊ����Ȩ��
        m_B=10;   //�����еİ���Ȩ�޳�Ա�����������Ǳ���Ȩ��
        // m_C=10;   //�����е�˽��Ȩ�޳�Ա��������ʲ���
    }
};

void test01()
{
    Son1 s1;
    s1.m_A =100;
//     s1.m_B =100;   //��Son1��m_B�Ǳ���Ȩ�ޣ�������ʲ���
}
//�����̳�
class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son2 : protected Base2
{
public:
    void func()
    {
        m_A=10;   //�����еĹ���Ȩ�޳�Ա�������б�Ϊ����Ȩ��
        m_B=10;   //�����еı���Ȩ�޳�Ա�����������Ǳ���Ȩ��
        // m_C=10;   //�����е�˽��Ȩ�޳�Ա��������ʲ���
    }
};
void test02()
{
    Son2 s1;
    // s1.m_A =100;      //��Son2��m_B�Ǳ���Ȩ�ޣ�������ʲ���
    // //s1.m_B =100;   //��Son2��m_B�Ǳ���Ȩ�ޣ�������ʲ���
}

//˽�м̳�
class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son3 : private Base3
{
public:
    void func()
    {
        m_A=10;   //�����еĹ���Ȩ�޳�Ա�������б�Ϊ˽��Ȩ��
        m_B=10;   //�����еı���Ȩ�޳�Ա������������˽��Ȩ��
        // m_C=10;   //�����е�˽��Ȩ�޳�Ա��������ʲ���
    }
};
void test03()
{
    Son3 s1;
    // s1.m_A =100;       //��Son3��m_B��˽��Ȩ�ޣ�������ʲ���
    // s1.m_B =100;      //��Son3��m_B��˽��Ȩ�ޣ�������ʲ���
}
int main()
{
    system("pause");
    return 0;
}