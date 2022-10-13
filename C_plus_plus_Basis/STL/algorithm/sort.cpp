#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//常用排序算法：sort
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v;
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(10);
    //利用sort升序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
    //降序
    sort(v.begin(), v.end(), greater<int>());
}
int main()
{
    test01();
    system("pause");
    return 0;
}