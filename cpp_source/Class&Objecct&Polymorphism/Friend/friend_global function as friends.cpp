#include<iostream>
#include<string>
using namespace std;
//建筑物类
class  Buiding
{
    //girlfriend全局函数是Building好朋友，可以访问Building中私有成员
     friend void girlfriend(Buiding *building);
public:
     string m_SittingRoom; //客厅
public:
     Buiding()
    {
        m_SittingRoom="客厅";
        m_BedRoom="卧室";
    }
private:
    string m_BedRoom;     //卧室
};
//全局函数
void girlfriend(Buiding *building)
{
    cout<<"女朋友正在进入"<<building->m_SittingRoom <<endl;
    cout<<"女朋友正在进入"<<building->m_BedRoom <<endl;
}
void test()
{
    Buiding building;
    girlfriend(&building);
}
int main()
{
    test();
    system("pause");
    return 0;
}