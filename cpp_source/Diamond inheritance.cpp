#include<iostream>
using namespace std;
//���μ̳У�����������̳�ͬһ�����࣬����ĳͬʱ�̳�������������
//������
class Animal
{
public:
    int m_Age;
};
//������̳� ������μ̳е�����
//�̳�֮ǰ ���Ϲؼ��� virtual ��Ϊ��̳�
//Animal���Ϊ�����
//����
class Sheep: virtual public Animal
{
public:
};
//����
class Tuo :virtual public Animal
{
public:
};
//����

class SheepTuo:public Sheep, public Tuo
{

};
void test01()
{
    SheepTuo st;
    st.Sheep::m_Age=18;
    st.Tuo::m_Age=28;
    //�����μ̳У���������ӵ����ͬ���ݣ���Ҫ��������������
    cout<<"st.Sheep::m_Age="<<st.Sheep::m_Age<<endl;
    cout<<"st.Tuo::m_Age="<<st.Tuo::m_Age<<endl;
    cout<<"st.m_Age="<<st.m_Age<<endl;
    //�����������֪����ֻ��һ�ݾͿ��ԣ����μ̳е������������ݣ���Դ�˷�
}
int main()
{
    test01();
    system("pause");
    return 0;
}