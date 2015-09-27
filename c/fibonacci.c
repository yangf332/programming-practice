#include "stdio.h"

int F(int n)
{
    if (n == 1 || n == 2) return n;
    return F(n - 1) + F(n - 2);
}

int main()
{
    for (int i = 1; i <= 7; i ++) {
        printf("F(%d)=%d \n", i, F(i));
    }

    return 0;
}
