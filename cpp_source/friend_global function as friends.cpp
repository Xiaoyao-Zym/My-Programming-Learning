#include<iostream>
#include<string>
using namespace std;
//��������
class  Buiding
{
    //girlfriendȫ�ֺ�����Building�����ѣ����Է���Building��˽�г�Ա
     friend void girlfriend(Buiding *building);
public:
     string m_SittingRoom; //����
public:
     Buiding()
    {
        m_SittingRoom="����";
        m_BedRoom="����";
    }
private:
    string m_BedRoom;     //����
};
//ȫ�ֺ���
void girlfriend(Buiding *building)
{
    cout<<"Ů�������ڽ���"<<building->m_SittingRoom <<endl;
    cout<<"Ů�������ڽ���"<<building->m_BedRoom <<endl;
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