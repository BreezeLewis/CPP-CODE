#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 25
int main()
{
    int a[MAX_SIZE][MAX_SIZE], n, cnum, x, y, k = 1, i, j;
    scanf("%d", &n);
    cnum = (int)ceil((double)n / 2);
    for (i = 1; i <= cnum; i++)
    {
        for (x = i, y = n - i + 1; x <= n - i + 1; x++)
            a[x][y] = k++;
        for (x = n - i + 1, y = n - i; y >= i; y--)
            a[x][y] = k++;
        for (x = n - i, y = i; x >= i; x--)
            a[x][y] = k++;
        for (x = i, y = i + 1; y <= n - i; y++)
            a[x][y] = k++;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}