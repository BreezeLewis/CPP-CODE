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

        if (a[0].cnt == 0)//��ϴ���ˣ�����ѭ��
            break;
        res++;//����ûϴ�꣬�ͼ�ʱ��

        for (int i = 0; i < 26; i++)//��ǹ��ļ�ʱ++
        {
            if (vis[i].flag)
                vis[i].cnt++;
            if (vis[i].cnt > T)
                vis[i].flag = 0, vis[i].cnt = 0;
        }

        for (int i = 0; i < 26; i++)
        {
            if (a[i].cnt == 0)//˵������ֱ���ֿգ�û��ϴ�裬����ѭ��
                break;
            if (!vis[a[i].c - 'A'].flag)
            {
                vis[a[i].c - 'A'].flag = 1;//û��ǹ��ȱ��
                a[i].cnt--;//��������--
                break;//�ҵ���ϴ��ĺ�����ѡ������ѭ��
            }
            else//����ǹ�������ϴ������
            {
                continue;
            }
        }
    }

    cout << res << endl;

    return 0;
}