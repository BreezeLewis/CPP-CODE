#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cout << "请输入玩家数量 n：";
    cin >> n;
    cout << "请输入真实答案数量 m：";
    cin >> m;

    vector<string> answers(n);

    cout << "请依次输入玩家的回答：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> answers[i];
    }

    // 处理每个玩家的回答
    for (int i = 0; i < n; i++) {
        string answer = answers[i];
        bool truthful = false;
        bool lie = false;

        // 检查是否说了实话
        if (answer == "+1" || answer == ("+ " + to_string(i + 1))) {
            truthful = true;
        }

        // 检查是否说了谎言
        if (answer == "-1" || answer == ("- " + to_string(i + 1))) { 
            lie = true;
        }

        // 输出结果
        if (truthful && m > 0) {
            cout << "truth" << endl;
            m--;
        }
        else if (lie) {
            cout << "lie" << endl;
        }
        else {
            cout << "not defined" << endl;
        }
    }

    return 0;
}
