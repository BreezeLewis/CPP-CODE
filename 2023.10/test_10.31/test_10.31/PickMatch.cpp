#include <iostream>
using namespace std;

int main()
{
    int n = 21, x;

    cout << "-------------------------------------------" << endl;
    cout << "|        �㲻��սʤ�ң���������           |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "��Ϸ��ʼ��\n" << endl;
    while (true)
    {
        cout << "\n--------- Ŀǰ�� " << n << " ����� --------" << endl;
        cout << "��������ȡ�û��";
        cin >> x;
        if (x < 1 || x>4 || x > n)
        {
            cout << "��Υ���ˣ���ȡ�Ļ���������⣡" << endl;
            continue;
        }
        n = n - x;
        if (n <= 0)
        {
            cout << "\n���ź��������ˣ���Ϸ������" << endl;
            break;
        }
        cout << "    �����ȡ " << (5 - x) << " �����" << endl;
        n = n - (5 - x);
        if (n <= 0)
        {
            cout << "\n��ϲ�㣬��Ӯ�ˣ���Ϸ������" << endl;
            break;
        }
    }
}
