#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//常用拷贝和替换算法
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
    }
    cout<<"交换前"<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<"交换后"<<endl;
    swap(v1, v2);
    cout<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    for_each(v2.begin(), v2.end(), myPrint);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
