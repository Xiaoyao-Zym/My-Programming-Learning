#include<iostream>
using namespace std;
//���һ��Բ�࣬��Բ���ܳ�
#define PI 3.14
class Circle
{
public:
    //����
    //�뾶
    int m_r;
    //��Ϊ
    //��ȡԲ���ܳ�
    double calculateZC()
    {
        return 2*PI*m_r;
    }
};

int main()
{
    //ͨ��Բ�ഴ������
    Circle c1;
    //���ƶ������ԣ�����ֵ
    c1.m_r=10;
    cout<<"Բ���ܳ���"<<c1.calculateZC()<<endl;
    system("pause");
    return 0;
}