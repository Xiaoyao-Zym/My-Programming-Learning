#include<iostream>
using namespace std;
void swap01(int a, int b)
{
    int temp=a;
    a=b;
    b=temp;
    cout<<"swap01a="<<a<<endl;
    cout<<"swap01b="<<b<<endl;
}
void swap02(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    cout<<"swap02a="<<*a<<endl;
    cout<<"swap02b="<<*b<<endl;
}
int main()
{
    //����ָ��
    int a=10;
    int b=20;
    //����ָ��ָ���ֵ�����Ըģ�ָ����Ըġ�
   //  const int *p=&a;
    //ָ��a����
  //  cout<<"a�ĵ�ַΪ��"<<p;

    //ָ�볣����ָ�򲻿��Ըģ�ָ���ֵ���Ը�
   // int *const p1=&a;
   // *p1=100;
   // cout<<' '<<*p1<<' '<<a<<endl;

    //const����ָ��ͳ����������޸�
   // const int *const p2=&a;
   // cout<<sizeof(p2)<<endl;
   swap01(a,b);
    cout<<"a="<<a<<endl;
   cout<<"b="<<b<<endl;
   swap02(&a, &b);
   cout<<"a="<<a<<endl;
   cout<<"b="<<b<<endl;

    system("pause");
}