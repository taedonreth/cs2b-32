// Student ID: 20586501
// Trie.cpp
// 2B-GreenLab-08

#include "Trie.h"

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

Trie::Trie() {
    _root = new Trie::Node();
}

void Trie::Node::insert(string s) {
    Trie::Node* curr = this;
    for (char ch : s) {
        if (static_cast<size_t>(ch) >= curr->next.size())
            curr->next.resize(ch + 1);

        if (curr->next[ch] == nullptr)
            curr->next[ch] = new Trie::Node;

        curr = curr->next[ch];
    }

    if (curr->next.empty())
        curr->next.resize(1);

    if (curr->next[0] == nullptr)
        curr->next[0] = new Trie::Node;
}

const Trie::Node* Trie::Node::traverse(string s) const {
    const Trie::Node* curr = this;
    for (char ch : s) {
        if (static_cast<size_t>(ch) < curr->next.size() && curr->next[ch] != nullptr) {
            curr = curr->next[ch];
        } else {
            return nullptr;
        }
    }
    return curr;
}

bool Trie::Node::lookup(string s) const {
    const Node* result_node = traverse(s);
    return result_node != nullptr && result_node->next[0] != nullptr;
}

Trie::~Trie() {
    delete _root;
    _root = nullptr;
}

Trie::Node::~Node() {
    static int r_depth = 0;
    cout << "~Node() Recursion depth " << ++r_depth << endl;

    for (auto& child : next) {
        if (child != nullptr) {
            cout << "~Node() Descending from depth " << r_depth << endl;
            delete child;
            child = nullptr;
        }
    }

    next.clear();
    cout << "~Node() back to depth " << --r_depth << endl;
}

size_t Trie::Node::get_completions(vector<string>& completions, size_t limit) const {
    completions.clear();
    if (limit == 0) {
        return 0;
    }

    struct Continuation {
        const Trie::Node* node;
        string partial;
        Continuation(const Node* n, const string& p) : node(n), partial(p) {}
    };

    queue<Continuation> unprocessed_nodes;
    unprocessed_nodes.emplace(this, "");

    while (!unprocessed_nodes.empty()) {
        Continuation cont = unprocessed_nodes.front();
        unprocessed_nodes.pop();

        for (size_t i = 0; i < cont.node->next.size(); ++i) {
            if (i == 0 && cont.node->next[0] != nullptr) {
                completions.push_back(cont.partial);
                if (completions.size() >= limit) {
                    return completions.size();
                }
            } else if (cont.node->next[i] != nullptr) {
                unprocessed_nodes.emplace(cont.node->next[i], cont.partial + static_cast<char>(i));
            }
        }
    }

    return completions.size();
}

size_t Trie::get_completions(string s, vector<std::string>& completions, size_t limit) const {
    const Node* result_node = _root->traverse(s);
    if (result_node == nullptr) {
        return 0;
    }
    return result_node->get_completions(completions, limit);
}

string Trie::to_string(size_t limit) const {
    string output = "# Trie contents\n";
    vector<string> completions;
    size_t completion_num = get_completions("", completions, limit + 1);

    if (completion_num < limit) {
        limit = completion_num;
    }

    for (size_t i = 0; i < limit; ++i) {
        if (!completions[i].empty()) {
            output += completions[i] + "\n";
        }
    }

    if (completions.size() > limit) {
        output += "...\n";
    }

    return output;
}

size_t Trie::trie_sort(vector<string>& vec) const {
    vec.clear();
    size_t trie_size = get_completions("", vec, 10000);
    vec.resize(trie_size);
    return trie_size;
}