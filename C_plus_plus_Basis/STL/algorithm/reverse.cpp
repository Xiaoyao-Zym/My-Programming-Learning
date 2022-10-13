#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//常用排序算法 merge
void myPrint (int val)
{
        cout<<val<<" ";
}
//reverse算法
void test01()
{
    vector<int>v1;
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(10);
    cout<<"反转前："<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<"反转后："<<endl;
    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), myPrint);
}
int main()
{
    test01();
    system("pause");
    return 0;
}