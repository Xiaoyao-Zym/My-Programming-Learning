#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//���������㷨��sort
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
    //����sort����
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
    //����
    sort(v.begin(), v.end(), greater<int>());
}
int main()
{
    test01();
    system("pause");
    return 0;
}