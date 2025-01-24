// 获取值，并将访问的元素移到最近使用的位置
int get(int key) {
    auto it = cache.find(key);

    // 如果key不存在
    if (it == cache.end()) {
        return -1;
    }

    // 将访问的元素移到链表尾部（最近使用）
    lruList.splice(lruList.end(), lruList, it->second);

    // 返回值
    return it->second->second;
}

// 添加或更新键值对
void put(int key, int value) {
    auto it = cache.find(key);

    // 如果key已存在
    if (it != cache.end()) {
        // 更新值并移到链表尾部
        it->second->second = value;
        lruList.splice(lruList.end(), lruList, it->second);
        return;
    }

    // 如果缓存已满
    if (cache.size() >= capacity) {
        // 删除最近最少使用的元素（链表头部）
        int delKey = lruList.front().first;
        cache.erase(delKey);
        lruList.pop_front();
    }

    // 添加新元素到链表尾部
    lruList.push_back({ key, value });
    // 更新哈希表映射
    cache[key] = std::prev(lruList.end());
}