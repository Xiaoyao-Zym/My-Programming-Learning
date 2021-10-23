#include <iostream>
#include <string>
using namespace std;
int main()
{
    int P1, P2, P3;
    cout << "请输入三个体重量" << endl;
    cin >> P1 >> P2 >> P3;
    if (P2 > P1) {
        if (P2 > P3) {
            cout << "体重最大的是：" << P2<<endl;
        }
        else
            cout << "体重最大的是：" << P3<<endl;
    }
    else if (P1 > P3) {
        cout << "体重最大的是：" << P1<<endl;
    }
    else
        cout << "体重最大的是：" << P3<<endl;
    system("pause");
}