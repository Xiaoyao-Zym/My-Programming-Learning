#include<iostream>
#include<string>
using namespace std;
//多态的优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
//普通写法
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
        //如果想扩展新的功能，需要修改源码
        //开发中，提倡开闭原则，对扩展进行开放，对修改进行关闭
    }
    int m_Num1;  //操作数1
    int m_Num2;  //操作数2
};
void test01()
{
    //创建计算器对象
    Calculator c;
    c.m_Num1=321;
    c.m_Num2=543;
    cout<<c.m_Num1<<"+"<<c.m_Num2<<"="<<c.getResult("+")<<endl;
    cout<<c.m_Num1<<"-"<<c.m_Num2<<"="<<c.getResult("-")<<endl;
    cout<<c.m_Num1<<"*"<<c.m_Num2<<"="<<c.getResult("*")<<endl;
}
//多态写法
//实现计算器抽象类
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
//加法计算类
class Add : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1+m_Num2;
    }
};
//减法计算类
class Subtraction : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return m_Num1-m_Num2;
    }
};
//乘法计算类
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
    //父类指针指向子类对象
    AbstractCalculator *abc;
    //加法计算
    abc=new Add;
    abc->m_Num1=123;
    abc->m_Num2=456;
    cout<<abc->m_Num1<<"+"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    delete abc;
    //减法计算
    abc=new Subtraction;
    abc->m_Num1=123;
    abc->m_Num2=456;
    cout<<abc->m_Num1<<"-"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    delete abc;
    //乘法计算
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