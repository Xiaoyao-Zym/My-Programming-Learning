#include<vector>
#include<iostream>
using namespace std;
//��������
void printVector(vector<int>v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//1.����ʹ��
void test01()
{
    cout<<"����ǰ��"<<endl;
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int>v2;
    for (int i = 10; i >0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);
    cout<<"������"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//2.ʵ����;
//����swap���������ڴ�ռ�
void test02()
{
    vector<int>v3;
    for (int i = 0; i < 10000; i++)
    {
        v3.push_back(i);
    }
    cout<<"v3������Ϊ��"<<v3.capacity()<<endl;
    cout<<"v3�Ĵ�СΪ��"<<v3.size()<<endl;
    //����ָ����С
    v3.resize(3);
    cout<<"v3������Ϊ��"<<v3.capacity()<<endl;
    cout<<"v3�Ĵ�СΪ��"<<v3.size()<<endl;
    //����swap�����ڴ�
    vector<int>(v3).swap(v3);
    cout<<"v3������Ϊ��"<<v3.capacity()<<endl;
    cout<<"v3�Ĵ�СΪ��"<<v3.size()<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}