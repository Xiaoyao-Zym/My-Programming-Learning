#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//���������㷨 merge
class myPrint
{
public:
    void operator() (int val)
   {
        cout<<val<<" ";
   }
};
void  test01()
{
    vector<int>v1;
    vector<int>v2;
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    vector<int>vTarget;
    //��ǰ��Ŀ����������ռ�
    vTarget.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), myPrint());
}
int main()
{
    test01();
    system("pause");
    return 0;
}