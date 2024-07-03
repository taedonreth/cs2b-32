// Student ID: 20586501
// String_List.h
// 2B-BlueLab-09

#ifndef String_List_h
#define String_List_h

#include <iostream>
#include <sstream>

// Important implementation note: With the exception of to_string(),
// find*() and clear(), all list methods below should operate in a constant amount
// of time regardless of the size of the String_List instance.
//
// The semantics of _prev_to_current is such that it always points to the
// node *BEFORE* the current one. This makes the manipulations easy because
// we can only look forward (and not back) in singly linked lists.
//
// I've included some method header comments below where there's likely to
// be confusion.
//
class String_List {
private:
    struct Node {
        std::string data;
        Node *next;
        Node(std::string s = "") : data(s), next(nullptr) {}
    };

    Node *_head, *_tail, *_prev_to_current;
    size_t _size;

public:
    String_List() {
        
    }

    ~String_List() {
        
    }

    String_List *insert_at_current(std::string s) {
    // TODO - Your code here
    }

    String_List *push_back(std::string s) {
    // TODO - Your code here
    }

    String_List *push_front(std::string s) {
    // TODO - Your code here
    }

    String_List *advance_current() {
    // TODO - Your code here
    }

    std::string get_current() const {
    // TODO - Your code here
    }

    String_List *remove_at_current() {
    // TODO - Your code here
    }

    size_t get_size() const {
    // TODO - Your code here
    }

    String_List *rewind() {
    // TODO - Your code here
    }

    void clear() {
    // TODO - Your code here
    }

    // Find a specific item. Does NOT change cursor.
    //
    // The following returns a reference to the target string if found. But what will
    // you do if you didn't find the requested string? Using sentinel markers is
    // one way to handle that situation. Usually there's only one copy of the
    // sentinel that's global. We will use a local one so it's cleaner with a
    // little more risk (what's the risk?)
    //
    std::string& find_item(std::string s) const {
    // TODO - Your code here
    }

    // Print up to max_lines lines starting at _prev_to_current->next. If the caller
    // wants to print from the beginning of the list, they should rewind() it first.
    //
    std::string to_string() const {
    // TODO - Your code here
    }

    friend class Tests; // Don't remove this line
};

#endif /* String_List_h */