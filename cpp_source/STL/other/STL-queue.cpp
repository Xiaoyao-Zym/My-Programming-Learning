#include<iostream>
#include<queue>
using namespace std;
//队列queue容器
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
    string m_Name;
    int m_Age;
};
void test()
{
    //创建队列
    queue<Person>q;
    //入栈
    Person p1("唐三藏", 100);
    Person p2("孙悟空", 500);
    Person p3("猪八戒", 400);
    Person p4("沙和尚", 300);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"队列的大小："<<q.size()<<endl;
    //只要队列不为空，查看队头和队尾，并且执行出队操作
    while (!q.empty())
    {
        //查看队头元素
        cout<<"队头元素为--姓名："<<q.front().m_Name
               <<"--年龄："<<q.front().m_Age<<endl
               <<"队尾元素为--姓名："<<q.back().m_Name
               <<"--年龄："<<q.back().m_Age<<endl;
        //出队
        q.pop();
    }
    cout<<"队列的大小："<<q.size()<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}