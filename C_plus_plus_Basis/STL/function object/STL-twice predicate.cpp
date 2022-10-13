#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//二元谓词
class myCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1>val2;
    }
};
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    //GreaterFive()   //匿名函数对象
   sort(v.begin(), v.end(), myCompare());
   for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
   {
       cout<<*it<<" ";
   }
   cout<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}