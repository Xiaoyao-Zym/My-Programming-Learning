#include<iostream>
using namespace std;
//����ģ��
//������������
/************************************************************************
*template----��������ģ��
*typename----���������ķ�����һ���������ͣ�������class����
*T----ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
*************************************************************************/
// //�����������͵ĺ���
// void swapInt (int &a, int &b)
// {
//     int temp=a;
//     a=b;
//     b=temp;
// }
// //�������������͵ĺ���
// void swapDouble (double &a, double &b)
// {
//     double temp=a;
//     a=b;
//     b=temp;
// }
template<typename T> //����ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ����������
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
    //���ú���ģ�彻��
    //1.�Զ������Ƶ�
    // mySwap(a, b);
    //2.��ʾָ������
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