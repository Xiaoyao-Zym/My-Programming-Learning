#include <iostream>
using namespace std;
#define N 3
int main()
{
    int i, j, k = 0, Source_data[N][N], Transpose_data[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << "��" << i + 1 << "�е�" << j + 1 << "��Ԫ��Ϊ��";
            cin >> Source_data[i][j];
        }
    }
    cout<<"����ľ���"<<endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << Source_data[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Transpose_data[j][i] = Source_data[i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (Transpose_data[i][j] == Source_data[i][j])
                k++;
        }
    }
    cout << "Whether the matrix is symmetic? Yes / No :  ";
    if (k ==(N*N) ) {
        cout << "Yes"<<endl;
    }
    else
        cout << "No"<<endl;
     system("pause");
    return 0;
}