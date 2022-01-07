#include<iostream>
using namespace std;
  /*************************************************************
**函数模板使用注意事项
**自动类型推导，必须推导出一致的数据类型T，才可以使用
**模板必须要确定处T的数据类型，才可以使用
**普通函数与函数模板区别
**1.普通函数可以发生隐式类型转换
**2.函数模板用自动类型推导，不可以发生隐式类型转换
**3. 函数模板用显示指定类型，可以发生隐式类型转换
*************************************************************/
//普通函数
int myAdd01(int a, int b)
{
    return a+b;
}
template<typename T>  //typename可以替换成class
void mySwap(T&a, T&b)
{
    T temp=a;
    a=b;
    b=temp;
}
 void test01()
 {
    int a=10;
    int b=20;
    char c='c';
    mySwap(a, b);
    // mySwap(a,c);  错误，推到不出一致的T类型
    cout<<"a="<<a<<"b="<<b<<endl;
 }
 //函数模板
 template<typename T>  
 void func()
 {
     cout<<"func调用"<<endl;
 }
  template<typename T>  
  T myAdd02(T a, T b)
  {
      return a+b;
  }
 void test02()
 {
    //  func(); 未指定模板中T的数据类型
    func<int>(); 
    int a=10,b=20;
    char c='c';
    cout<<myAdd01(a, c)<<endl;  //发生了隐式类型转换，字符型变量转化为整型变量，a=10, c-99, a+c=109
    //1. 自动类型转换
    // cout<<myAdd02(a, c)<<endl; //报错，无法发生隐式类型转换
    //2. 显示指定类性
    cout<<myAdd02<int>(a, c)<<endl;   //发生隐式类型转换
 }
int main()
{
    test02();
    system("pause");
    return 0;
}