#include<iostream>
using namespace std;
//��Ա�����ͱ����Ƿֿ��洢
 class Person
{
public:
    int m_A;                //�Ǿ�̬��Ա������������Ķ�����
    static int m_B;      // ��̬��Ա�������������������
    void func()           //�Ǿ�̬��Ա�������������������
    {

    }
    static void func2()    //
    {

    }

};
void test01()
{
    Person p;
    //�ն���ռ���ڴ�ռ䣺1
    //C++����Ϊÿ���ն������һ���ֽڿռ䣬��Ϊ�����ֿն���ռ���ڴ��λ��
    //ÿ���ն���ҲӦ����Ψһ��ַ
    cout<<"size of p="<<sizeof(p)<<endl;
}
void test02()
{
    Person p1;
    cout<<"size of p1="<<sizeof(p1)<<endl;
}
 int main()
{
    test02();
    system("pause");
    return 0;
}