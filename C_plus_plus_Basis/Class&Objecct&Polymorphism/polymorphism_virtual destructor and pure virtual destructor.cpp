#include<iostream>
#include<string>
using namespace std;
//�������ʹ����������ԣ����Խ������ָ���ͷ�������󣬶���Ҫ����ġ�����ʵ�֣��������������ڳ����࣬�޷�ʵ��������
//�������﷨��virtual~����() {}�����������﷨��virtual~����()=0��
//�������ʹ�������
class Animal
{
public: 
    //���麯��
    Animal()
    {
        cout<<"Animal���캯������"<<endl;
    }
    //�������������Խ������ָ���ͷ�������󲻸ɾ�������
    // virtual ~Animal()
    // {
    //     cout<<"Animal������������"<<endl;
    // }
    //���麯��  ��Ҫ����Ҳ��Ҫʵ��
    //�������������Ҳ���ڳ����࣬�޷�ʵ��������
    virtual ~Animal()=0;
    //���麯��
    virtual void speak()=0;
};
Animal ::~Animal()
{
    cout<<"Animal������������"<<endl;
}
class Cat : public Animal
{
public:
    Cat(string  name)
    {
         cout<<"Cat���캯������"<<endl;
         m_Name=new string(name);
    }
    virtual void speak()
    {
        cout<<m_Name<<"Сè��˵��"<<endl;
    }
    string *m_Name;
    ~Cat()
    {
        if(m_Name!=NULL)
        {
            cout<<"Cat������������"<<endl;
            //����ָ��������ʱ�� ������������е�����������������������ж������ԣ������ڴ�й©
            delete m_Name;
            m_Name=NULL;
        }
    }
};
void test01()
{
    Animal *animal=new Cat("Tom");
    animal->speak();
    delete animal;
}
int main()
{
    test01();
    system("pause");
    return 0;
}