#include <iostream>
#include <string>
#include<ctime>
using namespace std;
//�ṹ�嶨��
struct Student
{
    //ѧ����Ϣ�б�
    string name;
    int    age;
    int    score;
};
struct Teacher
{
    //��ʦ��Ϣ�б�
    int            ID;
    string         name;
    int            age;
    struct Student sArray[5];
};
//ֵ����
void allocateSpace(struct Teacher tArray[], int len)
{
    string nameSeed="ABCDE";
    for (int i = 0; i < len; i++)
    {
        tArray[i].name="Teacher";
        tArray[i].name+=nameSeed[i];
        for (int j = 0; j< 5; j++)
        {
            tArray[i].sArray[j].name="Student";
            tArray[i].sArray[j].name+=nameSeed[j];
            int random=rand()%61+40;
            tArray[i].sArray[j].score= random;
        }
    }
}
void printInfo(struct Teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout<<"��ʦ������"<<tArray[i].name<<endl;
        for (int j = 0; j < 5; j++)
        {
            cout<<"\tѧ��������"<<tArray[i].sArray[j].name
                   <<"\tѧ���ɼ���"<<tArray[i].sArray[j].score
                   <<endl;
        }
    }
}
int main()
{
    //��������ӷ�����
    srand((unsigned int )time(NULL));
    //�����ṹ�����
    struct Teacher tArray[3];
    int  len=sizeof(tArray)/ sizeof(tArray[0]);
    allocateSpace(tArray,  len);
    printInfo(tArray, len);
    system("pause");
}