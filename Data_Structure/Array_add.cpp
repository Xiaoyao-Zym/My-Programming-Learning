#include<iostream>
#include<algorithm>
int sum(int A[], int lo, int hi)
{
    //��������㷨(���ֵݹ��)
    if (lo==hi)
    {
        return A[lo];
    }
    else
    {
        int mi=(lo+hi)>>1;//�Ծ��е�ԪΪ�磬��ԭ����һ��Ϊ��
        return sum(A, lo, mi)+sum(A, mi+1, hi);//�ݹ�Ը���������ͣ�Ȼ��ϼ�
    }
}
void reverse(int* A, int lo, int hi)
{
    // //���ݵ���
    // next:
    // if (lo<hi)
    // {
    //     swap(A[lo], A[hi]);
    //     lo++;
    //     hi--;
    //     goto next;
    // }
    while (lo<hi)
    {
        swap(A[lo+1    }
    
}

