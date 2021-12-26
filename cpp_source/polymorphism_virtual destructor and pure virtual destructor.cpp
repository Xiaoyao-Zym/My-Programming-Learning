#include<iostream>
#include<string>
using namespace std;
//虚析构和纯虚析构共性：可以解决父类指针释放子类对象，都需要具体的·函数实现，纯虚析构类属于抽象类，无法实例化对象
//虚析构语法：virtual~类名() {}，纯虚析构语法：virtual~类名()=0，
//虚析构和纯虚析构
class Animal
{
public: 
    //纯虚函数
    Animal()
    {
        cout<<"Animal构造函数调用"<<endl;
    }
    //利用虚析构可以解决父类指针释放子类对象不干净的问题
    // virtual ~Animal()
    // {
    //     cout<<"Animal析构函数调用"<<endl;
    // }
    //纯虚函数  需要声明也需要实现
    //纯虚析构，这个也属于抽象类，无法实例化对象
    virtual ~Animal()=0;
    //纯虚函数
    virtual void speak()=0;
};
Animal ::~Animal()
{
    cout<<"Animal析构函数调用"<<endl;
}
class Cat : public Animal
{
public:
    Cat(string  name)
    {
         cout<<"Cat构造函数调用"<<endl;
         m_Name=new string(name);
    }
    virtual void speak()
    {
        cout<<m_Name<<"小猫在说话"<<endl;
    }
    string *m_Name;
    ~Cat()
    {
        if(m_Name!=NULL)
        {
            cout<<"Cat析构函数调用"<<endl;
            //父类指针在析构时候， 不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄漏
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