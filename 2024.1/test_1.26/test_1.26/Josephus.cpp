#include <iostream>
#include <list>

void Josephus(int N, int M) {
    // 初始化人员编号列表
    std::list<int> people;
    for (int i = 1; i <= N; ++i) {
        people.push_back(i);
    }

    // 迭代器指向圈子的开始
    auto it = people.begin();

    // 开始约瑟夫问题的过程
    while (!people.empty()) {
        // 每次循环报数到M
        for (int count = 1; count < M; ++count) {
            ++it;
            // 如果迭代器到了列表的尽头，则转回到开始
            if (it == people.end()) {
                it = people.begin();
            }
        }

        // 输出出圈的人的编号
        std::cout << *it;
        if (people.size() > 1) {
            std::cout << " ";
        }

        // 从列表中移除出圈的人
        it = people.erase(it);

        // 确保迭代器不会指向列表的尽头
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