#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
class Print
{
public:
    int operator()(int v)
    {
        return v;
    }
};
class Myprint
{
public:
    void operator()(int val)
    {
        cout<<val<<" ";
    }
};
void test()
{
    vector<int>v;
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    transform(v.begin(),v.end(), v1.begin(), Print());
    for_each(v1.begin(), v1.end(), Myprint());  
}
int main()
{
    test();
    system("pause");
    return 0;
}