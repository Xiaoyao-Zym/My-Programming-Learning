#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//���ñ����㷨 for_each
//��ͨ����
void print01(int val)
{
    cout<<val<<" ";
}
//�º���
class print02
{
public:
    void operator()(int val)
    {
        cout<<val<<endl;
    }
};
void test()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout<<endl;
    for_each(v.begin(), v.end(), print01);
    cout<<endl;
    for_each(v.begin(), v.end(), print02());
}
int main()
{
    test();
    system("pause");
    return 0;
}