#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//adjacent_find
void test()
{
    vector<int>v;
    //创建数据
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    vector<int>::iterator it=adjacent_find(v.begin(), v.end());
    if (it==v.end())
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到元素："<<*it<<endl;
    }
}
int main()
{
    test();
    system("pause");
    return 0;
}