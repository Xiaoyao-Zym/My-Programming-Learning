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
    //�����ṹ������
    struct Student s2[3] = {
        {"����", 18, 100},
        {"����", 19, 100},
        {"����", 20, 100},
    };
    //�ṹ�����鸳ֵ
    s2[2].name = "����";
    //�ṹ�����
    for (int i = 0; i < 3; i++) {
        cout << "������" << s2[i].name << "���䣺" << s2[i].age << "������"
             << s2[i].score << endl;
    }
    system("pause");
}
