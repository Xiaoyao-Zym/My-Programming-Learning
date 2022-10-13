#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
//选手类
class Person
{
public:
   Person(string name, int score) 
   {
       m_Name=name;
       m_Score=score;
   }
   string m_Name;
   int m_Score;
};
void creatPerson(vector<Person>&v)
{
    string nameSeed="ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name="选手：";
        name+=nameSeed[i];
        int score=0;
        //将创建的person对象，放入到容器中
        Person p(name, score);
        v.push_back(p);
    }
}
//打分
void setScore(vector<Person>&v)
{
    for (vector<Person>:: iterator it=v.begin(); it!=v.end();it++)
    {
        //将评委的打分放入deque容器中
        deque<int>d;
        for (int i = 0; i < 10; i++)
        {
            int score=rand()%41+60; //60~100
            d.push_back(score);
        }
        // cout<<it->m_Name<<"打分："<<endl;
        // for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        // {
        //     cout<<*dit<<" ";   
        // }
        // cout<<endl;
        //排序
        sort(d.begin(), d.end());
        //去除最高分和最低分
        d.pop_back();
        d.pop_front();
        //取平均分
        int sum=0;
        for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        {
            sum+=*dit;   //累加每个分数
        }
        int avg=sum/d.size();
        //将平均分 赋值给选手身上
        it->m_Score=avg;
    }
}
void showScore(vector<Person>&v)
{
    for (vector<Person>:: iterator it=v.begin(); it!=v.end();it++)
    {
        cout<<it->m_Name<<"   平均得分："<<it->m_Score<<endl;
    }
}
int main()
{
    //1. 创建5名选手
    vector<Person>v;  //存放选手的容器
    creatPerson(v);
    // for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<"姓名："<<(*it).m_Name;
    //     cout<<"分数："<<(*it).m_Score<<endl;
    // }    
    //选手打分
    setScore(v);    
    //输出分数
    showScore(v);
    system("pause");
    return 0;
}