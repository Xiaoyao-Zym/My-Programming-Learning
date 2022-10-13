#include<iostream>
using namespace std;
//函数模板
//函数声明或定义
/************************************************************************
*template----声明创建模板
*typename----表面其后面的符号是一种数据类型，可以用class代替
*T----通用的数据类型，名称可以替换，通常为大写字母
*************************************************************************/
// //交换两个整型的函数
// void swapInt (int &a, int &b)
// {
//     int temp=a;
//     a=b;
//     b=temp;
// }
// //交换两个浮点型的函数
// void swapDouble (double &a, double &b)
// {
//     double temp=a;
//     a=b;
//     b=temp;
// }
template<typename T> //声明模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp=a;
    a=b;
    b=temp;
}
 void test01()
 {
    int a=10;
    int b=20;
    // swapInt(a, b);
    //利用函数模板交换
    //1.自动类型推导
    // mySwap(a, b);
    //2.显示指定类型
    mySwap<int>(a, b);
    cout<<"a="<<a<<"b="<<b<<endl;
    double c=10.00;
    double d=20.00;
    // swapDouble(c, d);
    cout<<"c="<<c<<"d="<<d<<endl;
 }
int main()
{
    test01();
    system("pause");
    return 0;
}