#include<iostream>
using namespace std;
//���һ���������࣬��������ı���������
class Cude
{
private: 
    //����
    //��������
    int m_L;
    int m_W;
    int m_H;
public:
    //��ȡ����������
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
    //��ȡ������ı����
    int  Cube_square()
    {
        return (m_H*m_L+m_H*m_W+m_L*m_W)*2;
    }
    //��ȡ����������
    int  Cub_volume()
    {
        return (m_W*m_L*m_H);
    }
};

int main()
{
    //�������������
    Cude c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);
    cout<< "�������"<<c1.Cube_square()<<endl;
    cout<<"�����"<<c1.Cub_volume()<<endl;
    system("pause");
}