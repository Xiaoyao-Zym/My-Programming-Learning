#include<iostream>
#include<string>
using namespace std;
struct Hero 
{
    string name;
    int      age;
    string gender;
};
void bubbleSort (struct Hero heroArray[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (heroArray[j].age>heroArray[j+1].age)
            {
                struct Hero  temp=heroArray[j];
                heroArray[j]=heroArray[j+1];
                heroArray[j+1]= temp;
            }
        }
    }
    for (int i = 0; i < len ; i++) 
    {
        cout << "������" << heroArray[i].name << "���䣺" << heroArray[i].age << "������"
                << heroArray[i].gender << endl;
     }
}
int main()
{
    struct Hero heroArray[5] = 
    {
        {"����", 18, "��"},
        {"����", 21, "��"},
        {"�ŷ�", 20, "��"},
        {"����", 23, "��"},
        {"����", 19, "Ů"},
    };
    int len=sizeof(heroArray) / sizeof(heroArray[0]);
    bubbleSort(heroArray, len);
    system("pause");
}