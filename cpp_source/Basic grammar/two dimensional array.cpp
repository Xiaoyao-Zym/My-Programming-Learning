#include <iostream>
#include <string>
using namespace std;
int main()
{
    int scores[3][3] = {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80},
    };
    //输出分数
    string name[3] = {"ZHang", "Wang", "Li"};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << scores[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //统计总分
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += scores[i][j];
        }
        cout << name[i] << "的总分为：" << sum << endl;
    }
    system("pause");
    return 0;
}