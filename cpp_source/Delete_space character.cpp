#include <iostream>
#include <string>
using namespace std;
int main()
{
    int    i, len = 0;
    string data;
    cout << "������ĩβ���ո���ַ�����" << endl;
    cin >> data;
    while (data[i] != '\0') {
        len++;
        i++;
    }
    for (i = len; i > 0; i--) {
        if (data[i] == ' ') {
            data[i] = '\0';
        }
    }
    cout << "���ĩβ�޿ո���ַ�����" << data << endl;
    system("pause");
    return 0;
}