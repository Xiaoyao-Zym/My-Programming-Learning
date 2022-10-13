#include<iostream>
#include<string>
using namespace std;
//��̬���ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��
//��ͨд��
class Calculator
{
public:
    int getResult(string open)
    {
        if(open=="+")
        {
            return m_Num1+m_Num2;
        }
        else if(open=="-")
        {
            return m_Num1-m_Num2;
        }
        else if(open=="*")
        {
            return m_Num1*m_Num2;
        }
        //�������չ�µĹ��ܣ���Ҫ�޸�Դ��
        //�����У��ᳫ����ԭ�򣬶���չ���п��ţ����޸Ľ��йر�
    }
    int m_Num1;  //������1
    int m_Num2;  //������2
};
void test01()
{
    //��������������
    Calculator c;
    c.m_Num1=321;
    c.m_Num2=543;
    cout<<c.m_Num1<<"+"<<c.m_Num2<<"="<<c.getResult("+")<<endl;
    cout<<c.m_Num1<<"-"<<c.m_Num2<<"="<<c.getResult("-")<<endl;
    cout<<c.m_Num1<<"*"<<c.m_Num2<<"="<<c.getResult("*")<<endl;
}
//��̬д��
//ʵ�ּ�����������
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
//�ӷ�������
class Add : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1+m_Num2;
    }
};
//����������
class Subtraction : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1-m_Num2;
    }
};
//�˷�������
class Multiplication : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1*m_Num2;
    }
};
void test02()
{
    //����ָ��ָ���������
    AbstractCalculator *abc;
    //�ӷ�����
    abc=new Add;
    abc->m_Num1=123;
    abc->m_Num2=456;
    cout<<abc->m_Num1<<"+"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    delete abc;
    //��������
    abc=new Subtraction;
    abc->m_Num1=123;
    abc->m_Num2=456;
    cout<<abc->m_Num1<<"-"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    delete abc;
    //�˷�����
    abc=new Multiplication;
    abc->m_Num1=123;
    abc->m_Num2=456;
    cout<<abc->m_Num1<<"*"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    delete abc; 
}
int main()
{
    test02();
    system("pause");
    return 0;
}