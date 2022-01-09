#include<iostream>
#include<string>
using namespace std;
/*************函数模板使用注意事项***********************
 * 自动类型推导，必须推导出一致的数据类型T，才可以使用
*模板必须要确定处T的数据类型，才可以使用
*普通函数与函数模板区别
*1.普通函数可以发生隐式类型转换
*2.函数模板用自动类型推导，不可以发生隐式类型转换
*3. 函数模板用显示指定类型，可以发生隐式类型转换
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
    int a=10, b=20;
    char c='c';
    cout<<myAdd01(a, c)<<endl;  //发生了隐式类型转换，字符型变量转化为整型变量，a=10, c-99, a+c=109
    //1. 自动类型转换
    // cout<<myAdd02(a, c)<<endl; //报错，无法发生隐式类型转换
    //2. 显示指定类性
    cout<<myAdd02<int>(a, c)<<endl;   //发生隐式类型转换
 }
/************普通函数与函数模板调用规则****************
**普通函数和函数模板都可以实现，优先调用普通函数
**可以通过空模板参数列表来强制调用函数模板
**函数模板可以发生重载
**如果函数模板可以产生更好的匹配，优先调用函数模板
**提供了函数模板，最好不使用普通函数，否则容易出现二义性
*************************************************************/
int myPrint(int a, int b);
// {
//     return a+b;
// }
template<typename T>
T  myPrint(T a, T b)
{
    return a+b;
}
void test03()
{
    int a=10;
    int b=10;
    // cout<<"a+b="<<myPrint(a, b)<<endl;   //普通函数和函数模板都可以实现，优先调用普通函数，报错，普通函数无定义
    // cout<<"a+b="<<myPrint<>(a, b)<<endl;  //通过空模板参数列表来强制调用函数模板
    char c1='a';
    char c2='c';
    cout<<"a+b="<<myPrint<>(a, b)<<endl;  // //如果函数模板可以产生更好的匹配，优先调用函数模板
}
/***************************模板的局限性*********************************
**模板并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现
/*************************************************************************/
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
   string m_Name;
   int m_Age;
};
template<typename T>
bool myCompare(T &a, T &b)
{
    if (a==b)
    {
        return true;
    }
    else
    {
        return  false;
    }
}
void test04()
{
    int a=10;
    int b=20;
    bool ret=myCompare(a,b);
    if (ret)
    {
        cout<<"a==b"<<endl;
    }
    else
    {
        cout<<"a!=b"<<endl;
    }
}
 //利用具体化Person的版本实现代码，具体化优先调用
 template<>bool myCompare(Person &p1, Person &p2)
 {
    if (p1.m_Name==p2.m_Name&&p1.m_Age==p2.m_Age)
    {
        return true;
    }
     else
    {
        return false;
    }
 }
void test05()
{
    Person p1("Tom", 18);
    Person p2("Marry", 18);
    bool ret=myCompare(p1, p2);   //报错，编译器无法识别Person数据类型
    if (ret)
    {
        cout<<"p1=p2"<<endl;
    }
    else
    {
        cout<<"p1!=p2"<<endl;
    }
}
int main()
{
    test05();
    system("pause");
    return 0;
}