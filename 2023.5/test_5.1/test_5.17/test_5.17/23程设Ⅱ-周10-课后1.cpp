#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
struct mypair
{
    char c;
    int cnt;
    int flag;
}a[26], vis[26];

bool cmp(mypair x, mypair y)
{
    return x.cnt > y.cnt;
}

int main()
{
    for (int i = 0; i < 26; i++)
        a[i].c = vis[i].c = 'A' + i, a[i].cnt = vis[i].cnt = vis[i].flag = 0;
    char ch = 0;
    cin >> T >> N;
    for (int i = 0; i < N; i++)
        cin >> ch, a[ch - 'A'].cnt++;

    //sort(a, a + 26, cmp);

    int res = 0;
    while (1)
    {
        sort(a, a + 26, cmp);

        if (a[0].cnt == 0)//都洗完了，结束循环
            break;
        res++;//有人没洗完，就加时间

        for (int i = 0; i < 26; i++)//标记过的计时++
        {
            if (vis[i].flag)
                vis[i].cnt++;
            if (vis[i].cnt > T)
                vis[i].flag = 0, vis[i].cnt = 0;
        }

        for (int i = 0; i < 26; i++)
        {
            if (a[i].cnt == 0)//说明这轮直接轮空，没人洗澡，跳出循环
                break;
            if (!vis[a[i].c - 'A'].flag)
            {
                vis[a[i].c - 'A'].flag = 1;//没标记过先标记
                a[i].cnt--;//卷王数量--
                break;//找到了洗澡的合适人选，跳出循环
            }
            else//被标记过，不能洗，跳过
            {
                continue;
            }
        }
    }

    cout << res << endl;

    return 0;
}