#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
private:
    unordered_map<char, Trie*> children;
    int count;

public:
    Trie() : count(0) {}

    void insert(const string& word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
            node->count++;
        }
    }

    int find(const string& prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (!node->children.count(c)) {
                return 0;
            }
            node = node->children[c];
        }
        return node->count;
    }
};

int main() {
    Trie trie;
    string word;
    while (getline(cin, word) && !word.empty()) {
        trie.insert(word);
    }
    while (getline(cin, word)) {
        cout << trie.find(word) << endl;
    }
    return 0;
}