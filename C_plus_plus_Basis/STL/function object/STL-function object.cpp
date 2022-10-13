#include<iostream>
using namespace std;
//函数对象使用
/*特点：
-函数对象在使用，可以像普通函数那样调用，可以有参数，可以返回值
-函数对象超出普通函数的概念，函数对象可以有自己的状态
-函数对象可以作为参数传递
*/
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return  v1+v2;
    }
};
//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
    MyAdd myadd;
    cout<<myadd(10, 10)<<endl;
}
//2. 函数对象超出普通函数的概念，可以有自己的状态
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
    int count;  //内部状态
};
void test02()
{
    myPrint myprint;
    myprint("hello world");
    myprint("hello world");
    cout<<"myprint调用次数"<<myprint.count<<endl;
}
//函数对象可以作为参数传递
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