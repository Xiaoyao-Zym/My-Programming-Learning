#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>&v)
{
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//vector����f��ֵ
void test()
{
   vector<int>v1;                 //Ĭ�Ϲ���
   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
   }
   printVector(v1);
   //operator=��ֵ
   vector<int>v2=v1;
    printVector(v2);
    //ͨ��assign��ʽ��ֵ
    vector<int>v3;
    v3.assign(v2.begin(), v2.end());       //Ϊ����ҿ�����
    printVector(v3);
    //��������
    vector<int>v4;
    v4.assign(10, 9);;
    printVector(v4);
}
int main()
{
    test();
    system("pause");
    return 0;
}