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
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //降序
    //sort(v.begin(), v.end(), MyCompare)；
    //greater<int>() 内建函数
    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
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