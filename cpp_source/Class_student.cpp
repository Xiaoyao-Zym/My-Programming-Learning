#include<iostream>
#include<string>
using namespace std;

class student
{
private:
    /* data */
public:
    //�����Ժ���Ϊ ͳ��Ϊ��Ա
    //���ԣ���Ա����  ��Ա����
    //��Ϊ����Ա����  ��Ա����
    //����
    string m_name;
    string m_ID;

    //��Ϊ
    void Input()
    {
        cout<<"������ѧ��������ID";
        cin>>m_name;
        cin>>m_ID;
    }
    void Output()
    {
        cout<<"������"<<m_name<<"ID��"<<m_ID<<endl;
    }
};
int main()
{
    student s;  //������ʵ��
    s.Input();
    s.Output();   
    system("pause");
    return 0;
}