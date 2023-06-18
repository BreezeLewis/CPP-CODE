//#include <vector>

void push_back(std::vector<std::string>& v, const std::string& str) {
    v.push_back(str);
}

void insert(std::vector<std::string>& v, const std::vector<std::string>::iterator& pos, const std::string& str) {
    v.insert(pos, str);
}

void print(std::vector<std::string>& v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void erase(std::vector<std::string>& v, const std::vector<std::string>::iterator& pos) {
    v.erase(pos);
}

void pop_back(std::vector<std::string>& v) {
    v.pop_back();
}