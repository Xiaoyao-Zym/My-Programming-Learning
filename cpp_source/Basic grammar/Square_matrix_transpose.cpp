#include <iostream>
#define N 4
using namespace std;
int main()
{
    int t, i, j;
    int data[N][N];
    cout << "���������Ԫ�أ�" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << "��" << i + 1 << "�е�" << j + 1 << "��Ԫ��Ϊ��";
            cin >> data[i][j];
        }
    }
    cout << "����ľ���Ϊ��" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < i; j++) {
            t          = data[i][j];
            data[i][j] = data[j][i];
            data[j][i] = t;
        }
    }
    cout << "ת�ú�ľ���Ϊ��" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}