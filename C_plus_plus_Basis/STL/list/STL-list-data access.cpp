#include<iostream>
#include<list>
using namespace std;
//list���������ɾ��
void printList(const list<int>&L)
{
    for (list<int>:: const_iterator  it=L.begin(); it!=L.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
     list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //L1(0)   ��������[]����list�����е�Ԫ��
    //L1.at(0);   ��������at��ʽ����list�����е�Ԫ��
    //ԭ����list�������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�
    cout<<"��һ��Ԫ��Ϊ��"<<L1.front()<<endl;
    cout<<"���һ��Ԫ��Ϊ��"<<L1.back()<<endl;
    //��֤�������ǲ�֧���������
    list<int>::iterator it=L1.begin();
    //it=it+2;  ����
    it++;      //��ȷ
    it--;       //��֧���������
}
int main()
{
    test();
    system("pause");
    return 0;
}