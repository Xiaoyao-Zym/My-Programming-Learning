#include<iostream>
#include<vector>
using namespace std;
//vector �����Ĳ�����ɾ��
/*
*push_back(else);                           //β������Ԫ��ele
*pop_back();                                  //ɾ�����һ��Ԫ��
*insert(const_itrerator pos, ele);   //������ָ��λ��pos����Ԫ��ele
*insert(const_iterator pos, int count,ele); //������ָ��λ��pos����count��Ԫ��ele
*errase(const_iterator pos);        //ɾ����������Ԫ��
*erase(const_iterrator start, const_iterator end); //ɾ����������start��end֮���Ԫ��
*clear();
*/
void printVector(vector<int>&v)
{
    for (vector<int>:: iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    vector<int>v1;
    //β�巨��ʼ������
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    //βɾ��
    v1.pop_back();
    printVector(v1);
    //β����  ��һ�������ǵ�����
    v1.insert(v1.begin(), 2, 100);
    printVector(v1);
    //ɾ��   ����Ҳ�ǵ�����
    v1.erase(v1.begin());
    printVector(v1);
    //�������
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}
int main()
{
    test();
    system("pause");
    return 0;
}