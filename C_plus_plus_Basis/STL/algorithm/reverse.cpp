#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//���������㷨 merge
void myPrint (int val)
{
        cout<<val<<" ";
}
//reverse�㷨
void test01()
{
    vector<int>v1;
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(10);
    cout<<"��תǰ��"<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<"��ת��"<<endl;
    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), myPrint);
}
int main()
{
    test01();
    system("pause");
    return 0;
}