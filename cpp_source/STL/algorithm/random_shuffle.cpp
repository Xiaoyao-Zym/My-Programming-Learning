#include<iostream>
#include<time.h>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//���������㷨��random_shuffle
void myPrint(int val)
{
    cout<<val<<" ";
}
void test01()
{
    srand((unsigned int)time(NULL));
    vector<int>v;
    for(int i=0; i<10; i++)
    {
        v.push_back(i);
    }
    //����ϴ�ơ��㷨������˳��
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
    //����
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}