#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
//ѡ����
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
        string name="ѡ�֣�";
        name+=nameSeed[i];
        int score=0;
        //��������person���󣬷��뵽������
        Person p(name, score);
        v.push_back(p);
    }
}
//���
void setScore(vector<Person>&v)
{
    for (vector<Person>:: iterator it=v.begin(); it!=v.end();it++)
    {
        //����ί�Ĵ�ַ���deque������
        deque<int>d;
        for (int i = 0; i < 10; i++)
        {
            int score=rand()%41+60; //60~100
            d.push_back(score);
        }
        // cout<<it->m_Name<<"��֣�"<<endl;
        // for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        // {
        //     cout<<*dit<<" ";   
        // }
        // cout<<endl;
        //����
        sort(d.begin(), d.end());
        //ȥ����߷ֺ���ͷ�
        d.pop_back();
        d.pop_front();
        //ȡƽ����
        int sum=0;
        for (deque<int>::iterator dit=d.begin(); dit!=d.end(); dit++)
        {
            sum+=*dit;   //�ۼ�ÿ������
        }
        int avg=sum/d.size();
        //��ƽ���� ��ֵ��ѡ������
        it->m_Score=avg;
    }
}
void showScore(vector<Person>&v)
{
    for (vector<Person>:: iterator it=v.begin(); it!=v.end();it++)
    {
        cout<<it->m_Name<<"   ƽ���÷֣�"<<it->m_Score<<endl;
    }
}
int main()
{
    //1. ����5��ѡ��
    vector<Person>v;  //���ѡ�ֵ�����
    creatPerson(v);
    // for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout<<"������"<<(*it).m_Name;
    //     cout<<"������"<<(*it).m_Score<<endl;
    // }    
    //ѡ�ִ��
    setScore(v);    
    //�������
    showScore(v);
    system("pause");
    return 0;
}