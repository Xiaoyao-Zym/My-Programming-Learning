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
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for (vector<bool>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //�����߼��ǡ�������v���˵�����v2�У���ִ��ȡ������
    vector<bool>v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), v.end(), logical_not<bool>());
    for (vector<bool>::iterator it=v.begin(); it!=v.end(); it++)
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