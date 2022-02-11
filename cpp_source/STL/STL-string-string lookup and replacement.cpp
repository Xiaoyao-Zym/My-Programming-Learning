#include<string>
#include<iostream>
using namespace std;
//²éÕÒ
void test01()
{
    string str1="abcdefg";
    //find²éÕÒ´Ó×óÍùÓÒ£»
    int pos =str1.find("cd");
    if (pos==-1)
    {
        cout<<"Î´ÕÒµ½×Ö·û´®";
    }
    else
    {
        cout<<"ÕÒµ½×Ó´®Î»ÖÃ£º"<<pos<<endl;
    }
    //rfind´ÓÓÒÍù×óÕÒ
    pos=str1.rfind("cd");
    cout<<"pos="<<pos<<endl; 
}
//Ìæ»»
void test02()
{
    string str2="abcdefd";
    str2.replace(2, 2,"12345");
    cout<<"str2="<<str2<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}