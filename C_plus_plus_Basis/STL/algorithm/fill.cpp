#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
//�������������㷨 fill
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    vector<int>v;
    v.resize(10);
    //�����������
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), myPrint);
}
int main()
{
    test01();
    system("pause");
    return 0;
}