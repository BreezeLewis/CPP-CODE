#include <iostream>
#include <vector>
using namespace std;

// �жϸ����� m �Ƿ��ܱ�֤���л��˱�ִ���ں���֮ǰ
bool is_valid_m(int k, int m) {
    int total = 2 * k;  // ������
    int pos = 0;  // ��ǰִ��λ��
    for (int i = 0; i < k; ++i) {
        pos = (pos + m - 1) % (total - i);  // �ҵ���һ��ִ�е�λ��
        if (pos < k) return false;  // ���ִ�е��Ǻ��ˣ�m������
    }
    return true;  // ������л��˶��ȱ�ִ�У�����true
}

int find_min_m(int k) {
    int m = k + 1;  // m��СΪk+1����Ϊm=kʱ�����˲������ȱ�ִ��
    while (!is_valid_m(k, m)) {
        ++m;
    }
    return m;  // �����ҵ�����Сm
}

int main() {
    int k;
    while (cin >> k && k != 0) {
        cout << find_min_m(k) << endl;;;
    }
    return 0;
}
