#include<iostream>
using namespace std;
//抽象CPU类
class CPU
{
public:
    //抽象的计算函数
    virtual void calculate()=0;
};
class GraphicsCard
{
public:
    //抽象的显示函数
    virtual  void show()=0;
};
//抽象的内存条
class MemoryBank
{
public:
    //抽象的存储函数
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
    //提供工作的函数
    void work()
    {
        //零件工作，调用接口
        m_cpu->calculate();
        m_vc->show();
        m_mem->storage();
    }
    //提供析构函数，释放3个零件
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
//厂商01
class Inter_Cpu : public CPU
{
public:
    virtual void calculate()
    {
         cout<<"Inter CPU开始计算"<<endl;
    }
};
class Inter_VideoCard : public GraphicsCard
{
public:
    virtual void show()
    {
         cout<<"Inter 显卡开始工作"<<endl;
    }
};
class Inter_Memory : public MemoryBank
{
public:
    virtual void  storage()
    {
         cout<<"Inter 内存开始存储"<<endl;
    }
};
//厂商02
class AMD_Cpu : public CPU
{
public:
    virtual void calculate()
    {
         cout<<"AMD CPU开始计算"<<endl;
    }
};
class AMD_VideoCard : public GraphicsCard
{
public:
    virtual void show()
    {
         cout<<"AMD 显卡开始工作"<<endl;
    }
};
class AMD_Memory : public MemoryBank
{
public:
    virtual void  storage()
    {
         cout<<"AMD 内存开始存储"<<endl;
    }
};
void test01()
{
    //第一台电脑零件
    cout<<"第一台电脑开始工作"<<endl;
    CPU *interCpu=new Inter_Cpu;
    GraphicsCard *interCard=new Inter_VideoCard;
    MemoryBank *inerMemroy=new Inter_Memory;
    //创建第一台电脑
    Computer  *computer01=new Computer(interCpu, interCard, inerMemroy);
    computer01->work();
    delete computer01;
    cout<<"-----------------------"<<endl;
    //创建第二台电脑
    cout<<"第二台电脑开始工作"<<endl;
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