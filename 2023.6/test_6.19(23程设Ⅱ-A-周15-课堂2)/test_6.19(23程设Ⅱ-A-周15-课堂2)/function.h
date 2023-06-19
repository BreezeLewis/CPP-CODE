#include <iostream>

void insert(std::map<std::string, int>& m, const std::string& key, int val) {
    m.insert({ key, val });
}

void insert(std::map<std::string, int>& m, const std::pair<std::string, int>& p) {
    m.insert(p);
}

std::map<std::string, int>::iterator find(std::map<std::string, int>& m, const std::string& key) {
    return m.find(key);
}

void erase(std::map<std::string, int>& m, const std::string& key) {
    m.erase(key);
}

void erase(std::map<std::string, int>& m, std::map<std::string, int>::iterator& pos) {
    m.erase(pos);
}

void print(const std::map<std::string, int>& m) {
    std::cout << "{";
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << ": " << it->second;
        if (it != --m.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}