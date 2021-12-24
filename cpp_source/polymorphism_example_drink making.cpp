#include<iostream>
using namespace std;
//利用多态技术实现，提供抽象制作品基类
class AbstractDrinking
{
public:
    //煮水
    virtual void Boil()=0;
    //冲泡
    virtual void Brew()=0;
    //倒入
    virtual void PourInCup()=0;
    //加入辅料
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
//制作咖啡
class Cooffee : public AbstractDrinking
{
public:
     //煮水
    virtual void Boil()
    {
        cout<<"煮山泉水"<<endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout<<"冲泡咖啡"<<endl;
    }
    //倒入
    virtual void PourInCup()
    {
        cout<<"倒入杯中"<<endl;
    }
    //加入辅料
    virtual void PutSoming()
    {
        cout<<"加入糖和牛奶"<<endl;;
    }
};
//制作茶叶
class Tea : public AbstractDrinking
{
public:
     //煮水
    virtual void Boil()
    {
        cout<<"煮山泉水"<<endl;
    }
    //冲泡
    virtual void Brew()
    {
        cout<<"冲泡茶叶"<<endl;
    }
    //倒入
    virtual void PourInCup()
    {
        cout<<"加入红枣"<<endl;
    }
    //加入辅料
    virtual void PutSoming()
    {
        cout<<"加入白砂糖"<<endl;
    }
};
//制作函数
void doWork(AbstractDrinking *abs)
{
    abs->makeDrink();
    delete abs;              //释放
}
void test01()
{
    //制作咖啡
    doWork(new  Cooffee);
    //制作茶叶
    doWork(new  Tea);
}
int main()
{
    test01();
    system("pause");
    return 0;
}