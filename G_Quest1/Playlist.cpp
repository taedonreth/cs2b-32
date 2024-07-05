// Student ID: 20586501
// Playlist.cpp
// 2B-GreenLab-01

#include <iostream>
#include <sstream>

#include "Playlist.h"

using namespace std;

bool Playlist::Song_Entry::set_id(int id) {
    if (id < 0) {
        return false;
    }
    _id = id;
    return true;
}


bool Playlist::Song_Entry::set_name(string name) {
    if (name.empty()) {
        return false;
    }
    _name = name;
    return true;
}

Playlist::Node* Playlist::Node::insert_next(Node *p) {
    if (p != nullptr) {
        p->_next = this->_next;
        this->_next = p;
    }
    return p;
}

Playlist::Node* Playlist::Node::remove_next() {
    if (this->_next != nullptr) {
        Node* temp = this->_next;
        this->_next = temp->get_next(); // Bypass the node to be removed
        temp->_next = nullptr;          // Clear the next pointer of the removed node
        delete temp;                    // Free the memory of the removed node
    }
    return this; // Return a pointer to the current node
}

Playlist::Playlist() {
    _head = new Node(Song_Entry(-1, "HEAD"));
    _tail = _head;
    _prev_to_current = _head;
    _size = 0;
}

Playlist::~Playlist() {
    clear();
    delete _head;
    return;
}


Playlist* Playlist::insert_at_cursor(const Playlist::Song_Entry& s) {
    Node* new_node = new Node(s);

    new_node->set_next(_prev_to_current->get_next());
    _prev_to_current->set_next(new_node);

    if (_prev_to_current == _tail) {
        _tail = new_node;
    }

    _size++;
    return this;
}

Playlist* Playlist::push_back(const Song_Entry& s) {
    Node *saved_prev_to_current = _prev_to_current;

    _prev_to_current = _tail;
    insert_at_cursor(s);
    _prev_to_current = saved_prev_to_current;
        
    return this;
}

Playlist* Playlist::push_front(const Song_Entry& s) {
    Node *saved_prev_to_current = _prev_to_current;

    _prev_to_current = _head;
    insert_at_cursor(s);
    _prev_to_current = saved_prev_to_current;

    return this;
}

Playlist* Playlist::advance_cursor() {
    if (_prev_to_current == _tail) {
        return nullptr;
    }
    _prev_to_current = _prev_to_current->get_next();
    return this;
}

Playlist* Playlist::circular_advance_cursor() {
    if (_prev_to_current->get_next() == _tail) {
        _prev_to_current = _head;
    } else {
    _prev_to_current = _prev_to_current->get_next();
    }
    return this;
}

Playlist::Song_Entry& Playlist::get_current_song() const {
    if (_prev_to_current == _tail) {
        return this->_head->get_song();
    }
    return _prev_to_current->get_next()->get_song();
}

Playlist* Playlist::remove_at_cursor() {
    Node* temp = _prev_to_current->get_next();

    if (temp == nullptr) {
        return this;
    }

    if (temp == _tail) {
        _tail = _prev_to_current;
    }

    _prev_to_current->set_next(temp->get_next());
    delete temp;
    _size--;
    return this;
    }

Playlist* Playlist::rewind() {
    _prev_to_current = _head;
    return this;
}

Playlist* Playlist::clear() {
    Node* curr = _head->get_next();
    while (curr != nullptr) {
        Node* temp = curr->get_next();
        curr->set_next(nullptr);
        delete curr;
        curr = temp;
    }
    _tail = _head;
    _prev_to_current = _head;
    _head->set_next(nullptr);
    _size = 0;
    return this;
}

Playlist::Song_Entry& Playlist::find_by_id(int id) const {
    Node* current = _head->get_next();
    while (current != nullptr) {
        if (current->get_song().get_id() == id) {
            return current->get_song();
        }
        current = current->get_next();
    }
    return this->_head->get_song();
}

Playlist::Song_Entry& Playlist::find_by_name(string name) const {
    Node* current = _head->get_next();
    while (current != nullptr) {
        if (current->get_song().get_name() == name) {
            return current->get_song();
        }
        current = current->get_next();
    }
    return this->_head->get_song();
}

string Playlist::to_string() const {
    ostringstream result;
    result << "Playlist: " << _size << " entries.";

    Node *current = _prev_to_current->get_next();
    int count = 0;
    while (current != nullptr && count < 25) {
        result << "\n{ id: " << current->get_song().get_id() << ", name: " << current->get_song().get_name() << " }";
        
        if (current == _prev_to_current) {
            result << " [P]";
        }
        if (current == _tail) {
            result << " [T]";
        }

        current = current->get_next();
        count++;
    }

    if (current != nullptr) {
        result << "\n...";
    }

    result << "\n";
    return result.str();
}
