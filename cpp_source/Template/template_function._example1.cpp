#include<iostream>
#include<string>
using namespace std;
/*************����ģ��ʹ��ע������***********************
 * �Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
*ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
*��ͨ�����뺯��ģ������
*1.��ͨ�������Է�����ʽ����ת��
*2.����ģ�����Զ������Ƶ��������Է�����ʽ����ת��
*3. ����ģ������ʾָ�����ͣ����Է�����ʽ����ת��
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
    int a=10, b=20;
    char c='c';
    cout<<myAdd01(a, c)<<endl;  //��������ʽ����ת�����ַ��ͱ���ת��Ϊ���ͱ�����a=10, c-99, a+c=109
    //1. �Զ�����ת��
    // cout<<myAdd02(a, c)<<endl; //�����޷�������ʽ����ת��
    //2. ��ʾָ������
    cout<<myAdd02<int>(a, c)<<endl;   //������ʽ����ת��
 }
/************��ͨ�����뺯��ģ����ù���****************
**��ͨ�����ͺ���ģ�嶼����ʵ�֣����ȵ�����ͨ����
**����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
**����ģ����Է�������
**�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
**�ṩ�˺���ģ�壬��ò�ʹ����ͨ�������������׳��ֶ�����
*************************************************************/
int myPrint(int a, int b);
// {
//     return a+b;
// }
template<typename T>
T  myPrint(T a, T b)
{
    return a+b;
}
void test03()
{
    int a=10;
    int b=10;
    // cout<<"a+b="<<myPrint(a, b)<<endl;   //��ͨ�����ͺ���ģ�嶼����ʵ�֣����ȵ�����ͨ������������ͨ�����޶���
    // cout<<"a+b="<<myPrint<>(a, b)<<endl;  //ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
    char c1='a';
    char c2='c';
    cout<<"a+b="<<myPrint<>(a, b)<<endl;  // //�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
}
/***************************ģ��ľ�����*********************************
**ģ�岢�������ܵģ���Щ�ض��������ͣ���Ҫ�þ��廯��ʽ������ʵ��
/*************************************************************************/
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
   string m_Name;
   int m_Age;
};
template<typename T>
bool myCompare(T &a, T &b)
{
    if (a==b)
    {
        return true;
    }
    else
    {
        return  false;
    }
}
void test04()
{
    int a=10;
    int b=20;
    bool ret=myCompare(a,b);
    if (ret)
    {
        cout<<"a==b"<<endl;
    }
    else
    {
        cout<<"a!=b"<<endl;
    }
}
 //���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
 template<>bool myCompare(Person &p1, Person &p2)
 {
    if (p1.m_Name==p2.m_Name&&p1.m_Age==p2.m_Age)
    {
        return true;
    }
     else
    {
        return false;
    }
 }
void test05()
{
    Person p1("Tom", 18);
    Person p2("Marry", 18);
    bool ret=myCompare(p1, p2);   //�����������޷�ʶ��Person��������
    if (ret)
    {
        cout<<"p1=p2"<<endl;
    }
    else
    {
        cout<<"p1!=p2"<<endl;
    }
}
int main()
{
    test05();
    system("pause");
    return 0;
}