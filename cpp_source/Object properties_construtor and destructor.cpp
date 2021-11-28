#include<iostream>
using namespace std;
//对象的初始化和清理
//构造函数，进行初始化操作
class Person
{
    //构造函数
    //没有返回值，不用写void
    //函数名与类名相同
    //构造函数可以有参数，可以发生重载
    //创建对象的时候，构造函数会自动调用，而且只调用一次。
public:
    Person()
    {
        cout<<"Person 构造函数调用"<<endl;
    }
    //解析函数 进行清理的操作。
    //没有返回值，不用写void
    //函数名与类名相同
    //构造函数可以有参数，可以发生重载
    //创建对象的时候，构造函数会自动调用，而且只调用一次。
    ~Person()
    {
        cout<<"Person 析构函数调用"<<endl;
    }
};

void test01()
{
    Person p;    //栈区上的数据，函数执行完毕后，释放内存
}
int main()
{
    test01();
    system("pause");
    return 0;
}