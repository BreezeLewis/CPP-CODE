// ��ȡֵ���������ʵ�Ԫ���Ƶ����ʹ�õ�λ��
int get(int key) {
    auto it = cache.find(key);

    // ���key������
    if (it == cache.end()) {
        return -1;
    }

    // �����ʵ�Ԫ���Ƶ�����β�������ʹ�ã�
    lruList.splice(lruList.end(), lruList, it->second);

    // ����ֵ
    return it->second->second;
}

// ��ӻ���¼�ֵ��
void put(int key, int value) {
    auto it = cache.find(key);

    // ���key�Ѵ���
    if (it != cache.end()) {
        // ����ֵ���Ƶ�����β��
        it->second->second = value;
        lruList.splice(lruList.end(), lruList, it->second);
        return;
    }

    // �����������
    if (cache.size() >= capacity) {
        // ɾ���������ʹ�õ�Ԫ�أ�����ͷ����
        int delKey = lruList.front().first;
        cache.erase(delKey);
        lruList.pop_front();
    }

    // �����Ԫ�ص�����β��
    lruList.push_back({ key, value });
    // ���¹�ϣ��ӳ��
    cache[key] = std::prev(lruList.end());
}