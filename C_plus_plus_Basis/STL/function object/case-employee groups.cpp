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
//创建员工
void creat_employee(vector<Employee>&v)
{
    string nameSeed="ABCDEFGHJK";
    for (int i = 0; i < 10; i++)
    {
        string name="员工：";
        name+=nameSeed[i];
        int salary=rand()%5000+10000;   //10000~149999
        Employee e(name,salary);
        v.push_back(e);
    }
}
//分组
void setGroup( vector<Employee>&v, multimap<int, Employee>&m)
{
    for (vector<Employee>::iterator it=v.begin(); it!=v.end(); it++)
    {
        int depId=rand()%3;   //产生随机编号
        m.insert(make_pair(depId, *it));
    }
}
//显示员工(方法1)
void showEmployee01(multimap<int, Employee>&m)
{
    cout<<"策划部门："<<endl;
    multimap<int, Employee>::iterator pos=m.find(Scheme); 
    int num=m.count(Scheme);
    int  index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"姓名："<< pos->second.m_Name;
        cout<<"薪资："<<pos->second.m_Salary<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"美术部门："<<endl;
    pos=m.find(Fine_arts); 
    num=m.count(Fine_arts);
    index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"姓名："<< (*pos).second.m_Name;
        cout<<"薪资："<<(*pos).second.m_Salary<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<"研发部门："<<endl;
    pos=m.find(Research_development); 
    num=m.count(Research_development);
    index=0;
    for (; pos!=m.end()&&index<num; pos++, index++)
    {
        cout<<"姓名："<< (*pos).second.m_Name;
        cout<<"薪资："<<(*pos).second.m_Salary<<endl;
    }
}
//显示员工(方法2)
void showEmployee02(multimap<int, Employee>&m)
{
    string s[3]={"策划部门", "美术部门", "研发部门"};
    for(int i=0; i<3; i++)
    {
        cout<<s[i]<<endl;
        multimap<int, Employee>::iterator pos=m.find(i); 
        int num=m.count(i);
        int index=0;
        for (; pos!=m.end()&&index<num; pos++, index++)
        {
        cout<<"姓名："<< (*pos).second.m_Name;
        cout<<"薪资："<<(*pos).second.m_Salary<<endl;
        }
        cout<<"------------------------------------"<<endl;
    }
}
int main()
{
    //1. 创建员工
    vector<Employee>v;
    creat_employee(v);
    // for (vector<Employee>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<"姓名："<<(*it).m_Name;
    //     cout<<"薪水："<<(*it).m_Salary<<endl;
    // }    
    //2. 员工分组
    multimap<int, Employee>m;
    setGroup(v, m);
    //分组显示员工
    showEmployee01(m);
    showEmployee02(m);
    system("pause");
    return 0;
}