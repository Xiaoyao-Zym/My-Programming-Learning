#include<iostream>
#include<set>
using namespace  std;
void printSet(set<int>&s)
{
    for (set<int>::iterator it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    set<int>s;
    //²åÈë
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    //±éÀú
    printSet(s);
    //É¾³ı
    s.erase(s.begin());
    printSet(s);
    //É¾³ıÖØÔØ°æ±¾
    s.erase(30);
    printSet(s);
    //Çå¿Õ
    //s.erase(s.begin(), s.end());
    s.clear();
    printSet(s);
}
int main()
{
    test();
    system("pause");
    return 0;
}