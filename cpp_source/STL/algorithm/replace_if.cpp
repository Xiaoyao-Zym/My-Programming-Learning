#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//替换算法replace_if
class myPrint
{
public:
    void operator() (int val)
   {
        cout<<val<<" ";
   }
};
class Greater
{
public:
    bool operator()(int val)
    {
        return val>20;
    }
};
void test01()
{
        vector<int>v;
    //创建数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(40);
     cout<<"替换前："<<endl;
    for_each(v.begin(), v.end(), myPrint());
    cout<<"替换后："<<endl;
    replace_if(v.begin(), v.end(), Greater(), 1000);
    for_each(v.begin(), v.end(), myPrint());
}
int main()
{
    test01();
    system("pause");
    return 0;
}