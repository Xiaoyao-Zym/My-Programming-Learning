#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
//���ü����㷨 set_nuion���󲢼�
void myPrint(int val)
{
    cout<<val<<" ";
}
void test()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);   //0~9
        v2.push_back(i+5);  //5~14
    }
    vector<int>vTarget;
    //Ŀ��������Ҫ��ǰ���ٿռ�
    //������������������޽���������sizeΪ����֮�͡�
    vTarget.resize(v1.size()+v2.size());
    //��ȡ����
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end
    (),vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);
    cout<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}