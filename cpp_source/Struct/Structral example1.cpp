#include <iostream>
#include <string>
#include<ctime>
using namespace std;
//结构体定义
struct Student
{
    //学生信息列表
    string name;
    int    age;
    int    score;
};
struct Teacher
{
    //老师信息列表
    int            ID;
    string         name;
    int            age;
    struct Student sArray[5];
};
//值传递
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
        cout<<"老师姓名："<<tArray[i].name<<endl;
        for (int j = 0; j < 5; j++)
        {
            cout<<"\t学生姓名："<<tArray[i].sArray[j].name
                   <<"\t学生成绩："<<tArray[i].sArray[j].score
                   <<endl;
        }
    }
}
int main()
{
    //随机数种子发生器
    srand((unsigned int )time(NULL));
    //创建结构体变量
    struct Teacher tArray[3];
    int  len=sizeof(tArray)/ sizeof(tArray[0]);
    allocateSpace(tArray,  len);
    printInfo(tArray, len);
    system("pause");
}