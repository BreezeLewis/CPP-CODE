#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    string output;
    for (char c : input) {
        if (c == '5') {
            output += '2'; // 布 -> 剪刀
        }
        else if (c == '2') {
            output += '0'; // 剪刀 -> 石头
        }
        else if (c == '0') {
            output += '5'; // 石头 -> 布
        }
    }

    cout << output << endl;
    return 0;
}
