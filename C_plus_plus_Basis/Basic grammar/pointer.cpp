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
    //定义指针
    int a=10;
    int b=20;
    //常量指针指向的值不可以改，指向可以改。
   //  const int *p=&a;
    //指向a变量
  //  cout<<"a的地址为："<<p;

    //指针常量的指向不可以改，指向的值可以改
   // int *const p1=&a;
   // *p1=100;
   // cout<<' '<<*p1<<' '<<a<<endl;

    //const修饰指针和常量都不可修改
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