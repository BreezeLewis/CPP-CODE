#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2010;
int f[N], n, m;
struct good
{
    int w, v;
};

int main()
{
    cin >> n >> m;
    vector<good> Good;
    good tmp;

    //�����ƴ���
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        //��,k <= s
        for (int k = 1; k <= s; k *= 2)
        {
            s -= k;
            Good.push_back({ k * w,k * v });
        }
        if (s > 0) Good.push_back({ s * w,s * v });
    }

    //01�����Ż�+������
    for (auto t : Good)
        for (int j = m; j >= t.v; j--)
            f[j] = max(f[j], f[j - t.v] + t.w); //�������f[j]


    cout << f[m] << endl;
    return 0;

}
