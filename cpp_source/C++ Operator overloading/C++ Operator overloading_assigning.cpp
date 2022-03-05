#include<iostream>
using namespace std;
class Perrson
{
public:
    Perrson(int age)
    {
        m_Age=new int(age);
    }
    ~Perrson()
    {
        if (m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
    }
    //重载 赋值运算符
    Perrson &operator=(Perrson &p)
    {
        //编译器是提供浅拷贝
        //m_Age=p.m_Age;
        //应该先判断是否有属性在堆区，如果有先释放干净，然后再拷贝
        if (m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
        m_Age=new int(*p.m_Age);  //深拷贝
        return *this; //返回自身
    }
    int *m_Age;    
};
void test01()
{
    Perrson p1(18);
    Perrson p2(20);
    Perrson p3(30);
    p3=p2=p1;           //赋值
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;
    cout<<"p3的年龄为："<<*p3.m_Age<<endl;
}
int main()
{
    // int a=10;
    // int b=20;
    // int c=30;
    test01();
    system("pause");
    return 0;
}