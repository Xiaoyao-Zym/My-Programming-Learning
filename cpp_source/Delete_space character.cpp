#include <iostream>
#include <string>
using namespace std;
int main()
{
    int    i, len = 0;
    string data;
    cout << "ÇëÊäÈëÄ©Î²´ø¿Õ¸ñµÄ×Ö·û´®£º" << endl;
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
    cout << "Êä³öÄ©Î²ÎŞ¿Õ¸ñµÄ×Ö·û´®£º" << data << endl;
    system("pause");
    return 0;
}