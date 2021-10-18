#include <iostream>
#define N 4
using namespace std;
int main()
{
    int t, i, j;
    int data[N][N];
    cout << "请输入矩阵元素：" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << "第" << i + 1 << "行第" << j + 1 << "个元素为：";
            cin >> data[i][j];
        }
    }
    cout << "输入的矩阵为：" << endl;
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
    cout << "转置后的矩阵为：" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}