#include<iostream>
using namespace std;
//��������ʹ��
/*�ص㣺
-����������ʹ�ã���������ͨ�����������ã������в��������Է���ֵ
-�������󳬳���ͨ�����ĸ����������������Լ���״̬
-�������������Ϊ��������
*/
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return  v1+v2;
    }
};
//1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test01()
{
    MyAdd myadd;
    cout<<myadd(10, 10)<<endl;
}
//2. �������󳬳���ͨ�����ĸ���������Լ���״̬
class myPrint
{
public:
     myPrint()
     {
         this->count=0;
     }
    void operator()(string test)
    {
        cout<<test<<endl;
        this->count++;
    }
    int count;  //�ڲ�״̬
};
void test02()
{
    myPrint myprint;
    myprint("hello world");
    myprint("hello world");
    cout<<"myprint���ô���"<<myprint.count<<endl;
}
//�������������Ϊ��������
void doPrint(myPrint &mp, string test)
{
    mp(test);
}
void test03()
{
    myPrint myprint;
    doPrint(myprint,"hello c++");
}
int main()
{
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}