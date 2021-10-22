#include <iostream>
#include <string>
using namespace std;
int main()
{
    int  i, len = 0;
    char data[1024];
    cout << "请输入末尾带空格的字符串：" << endl;
    for (i = 0; i < 1024; i++)
    {
            cin >> data[i];
    }
    while (data[i] != '\0') {
        len++;
        i++;
    }