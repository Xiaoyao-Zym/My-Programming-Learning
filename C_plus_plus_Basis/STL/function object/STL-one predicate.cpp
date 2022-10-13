#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//一元谓词
class GreatFive
{
public:
    bool operator()(int val)
    {
        return val>5;
    }
};
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //GreaterFive()   //匿名函数对象
    vector<int>::iterator it=find_if(v.begin(), v.end(), GreatFive());
    if (it==v.end())
    {
        cout<<"未找到"<<endl;
    }
    else
    {
        cout<<"已找到"<<*it<<endl;
    }    
}
int main()
{
    test01();
    system("pause");
    return 0;
}