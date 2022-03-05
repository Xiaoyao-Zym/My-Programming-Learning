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
        cout << "ÐÕÃû£º" << heroArray[i].name << "ÄêÁä£º" << heroArray[i].age << "·ÖÊý£º"
                << heroArray[i].gender << endl;
     }
}
int main()
{
    struct Hero heroArray[5] = 
    {
        {"Áõ±¸", 18, "ÄÐ"},
        {"¹ØÓð", 21, "ÄÐ"},
        {"ÕÅ·É", 20, "ÄÐ"},
        {"ÕÔÔÆ", 23, "ÄÐ"},
        {"õõ²õ", 19, "Å®"},
    };
    int len=sizeof(heroArray) / sizeof(heroArray[0]);
    bubbleSort(heroArray, len);
    system("pause");
}