#include<iostream>
#include<string>
using namespace std;
//函数调用运算符重载
//打印输出类
class MyPrint
{
public:
    void operator()(string text)
    {
        cout<<text<<endl;
    }
};
void MyPrint02(string test)
{
    cout<<test<<endl;
}
class MyAdd
{
public:
    int  operator()(int a, int b)
    {
        return a+b;
    }
};
void test01()
{
    //重载的()操作符也称为仿函数
    MyPrint myFunc;
    MyPrint02("hello world");
    myFunc("hello world");  //类似函数调用
}
//仿函数十分灵活，无固定的写法
void test02()
{
    MyAdd myAdd;
    int ret=myAdd(100,100);
    cout<<"ret="<<ret<<endl;
    //匿名函数对象
    cout<<"ret="<<MyAdd()(100,100)<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}