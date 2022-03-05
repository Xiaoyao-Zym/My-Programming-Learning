#include<iostream>
using namespace std;
//设计一个圆类，求圆的周长
#define PI 3.14
class Circle
{
public:
    //属性
    //半径
    int m_r;
    //行为
    //获取圆的周长
    double calculateZC()
    {
        return 2*PI*m_r;
    }
};

int main()
{
    //通过圆类创建对象
    Circle c1;
    //绘制对象属性，并赋值
    c1.m_r=10;
    cout<<"圆的周长："<<c1.calculateZC()<<endl;
    system("pause");
    return 0;
}