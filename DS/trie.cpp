#include <bits/stdc++.h>
using namespace std;


class Trie {
public:

    void append(const string& s) {
        Node* cur = root;
        for (char c: s) {
            ++cur->cnt;
            if (!cur->childs[c]) {
                cur->childs[c] = new Node();
            }
            cur = cur->childs[c];
        } 
    }

    int process(const string& s) {
        int count = 0;
        Node* cur = root;
        for (char c: s) {
            count += cur->cnt;
            if (cur->childs[c]) {
                cur = cur->childs[c];
            }
            else break;
        }
        return count;
    }

private:

    struct Node {
        map<char, Node*> childs;
        int cnt = 0;

    } *root; 
};
