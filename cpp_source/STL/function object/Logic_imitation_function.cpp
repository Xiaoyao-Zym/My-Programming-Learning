#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//内建函数对象，_算术仿函数
//大于 greater
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1>v2;
    }
};
void test()
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for (vector<bool>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //利用逻辑非、将容器v搬运到容器v2中，并执行取反操作
    vector<bool>v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), v.end(), logical_not<bool>());
    for (vector<bool>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    test();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    system("pause");
    return 0;
}