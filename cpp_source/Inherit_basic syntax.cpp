#include<iostream>
using namespace std;
//��ͨʵ��ҳ��
//javaҳ��
// class  Java
// {
// public:
//     void header()
//     {
//         cout<<"��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����"<<endl;
//     }
//     void foooter()
//     {
//         cout<<"�������ġ�����������վ�ڵ�ͼ������������"<<endl;
//     }
//     void left()
//     {
//         cout<<"Java��Python��C++���������������б�"<<endl;
//     }
//     void content()
//     {
//         cout<<"Javaѧ����Ƶ"<<endl;
//     }
// };
// //Pythonҳ��
// class  Python
// {
// public:
//     void header()
//     {
//         cout<<"��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����"<<endl;
//     }
//     void foooter()
//     {
//         cout<<"�������ġ�����������վ�ڵ�ͼ������������"<<endl;
//     }
//     void left()
//     {
//         cout<<"Java��Python��C++���������������б�"<<endl;
//     }
//     void content()
//     {
//         cout<<"Pythonѧ����Ƶ"<<endl;
//     }
// };
// //C++ҳ��
// class  CPP
// {
// public:
//     void header()
    // {
    //     cout<<"��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����"<<endl;
    // }
    // void foooter()
    // {
    //     cout<<"�������ġ�����������վ�ڵ�ͼ������������"<<endl;
    // }
    // void left()
    // {
    //     cout<<"Java��Python��C++���������������б�"<<endl;
    // }
    // void content()
    // {
    //     cout<<"C++ѧ����Ƶ"<<endl;
    // }
// };
//�̳�ʵ��ҳ��
//�̳п��Լ����ظ�����
//�﷨��class ���ࣨ�����ࣩ���̳з�ʽ ���ࣨ���ࣩ
//����ҳ����
class BasePage
{
public:
    void header()
    {
        cout<<"��ҳ�������Ρ���¼��ע�ᡭ��������ͷ����"<<endl;
    }
    void foooter()
    {
        cout<<"�������ġ�����������վ�ڵ�ͼ������������"<<endl;
    }
    void left()
    {
        cout<<"Java��Python��C++���������������б�"<<endl;
    }
};
//Javaҳ��
class Java : public BasePage
{
public:
   void content()
    {
        cout<<"Javaѧ����Ƶ"<<endl;
    }
};
//Pythonҳ��
class Python : public BasePage
{
public:
   void content()
    {
        cout<<"Pythonѧ����Ƶ"<<endl;
    }
};
//C++ҳ��
class CPP : public BasePage
{
public:
   void content()
    {
        cout<<"C++ѧ����Ƶ"<<endl;
    }
};
void test01()
{
    cout<<"Java������Ƶҳ��"<<endl;
    Java ja;
    ja.header();
    ja.foooter();
    ja.left();
    ja.content();
    cout<<"--------------------"<<endl;
    cout<<"Python������Ƶҳ��"<<endl;
    Python py;
    py.header();
    py.foooter();
    py.left();
    py.content();
    cout<<"--------------------"<<endl;
    cout<<"C++������Ƶҳ��"<<endl;
    CPP cpp;
    cpp.header();
    cpp.foooter();
    cpp.left();
    cpp.content();
    cout<<"--------------------"<<endl;
 }
int main()
{
    test01();
    system("pause");
    return 0;
}