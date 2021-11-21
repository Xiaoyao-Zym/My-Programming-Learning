#include<iostream>
using namespace std;
//设计一个立方体类，求立方体的表面积和体积
class Cude
{
private: 
    //属性
    //长、宽、高
    int m_L;
    int m_W;
    int m_H;
public:
    //获取立方体属性
    void setL(int L)
    {
        m_L=L;
    }
    int getL()
    {
        return m_L;
    }
    void setW(int W)
    {
        m_W=W;
    }
    int getW()
    {
        return m_W;
    }
    void setH(int H)
    {
        m_H=H;
    }
    int getH()
    {
        return m_H;
    }
    //获取立方体的表面积
    int  Cube_square()
    {
        return (m_H*m_L+m_H*m_W+m_L*m_W)*2;
    }
    //获取立方体的体积
    int  Cub_volume()
    {
        return (m_W*m_L*m_H);
    }
};

int main()
{
    //创建立方体对象
    Cude c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);
    cout<< "表面积："<<c1.Cube_square()<<endl;
    cout<<"体积："<<c1.Cub_volume()<<endl;
    system("pause");
}