#include<stdio.h>
int main()
{
    for (int i =1 ; i <=100; i++)
    {
        for (int j = 1; j <=100; j++)
        {
            for (int k = 0; k <=100; k++)
            {
                if (5*i+3*j+k/3==100&k%3==0&i+j+k==100)
                {
                    printf("公鸡数：%d", i);
                    printf("公鸡数：%d", j);
                    printf("公鸡数：%d", k);
                }
            }
        }
    }
}