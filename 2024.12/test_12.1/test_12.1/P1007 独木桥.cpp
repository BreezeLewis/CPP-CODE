#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int sizes = 5005;
int a[sizes];
int main()
{
    int L, N;
    cin >> L >> N;
    if (!N) //���� N==0����� 
    {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) cin >> a[i]; //����
    sort(a + 1, a + N + 1); //��С�����������ʱ��ʱ���ܷ���һЩ��
    int max_time, min_time;
    for (int i = 1; i <= N; i++)
        min_time = max(min(a[i], L + 1 - a[i]), min_time); //���ʱ���������������������Сֵ�е����ֵ 
    max_time = max(L + 1 - a[1], a[N]); //�ʱ���������˵������˸�����Է���,
    //ʱ��ϳ����Ǹ��˵�ʱ�� ������ĺô���
    cout << min_time << ' ' << max_time << endl;
    return 0;
}