#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    string output;
    for (char c : input) {
        if (c == '5') {
            output += '2'; // �� -> ����
        }
        else if (c == '2') {
            output += '0'; // ���� -> ʯͷ
        }
        else if (c == '0') {
            output += '5'; // ʯͷ -> ��
        }
    }

    cout << output << endl;
    return 0;
}
