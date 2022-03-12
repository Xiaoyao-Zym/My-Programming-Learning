#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#define  Scheme     0
#define  Fine_arts   1
#define  Research_development  2
using namespace std;
class Employee
{
public:
    Employee(string name, int salary)
    {
        this->m_Name=name;
        this->m_Salary=salary;
    }
    string m_Name;
    int  m_Salary;
};
//����Ա��
void creat_employee(vector<Employee>&v)
{
    string nameSeed="ABCDEFGHJK";
    for (int i = 0; i < 10; i++)
    {
        string name="Ա����";
        name+=nameSeed[i];
        int salary=rand()%5000+10000;   //10000~149999
        Employee e(name,salary);
        v.push_back(e);
    }
}
//����
void setGroup( vector<Employee>&v, multimap<int, Employee>&m)
{
    for (vector<Employee>::iterator it=v.begin(); it!=v.end(); it++)
    {
        int depId=rand()%3;   //����������
        m.insert(make_pair(depId, *it));
    }
}
//��ʾԱ��
void showEmployee(multimap<int, Employee>&m)
{
    cout<<"�߻����ţ�"<<endl;
    multimap<int, Employee>::iterator pos=m.find(Scheme); 
    int num=m.count(Scheme);
    int  index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"������"<< pos->second.m_Name;
        cout<<"н�ʣ�"<<pos->second.m_Salary<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"�������ţ�"<<endl;
    pos=m.find(Fine_arts); 
    num=m.count(Fine_arts);
    index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"������"<< (*pos).second.m_Name;
        cout<<"н�ʣ�"<<(*pos).second.m_Salary<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"�з����ţ�"<<endl;
    pos=m.find(Research_development); 
    num=m.count(Research_development);
    index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"������"<< (*pos).second.m_Name;
        cout<<"н�ʣ�"<<(*pos).second.m_Salary<<endl;
    }
}
int main()
{
    //1. ����Ա��
    vector<Employee>v;
    creat_employee(v);
    // for (vector<Employee>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<"������"<<(*it).m_Name;
    //     cout<<"нˮ��"<<(*it).m_Salary<<endl;
    // }    
    //2. Ա������
    multimap<int, Employee>m;
    setGroup(v, m);
    //������ʾԱ��
    showEmployee(m);
    system("pause");
    return 0;
}