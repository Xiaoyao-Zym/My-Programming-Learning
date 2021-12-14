#include<iostream>
using namespace std;
//重载递增运算符
//前置递增返回引用，后置递增返回值
class MyInteger
{
   friend ostream& operator<<(ostream&cout, MyInteger myit);
public:
   MyInteger()
   {
       m_Num = 0;
   }
   //重载前置++运算符，返回引用是为一直对一个数值操作
   MyInteger &operator++()
   {
      //先进行++运算
       m_Num++;
       return *this;
   }
  // 重载后置++
   MyInteger operator++(int) //int用于区分前置和后置递增
   {
        //先记录结果
       MyInteger  temp=*this;
       m_Num++;
       //再返回
       return temp;
   }
private:
   int m_Num;
};
//重载<<运算符
ostream& operator<<(ostream& cout, MyInteger myit)
{
    cout<<myit.m_Num<<endl;
    return cout;
}
void test01()
{
    MyInteger myint;
    cout<<++myint<<endl;
}
void test02()
{
    MyInteger myint;
    cout<<myint++<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}