#include <iostream>
#include <string>
using namespace std;
//�ṹ�嶨��
struct Student
{
    //��Ա��Ϣ�б�
    string name;
    int    age;
    int    score;
};

//ֵ����
void printStudent1(struct Student s)
{
    cout<<"������"<<s.name<<"���䣺"<<s.age<<"������"<<s.score<<endl;
}
//��ַ����
void printStudent2(struct Student *s)
{
    cout<<"������"<<s->name<<"���䣺"<<s->age<<"������"<<s->score<<endl;
}
int main()
{
    //�����ṹ�����
    struct Student s = {"����", 18, 100};
    printStudent1(s);
    //�����ṹ��ָ��ָ��ṹ�����
    struct Student * p = &s;  
    printStudent1(*p);
    //ͨ��ָ����ʽṹ���������
    system("pause");
}