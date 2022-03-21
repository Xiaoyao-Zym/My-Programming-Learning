#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
//常用算术生成算法
void test01()
{
    vector<int>v;
    for (int i = 1; i < 101; i++)
    {
        v.push_back(i);
    }
    int total=accumulate(v.begin(),v.end(), 0);
    cout<<"total="<<total<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}