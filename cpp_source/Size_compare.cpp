#include <iostream>
#include <string>
using namespace std;
int main()
{
    int P1, P2, P3;
    cout << "����������������" << endl;
    cin >> P1 >> P2 >> P3;
    if (P2 > P1) {
        if (P2 > P3) {
            cout << "���������ǣ�" << P2<<endl;
        }
        else
            cout << "���������ǣ�" << P3<<endl;
    }
    else if (P1 > P3) {
        cout << "���������ǣ�" << P1<<endl;
    }
    else
        cout << "���������ǣ�" << P3<<endl;
    system("pause");
}