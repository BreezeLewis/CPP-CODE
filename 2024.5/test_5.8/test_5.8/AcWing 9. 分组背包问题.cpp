#include <iostream>

using namespace std;

const int N = 110;

int f[N], v[N], w[N];

int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        for (int i = 0; i < s; i++) cin >> v[i] >> w[i];
        for (int j = m; j >= 0; j--)
            for (int k = 0; k < s; k++)
                if (j >= v[k])
                    f[j] = max(f[j], f[j - v[k]] + w[k]);
    }

    cout << f[m] << endl;

    return 0;
}