// Student ID: 20586501
// Trie.h
// 2B-GreenLab-08

#ifndef Trie_h
#define Trie_h

#include <string>
#include <vector>
#include <iostream>
#include <queue>

class Trie {
private:
    struct Node {
        std::vector<Trie::Node *> next;

        ~Node();

        void insert(std::string s);
        const Node *traverse(std::string s) const;
        bool lookup(std::string s) const;
        size_t get_completions(std::vector<std::string>& completions, size_t limit) const;
    } *_root;

    // Private Trie:: helper. Returns the interior node traversing s from _root
    const Node *traverse(std::string s) const { return _root->traverse(s); }

public:
    Trie();
    ~Trie();

    void insert(std::string s) { _root->insert(s); }
    bool lookup(std::string s) const { return _root->lookup(s); }
    size_t get_completions(std::string s, std::vector<std::string>& completions, size_t limit) const;
    size_t trie_sort(std::vector<std::string>& vec) const;

    std::string to_string(size_t n) const;
    std::ostream& operator<<(std::ostream& os) { return os << to_string(100); }

    friend class Tests; // Don't remove
};

#endif /*Trie_h*/
