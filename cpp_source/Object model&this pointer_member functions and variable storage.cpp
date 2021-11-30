#include<iostream>
using namespace std;
//成员函数和变量是分开存储
 class Person
{
public:
    int m_A;                //非静态成员变量，属于类的对象上
    static int m_B;      // 静态成员变量，不属于类对象上
    void func()           //非静态成员函数，不属于类对象上
    {

    }
    static void func2()    //
    {

    }

};
void test01()
{
    Person p;
    //空对象占用内存空间：1
    //C++对象为每个空对象分配一个字节空间，是为了区分空对象占用内存的位置
    //每个空对象也应该有唯一地址
    cout<<"size of p="<<sizeof(p)<<endl;
}
void test02()
{
    Person p1;
    cout<<"size of p1="<<sizeof(p1)<<endl;
}
 int main()
{
    test02();
    system("pause");
    return 0;
}