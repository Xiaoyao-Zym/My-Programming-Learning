#include<iostream>
#include<vector>
using namespace std;
//vector�������ݴ�ȡ
void printVector(vector<int>v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    printVector(v);
    //����[]��ʽ��������Ԫ��
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //����at��ʽ����Ԫ��
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
    //���ʵ�һ��Ԫ��
    cout<<"��һ��Ԫ��Ϊ��"<<v.front()<<endl;
    //��ȡ���һ��Ԫ��
    cout<<"���һ��Ԫ��Ϊ��"<<v.front()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}