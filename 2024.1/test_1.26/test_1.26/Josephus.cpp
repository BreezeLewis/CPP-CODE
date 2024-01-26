#include <iostream>
#include <list>

void Josephus(int N, int M) {
    // ��ʼ����Ա����б�
    std::list<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }

    // ������ָ��Ȧ�ӵĿ�ʼ
    auto it = people.begin();

    // ��ʼԼɪ������Ĺ���
    while (!people.empty()) {
        // ÿ��ѭ��������M
        for (int count = 1; count < M; ++count) {
            ++it;
            // ��������������б�ľ�ͷ����ת�ص���ʼ
            if (it == people.end()) {
                it = people.begin();
            }
        }

        // �����Ȧ���˵ı��
        std::cout << *it;
        if (people.size() > 1) {
            std::cout << " ";
        }

        // ���б����Ƴ���Ȧ����
        it = people.erase(it);

        // ȷ������������ָ���б�ľ�ͷ
        if (it == people.end()) {
            it = people.begin();
        }
    }

    std::cout << std::endl;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    Josephus(N, M);
    return 0;
}