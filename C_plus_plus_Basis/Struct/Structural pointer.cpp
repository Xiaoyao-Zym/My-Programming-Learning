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
int main()
{
    //�����ṹ�����
    struct Student s2 = {"����", 18, 100};
    //�����ṹ��ָ��ָ��ṹ�����
    struct Student* p = &s2;
    //ͨ��ָ����ʽṹ���������
    cout << "������" << p->name << " ���䣺" << p->age << " ������" << p->score
         << endl;
    system("pause");
}
