#include<iostream>
using namespace  std;
//纯虚函数语法： virtual 返回值类型  函数名 （参数列表）=0；若类中存在纯虚函数，则称这个类为抽象类
//抽象类特点：无法实例化对象 ，子类必须重写抽象类中的纯虚函数，否则也属于抽象类
class Base
{
public:
    //纯虚函数
    //抽象类
    //1.无法实例化对象，2.抽象类的子类  必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func()=0;
};
class Son : public Base
{
public:
    virtual void func()
    {
        cout<<"func函数调用"<<endl;
    }
};
void test01()
{
    // Base a;
    // new Base;  //抽象类是无法实例化对象
    //Son s;  //子类必须重写父类中的纯虚函数，否则无法实例化对象
    Base *base=new Son;
    base->func();
}
int main()
{
    test01();
    system("pause");
    return 0;
}