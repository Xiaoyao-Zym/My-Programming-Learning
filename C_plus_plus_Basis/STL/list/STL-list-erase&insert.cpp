#include<iostream>
#include<list>
using  namespace std;
//list���������ɾ��
/**
* push_back(elem);                  //������β������һ��Ԫ��
* pop_back();                          //ɾ�����������һ��Ԫ��
* push_front(elem);                //��������ͷ����һ��Ԫ��
* pop_front();                         //��������ͷ�Ƴ���һ��Ԫ��
*  insert(pos, elem);               //��posλ�ò�elemԪ�صĿ��������������ݵ�λ��
*  insert(pos, n, elem);           //��posλ�ò���n��elem���ݣ��޷���ֵ
*  insert(pos, beg, end);        //��posλ�ò���[beg, end]��������ݣ��޷���ֵ
*  clear();                               //�Ƴ���������������
*  erase(beg, end);                //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
*  erase(pos);                        //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
*  remove(elem);                 //ɾ��������������elemֵƥ���Ԫ��  
*/
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
    //β��
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //β��
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);
    L1.push_front(400);
    printList(L1);
    //βɾ
    L1.pop_back();
    //300, 200, 100, 10, 20
    printList(L1);
    //ͷɾ
    L1.pop_front();
    printList(L1);
    //insert����
    list<int>:: iterator  it=L1.begin();
    L1.insert(++it, 1000);
    L1.insert(L1.begin(), 1000);
    //1000  200  100  10  20
    printList(L1);
    //ɾ��
    it=L1.begin();
    L1.erase(it);
    //200 100 10  20
    printList(L1);
    //�Ƴ�
    L1.push_back(10000);
    printList(L1);
    L1.remove(1000);
    //���
    L1.clear();
    printList(L1);
}
int main()
{
    test();
    system("pause");
    return 0;
}