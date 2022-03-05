#include<iostream>
using namespace std;
int &test01()
{
    int a =10;
    return a;
}
int&  test02()
{
    static int a=10;
    return a;
}
int main()
{
    int &ref1= test01();
    int &ref2= test02();
    test02()=1000;
    cout<<"ref="<<ref2<<endl;
    system("pause");
}