#include<iostream>
#include<math.h>
using namespace std;
//设计一个圆形类，一个点类，计算其位置关系
class Point
{
private:
    //点坐标
    int m_X;
    int m_Y;
public:
     void setPoint_X(int x)
    {
        m_X=x;
    }
     int  getPoint_X()
    {
        return m_X;
    }
     void setPoint_Y(int y)
    {
        m_Y=y;
    }
    int  getPoint_Y()
    {
        return m_Y;
    }
};
class Circle
{
private:
    //属性
    //半径
    int m_r;
    Point m_Circle_center;
public:
    //行为
    //设置圆的半径
    void setCircle_R(int r)
    {
        m_r=r;
    }
    //获取圆的半径
    int  getCircle_R()
    {
        return  m_r;
    }
    //设置圆心坐标
    void setCircle_center(Point center)
    {
        m_Circle_center=center;
    }
    //获取圆心坐标
    Point getCircle_center()
    {
        return m_Circle_center;
    }
};
//判断点和圆的关系
void isCircle(Circle &c1,  Point &c2)
{
    if((pow((c1.getCircle_center().getPoint_X()-c2.getPoint_X()),2)+pow((c1.getCircle_center().getPoint_Y()-c2.getPoint_Y()),2))!=pow(c1.getCircle_R(), 2)) 
    {
        if((pow((c1.getCircle_center().getPoint_X()-c2.getPoint_X()),2)+pow((c1.getCircle_center().getPoint_Y()-c2.getPoint_Y()),2))>pow(c1.getCircle_R(), 2)) 
        {
            cout<<"点在圆外"<<endl;
        }
        else
        {
            cout<<"点在圆内"<<endl;
        }

    }
    else
    {
        cout<<"点在圆上"<<endl;
    }
      
}
int main()
{
    //创建圆类对象，并赋值
    Circle c1;
    c1.setCircle_R(5);
    Point center;
    center.setPoint_X(10);
    center.setPoint_Y(10);
    c1.setCircle_center(center);
    //创建点类对象，并赋值
    Point c2;
    c2.setPoint_X(9);
    c2.setPoint_Y(9);
    isCircle(c1, c2);
    system("pause");
    return 0;
}