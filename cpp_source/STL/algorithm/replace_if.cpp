#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//�滻�㷨replace_if
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
    //��������
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(40);
     cout<<"�滻ǰ��"<<endl;
    for_each(v.begin(), v.end(), myPrint());
    cout<<"�滻��"<<endl;
    replace_if(v.begin(), v.end(), Greater(), 1000);
    for_each(v.begin(), v.end(), myPrint());
}
int main()
{
    test01();
    system("pause");
    return 0;
}