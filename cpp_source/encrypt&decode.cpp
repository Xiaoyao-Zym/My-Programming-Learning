#include <iostream>
using namespace std;
int main()
{
    int  k, i;
    char a[40];
    cout << "�������������Կ��" << endl;
    cin >> a >> k;
    for (i = 0; a[i] != '\0'; i++)  //����
    {
        if (a[i] <= 'z' && a[i] >= 'a') {
            a[i] = (a[i] + k - 'a') % 26 + 'a';
        }
        else
            a[i] = (a[i] + k - 'A') % 26 + 'A';
    }
    cout << "���ܺ�" << a << endl;
    for (i = 0; a[i] != '\0'; i++)  //����
    {
        if (a[i] <= 'z' && a[i] >= 'a') {
            a[i] = (a[i] - k - 'a' + 26) % 26 + 'a';
        }
        else
            a[i] = (a[i] - k - 'A' + 26) % 26 + 'A';
    }
    cout << "���ܺ�" << a << endl;
    system("pause");
    return 0;
}