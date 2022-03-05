#include<iostream>
using namespace std;
//����CPU��
class CPU
{
public:
    //����ļ��㺯��
    virtual void calculate()=0;
};
class GraphicsCard
{
public:
    //�������ʾ����
    virtual  void show()=0;
};
//������ڴ���
class MemoryBank
{
public:
    //����Ĵ洢����
    virtual void storage()=0;
};
class Computer
{
public:
    Computer(CPU *cpu, GraphicsCard *vc, MemoryBank *men)
    {
        m_cpu=cpu; 
        m_vc=vc;
        m_mem=men;
    }
    //�ṩ�����ĺ���
    void work()
    {
        //������������ýӿ�
        m_cpu->calculate();
        m_vc->show();
        m_mem->storage();
    }
    //�ṩ�����������ͷ�3�����
    ~Computer()
    {
        if (m_cpu!=NULL)
        {
            delete m_cpu;
            m_cpu=NULL;
        }
        if (m_vc!=NULL)
        {
            delete m_vc;
            m_vc=NULL;
        }
        if (m_mem!=NULL)
        {
            delete m_mem;
            m_mem=NULL;
        }
    }
private: 
    CPU *m_cpu;
    GraphicsCard *m_vc;
    MemoryBank *m_mem;
};
//����01
class Inter_Cpu : public CPU
{
public:
    virtual void calculate()
    {
         cout<<"Inter CPU��ʼ����"<<endl;
    }
};
class Inter_VideoCard : public GraphicsCard
{
public:
    virtual void show()
    {
         cout<<"Inter �Կ���ʼ����"<<endl;
    }
};
class Inter_Memory : public MemoryBank
{
public:
    virtual void  storage()
    {
         cout<<"Inter �ڴ濪ʼ�洢"<<endl;
    }
};
//����02
class AMD_Cpu : public CPU
{
public:
    virtual void calculate()
    {
         cout<<"AMD CPU��ʼ����"<<endl;
    }
};
class AMD_VideoCard : public GraphicsCard
{
public:
    virtual void show()
    {
         cout<<"AMD �Կ���ʼ����"<<endl;
    }
};
class AMD_Memory : public MemoryBank
{
public:
    virtual void  storage()
    {
         cout<<"AMD �ڴ濪ʼ�洢"<<endl;
    }
};
void test01()
{
    //��һ̨�������
    cout<<"��һ̨���Կ�ʼ����"<<endl;
    CPU *interCpu=new Inter_Cpu;
    GraphicsCard *interCard=new Inter_VideoCard;
    MemoryBank *inerMemroy=new Inter_Memory;
    //������һ̨����
    Computer  *computer01=new Computer(interCpu, interCard, inerMemroy);
    computer01->work();
    delete computer01;
    cout<<"-----------------------"<<endl;
    //�����ڶ�̨����
    cout<<"�ڶ�̨���Կ�ʼ����"<<endl;
    Computer  *computer02=new Computer(new AMD_Cpu, new AMD_VideoCard, new AMD_Memory);
    computer02->work();
    delete computer02;
    cout<<"-----------------------"<<endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}