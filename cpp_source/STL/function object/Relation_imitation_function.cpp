#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//�ڽ���������_�����º���
//���� greater
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
    //����
    //sort(v.begin(), v.end(), MyCompare)��
    //greater<int>() �ڽ�����
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