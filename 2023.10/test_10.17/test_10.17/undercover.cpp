#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cout << "������������� n��";
    cin >> n;
    cout << "��������ʵ������ m��";
    cin >> m;

    vector<string> answers(n);

    cout << "������������ҵĻش�" << endl;
    for (int i = 0; i < n; i++) {
        cin >> answers[i];
    }

    // ����ÿ����ҵĻش�
    for (int i = 0; i < n; i++) {
        string answer = answers[i];
        bool truthful = false;
        bool lie = false;

        // ����Ƿ�˵��ʵ��
        if (answer == "+1" || answer == ("+ " + to_string(i + 1))) {
            truthful = true;
        }

        // ����Ƿ�˵�˻���
        if (answer == "-1" || answer == ("- " + to_string(i + 1))) { 
            lie = true;
        }

        // ������
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
