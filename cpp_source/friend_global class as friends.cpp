#include<iostream>
#include<string>
using namespace std;
//������Ԫ
class Building;
class Girlfriend
{
public:
    void visit();  //�ιۺ���  ����Building�е�����
    Building *building;
    Girlfriend();
};
class Building
{
    //Girlfriend��Ϊ��Ԫ
    friend class Girlfriend;
public:
    Building();
    string m_SittingRoom; //����
private:
    string m_Bedroom;      //����
};
//����д��Ա����
Building::Building()
{
    m_SittingRoom="����";
    m_Bedroom="����";
}
Girlfriend::Girlfriend()
{
    //�������������
    building= new Building;
}
void Girlfriend::visit()
{
    cout<<"Ů�������ڽ��룺"<<building->m_SittingRoom <<endl;   
    cout<<"Ů�������ڽ��룺"<<building->m_Bedroom <<endl; 
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