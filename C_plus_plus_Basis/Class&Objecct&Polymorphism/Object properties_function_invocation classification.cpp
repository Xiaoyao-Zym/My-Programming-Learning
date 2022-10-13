#include<iostream>
using namespace std;
//对象的初始化和清理
//构造函数分类及调用
//分类
// 按照参数分类   无参函数构造    有参函数构造
//按照类型分类    普通构造           拷贝构造
class Person
{
    //构造函数
    //没有返回值，不用写void
    //函数名与类名相同
    //构造函数可以有参数，可以发生重载
    //创建对象的时候，构造函数会自动调用，而且只调用一次。
public:
    Person()
    {
        cout<<"Person的无参构造函数调用"<<endl;
    }
     int age;
    Person(int a)
    {
        age=a;
        cout<<"Person的有参构造函数调用"<<endl;
    }
    //拷贝构造函数
    Person(const Person&p)
    {
        //将传入的人身上的所有属性，拷贝出来
        cout<<"Person的拷贝构造函数调用"<<endl;
        age =p.age;

    }
    //解析函数 进行清理的操作。
    //没有返回值，不用写void
    //函数名与类名相同
    //构造函数可以有参数，可以发生重载
    //创建对象的时候，构造函数会自动调用，而且只调用一次。
    ~Person()
    {
        cout<<"Person 析构函数调用"<<endl;
    }
};

//调用
void test01()
{
    //1.括号法
    //Person p1;          //调用无参函数
    //Person p2(10);   //调用有参函数
   // Person p3(p2);   //拷贝构造函数调用
    //cout<<"p2的年龄为："<<p2.age<<endl;
    //cout<<"p3的年龄为："<<p3.age<<endl;
    //注意事项
    //调用默认构造函数，不能加 ()

    //显示法
    //Person p1;
    //Person p2=Person(10);
    //Person p3=Person(p2);
    //注意事项2
    //Person(10);  //匿名对象，特点：当前行执行结束后，系统会立即会回收掉匿名对象
    
    //隐式转换法
    Person p4=10;  //相当于 写·了Person  p4=Person(10);
}
int main()
{
    test01();
    system("pause");
    return 0;
}