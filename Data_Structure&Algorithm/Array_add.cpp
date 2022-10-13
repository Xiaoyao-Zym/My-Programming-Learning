#include<iostream>
#include<algorithm>
int sum(int A[], int lo, int hi)
{
    //数组求和算法(二分递归版)
    if (lo==hi)
    {
        return A[lo];
    }
    else
    {
        int mi=(lo+hi)>>1;//以居中单元为界，将原区间一分为二
        return sum(A, lo, mi)+sum(A, mi+1, hi);//递归对各子数组求和，然后合计
    }
}
void reverse(int* A, int lo, int hi)
{
    // //数据倒置
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

