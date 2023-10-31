#include <iostream>
using namespace std;

int main()
{
    int n = 21, x;

    cout << "-------------------------------------------" << endl;
    cout << "|        你不能战胜我，不信试试           |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "游戏开始：\n" << endl;
    while (true)
    {
        cout << "\n--------- 目前有 " << n << " 根火柴 --------" << endl;
        cout << "请输入你取得火柴：";
        cin >> x;
        if (x < 1 || x>4 || x > n)
        {
            cout << "你违规了，你取的火柴数有问题！" << endl;
            continue;
        }
        n = n - x;
        if (n <= 0)
        {
            cout << "\n很遗憾，你输了！游戏结束！" << endl;
            break;
        }
        cout << "    计算机取 " << (5 - x) << " 根火柴" << endl;
        n = n - (5 - x);
        if (n <= 0)
        {
            cout << "\n恭喜你，你赢了！游戏结束！" << endl;
            break;
        }
    }
}
