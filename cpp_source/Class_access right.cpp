#include<iostream>
#include<string>
using namespace std;

//����Ȩ��
//����
//����Ȩ��  public     ��Ա  ���ڿ��Է��ʣ�������Է���
//����Ȩ��  protect   ��Ա  ���ڿ��Է��ʣ����ⲻ���Է���      �ӳ�Ա���ʸ���Ա��������
//˽��Ȩ��  private   ��Ա  ���ڿ��Է��ʣ����ⲻ���Է���      �ӳ�Ա�����Է��ʸ���Ա��������
//Ĭ��Ȩ���� private
class  person
{
private:
    /* ˽��Ȩ��*/
    string m_Name;    //����
protected:
    /* ����Ȩ��*/   
    string m_Car;
public:
    /*����Ȩ��*/
    int m_Password; //���п�����

public:
    void func()
    {
        m_Name="����";
        m_Car="������";
        m_Password=1223;
    }
};

struct C1
{
    /* Ĭ���ǹ���Ȩ��*/
    int m_A; 
}s;

int main()
{
    person p1;
    // p1.m_Name="����";           //˽��Ȩ���޷�����
    //p1.m_Car="����";             //����Ȩ���޷�����
    p1.m_Password =123;  
    s.m_A=123;
    system("pause");
    return 0;
}