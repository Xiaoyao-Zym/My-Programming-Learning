#include <iostream>
using namespace std;

void bubble_sort(int* data, int len)
{
    for (int i = 0; i < len - 1; i++) {
        //�ڲ�ѭ���Աȴ�����Ԫ�ظ���-��ǰ����-1
        for (int j = 0; j < len - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp    = data[j];
                data[j]     = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int i, j, data[] = {4, 2, 3, 5, 1, 9, 7, 8, 6};
    int len = sizeof(data) / sizeof(data[0]);
    bubble_sort(data, len);
    cout << "�����" << endl;
    for (int i = 0; i < len; i++) {
        cout << data[i] << ' ';
    }
    system("pause");
}