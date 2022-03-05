#include<iostream>
#include<string>
using namespace std;
//类做友元
class Building;
class Girlfriend
{
public:
    void visit();  //参观函数  访问Building中的属性
    Building *building;
    Girlfriend();
};
class Building
{
    //Girlfriend作为友元
    friend class Girlfriend;
public:
    Building();
    string m_SittingRoom; //客厅
private:
    string m_Bedroom;      //卧室
};
//类外写成员函数
Building::Building()
{
    m_SittingRoom="客厅";
    m_Bedroom="卧室";
}
Girlfriend::Girlfriend()
{
    //创建建筑物对象
    building= new Building;
}
void Girlfriend::visit()
{
    cout<<"女朋友正在进入："<<building->m_SittingRoom <<endl;   
    cout<<"女朋友正在进入："<<building->m_Bedroom <<endl; 
}
void test()
{
    Building building;
    Girlfriend p;
    p.visit();
}
int main()
{
    test();
    system("pause");
    return 0;
}