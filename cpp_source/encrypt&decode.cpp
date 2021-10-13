#include <iostream>
using namespace std;
int main()
{
    int  k, i;
    char a[40];
    cout << "请输入密码和密钥：" << endl;
    cin >> a >> k;
    for (i = 0; a[i] != '\0'; i++)  //加密
    {
        if (a[i] <= 'z' && a[i] >= 'a') {
            a[i] = (a[i] + k - 'a') % 26 + 'a';
        }
        else
            a[i] = (a[i] + k - 'A') % 26 + 'A';
    }
    cout << "加密后" << a << endl;
    for (i = 0; a[i] != '\0'; i++)  //解密
    {
        if (a[i] <= 'z' && a[i] >= 'a') {
            a[i] = (a[i] - k - 'a' + 26) % 26 + 'a';
        }
        else
            a[i] = (a[i] - k - 'A' + 26) % 26 + 'A';
    }
    cout << "解密后" << a << endl;
    system("pause");
    return 0;
}