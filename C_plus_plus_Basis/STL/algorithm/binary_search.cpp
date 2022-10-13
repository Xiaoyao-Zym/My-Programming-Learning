#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//binary_search
void test()
{
    vector<int>v;
    //创建数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    bool it=binary_search(v.begin(), v.end(), 20);
    if (it)
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<"找到元素："<<endl;
    }
}
int main()
{
    test();
    system("pause");
    return 0;
}