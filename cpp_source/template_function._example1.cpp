#include<iostream>
using namespace std;
  /*************************************************************
**����ģ��ʹ��ע������
**�Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
**ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
**��ͨ�����뺯��ģ������
**1.��ͨ�������Է�����ʽ����ת��
**2.����ģ�����Զ������Ƶ��������Է�����ʽ����ת��
**3. ����ģ������ʾָ�����ͣ����Է�����ʽ����ת��
*************************************************************/
//��ͨ����
int myAdd01(int a, int b)
{
    return a+b;
}
template<typename T>  //typename�����滻��class
void mySwap(T&a, T&b)
{
    T temp=a;
    a=b;
    b=temp;
}
 void test01()
 {
    int a=10;
    int b=20;
    char c='c';
    mySwap(a, b);
    // mySwap(a,c);  �����Ƶ�����һ�µ�T����
    cout<<"a="<<a<<"b="<<b<<endl;
 }
 //����ģ��
 template<typename T>  
 void func()
 {
     cout<<"func����"<<endl;
 }
  template<typename T>  
  T myAdd02(T a, T b)
  {
      return a+b;
  }
 void test02()
 {
    //  func(); δָ��ģ����T����������
    func<int>(); 
    int a=10,b=20;
    char c='c';
    cout<<myAdd01(a, c)<<endl;  //��������ʽ����ת�����ַ��ͱ���ת��Ϊ���ͱ�����a=10, c-99, a+c=109
    //1. �Զ�����ת��
    // cout<<myAdd02(a, c)<<endl; //�����޷�������ʽ����ת��
    //2. ��ʾָ������
    cout<<myAdd02<int>(a, c)<<endl;   //������ʽ����ת��
 }
int main()
{
    test02();
    system("pause");
    return 0;
}