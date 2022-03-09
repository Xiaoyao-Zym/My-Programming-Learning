#include<iostream>
#include<set>
using namespace std;
//pair对组的创建
void test()
{
    //第一种方式
    pair<string,int>p1("Ton", 20);
    cout<<"姓名："<<p1.first<<"年龄："<<p1.second<<endl;
    //第二种方式
    pair<string, int>p2=make_pair("jenrry", 10);
    cout<<"姓名："<<p2.first<<"年龄："<<p2.second<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}