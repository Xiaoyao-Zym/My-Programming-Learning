#include<iostream>
using namespace std;
//���ö�̬����ʵ�֣��ṩ��������Ʒ����
class AbstractDrinking
{
public:
    //��ˮ
    virtual void Boil()=0;
    //����
    virtual void Brew()=0;
    //����
    virtual void PourInCup()=0;
    //���븨��
    virtual void PutSoming()=0;
    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PourInCup();
        PutSoming();
    }
};
//��������
class Cooffee : public AbstractDrinking
{
public:
     //��ˮ
    virtual void Boil()
    {
        cout<<"��ɽȪˮ"<<endl;
    }
    //����
    virtual void Brew()
    {
        cout<<"���ݿ���"<<endl;
    }
    //����
    virtual void PourInCup()
    {
        cout<<"���뱭��"<<endl;
    }
    //���븨��
    virtual void PutSoming()
    {
        cout<<"�����Ǻ�ţ��"<<endl;;
    }
};
//������Ҷ
class Tea : public AbstractDrinking
{
public:
     //��ˮ
    virtual void Boil()
    {
        cout<<"��ɽȪˮ"<<endl;
    }
    //����
    virtual void Brew()
    {
        cout<<"���ݲ�Ҷ"<<endl;
    }
    //����
    virtual void PourInCup()
    {
        cout<<"�������"<<endl;
    }
    //���븨��
    virtual void PutSoming()
    {
        cout<<"�����ɰ��"<<endl;
    }
};
//��������
void doWork(AbstractDrinking *abs)
{
    abs->makeDrink();
    delete abs;              //�ͷ�
}
void test01()
{
    //��������
    doWork(new  Cooffee);
    //������Ҷ
    doWork(new  Tea);
}
int main()
{
    test01();
    system("pause");
    return 0;
}