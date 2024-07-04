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
        _head = new Node("_SENTINEL_");
        _tail = _head;
        _prev_to_current = _head;
        _size = 0;
    }

    ~String_List() {
        clear();
        delete _head;
    }

    String_List* insert_at_current(std::string s) {
        Node* new_node = new Node(s);

        new_node->next = _prev_to_current->next;
        _prev_to_current->next = new_node;

        if (_prev_to_current == _tail) {
            _tail = new_node;
        }

        _size++;

        return this;
    }

    String_List *push_front(std::string s) {
        Node *saved_prev_to_current = _prev_to_current;

        _prev_to_current = _head;
        insert_at_current(s);
        _prev_to_current = saved_prev_to_current;

        return this;
    }

    String_List *push_back(std::string s) {
        Node *saved_prev_to_current = _prev_to_current;

        _prev_to_current = _tail;
        insert_at_current(s);
        _prev_to_current = saved_prev_to_current;
        
        return this;
    }

    String_List* advance_current() {
        if (_prev_to_current->next == nullptr) {
            return nullptr;
        }
        _prev_to_current = _prev_to_current->next;
        return this;
    }


    std::string get_current() const {
        if (_prev_to_current->next == nullptr) {
            return "_SENTINEL_";
        }
        return _prev_to_current->next->data;
    }

    String_List *remove_at_current() {
        Node* temp = _prev_to_current->next;

        if (temp == nullptr) {
            return this;
        }

        if (temp == _tail) {
            _tail = _prev_to_current;
        }

        _prev_to_current->next = temp->next;
        delete temp;
        _size--;
        return this;
    }

    size_t get_size() const {
        return _size;
    }

    String_List *rewind() {
        _prev_to_current = _head;
        return this;
    }

    void clear() {
        Node* current = _head->next;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }

        _tail = _head;
        _prev_to_current = _head;
        _head->next = nullptr;
        _size = 0;
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
        static std::string sentinel = "_SENTINEL_";

        Node* current = _head->next;
        while (current != nullptr) {
            if (current->data == s) {
                return current->data;
            }
            current = current->next;
        }
        return sentinel;
    }

    // Print up to max_lines lines starting at _prev_to_current->next. If the caller
    // wants to print from the beginning of the list, they should rewind() it first.
    //
    std::string to_string() const {
        std::ostringstream result;
        result << "# String_List - " << _size << " entries total. Starting at cursor:";

        Node *current = _prev_to_current->next;
        int count = 0;
        while (current != nullptr && count < 25) {
            result << "\n" << current->data;
            current = current->next;
            count++;
        }
        if (current != nullptr) {
            result << "\n...";
        }
        result << "\n";
        return result.str();
    }

    friend class Tests; // Don't remove this line
};

#endif /* String_List_h */