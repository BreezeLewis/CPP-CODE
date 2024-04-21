#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss()
{
    int c, r;
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r;
        for (int i = r; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))//1.找到当前列c绝对值最大的行
                t = i;

        if (fabs(a[t][c]) < eps) continue;//当前列最大值为0，不用处理

        for (int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);//把最大行和r行交换
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];//最大行第一个数变1
        for (int i = r + 1; i < n; i++)//此时r行为1，r+1行开始，c列全部变0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[i][c] * a[r][j];

        r++;
    }

    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return 2;
        return 1;
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[i][j] * a[j][n];

    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];

    int t = gauss();

    if (t == 0) for (int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
    else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");

    return 0;
}