#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�滻�㷨replace
class myPrint
{
public:
    void operator() (int val)
   {
        cout<<val<<" ";
   }
};
void test01()
{
    vector<int>v1;
    v1.push_back(40);
    v1.push_back(20);
    v1.push_back(20);
    v1.push_back(10);
    cout<<"�滻ǰ��"<<endl;
    for_each(v1.begin(), v1.end(), myPrint());
    cout<<"�滻��"<<endl;
    replace(v1.begin(), v1.end(), 20, 1000);
    for_each(v1.begin(), v1.end(), myPrint());
}
int main()
{
    test01();
    system("pause");
    return 0;
}