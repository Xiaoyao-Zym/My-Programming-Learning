#include<iostream>
#include<math.h>
using namespace std;
//���һ��Բ���࣬һ�����࣬������λ�ù�ϵ
class Point
{
private:
    //������
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
    //����
    //�뾶
    int m_r;
    Point m_Circle_center;
public:
    //��Ϊ
    //����Բ�İ뾶
    void setCircle_R(int r)
    {
        m_r=r;
    }
    //��ȡԲ�İ뾶
    int  getCircle_R()
    {
        return  m_r;
    }
    //����Բ������
    void setCircle_center(Point center)
    {
        m_Circle_center=center;
    }
    //��ȡԲ������
    Point getCircle_center()
    {
        return m_Circle_center;
    }
};
//�жϵ��Բ�Ĺ�ϵ
void isCircle(Circle &c1,  Point &c2)
{
    if((pow((c1.getCircle_center().getPoint_X()-c2.getPoint_X()),2)+pow((c1.getCircle_center().getPoint_Y()-c2.getPoint_Y()),2))!=pow(c1.getCircle_R(), 2)) 
    {
        if((pow((c1.getCircle_center().getPoint_X()-c2.getPoint_X()),2)+pow((c1.getCircle_center().getPoint_Y()-c2.getPoint_Y()),2))>pow(c1.getCircle_R(), 2)) 
        {
            cout<<"����Բ��"<<endl;
        }
        else
        {
            cout<<"����Բ��"<<endl;
        }

    }
    else
    {
        cout<<"����Բ��"<<endl;
    }
      
}
int main()
{
    //����Բ����󣬲���ֵ
    Circle c1;
    c1.setCircle_R(5);
    Point center;
    center.setPoint_X(10);
    center.setPoint_Y(10);
    c1.setCircle_center(center);
    //����������󣬲���ֵ
    Point c2;
    c2.setPoint_X(9);
    c2.setPoint_Y(9);
    isCircle(c1, c2);
    system("pause");
    return 0;
}