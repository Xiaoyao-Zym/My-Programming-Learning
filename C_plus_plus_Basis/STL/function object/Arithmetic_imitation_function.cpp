#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
//内建函数对象，算术仿函数
//negate  一元仿函数 ，取反 仿函数
void test()
{
    negate<int>n;
    cout<<n(50)<<endl;
}
//plus 二元仿函数  加法
void test01()
{
    plus<int>p;
    cout<<p(2, 3)<<endl;
}
int main()
{
    test01();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    system("pause");
    return 0;
}