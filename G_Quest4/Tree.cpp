// Student ID: 20586501
// Tree.cpp
// 2B-GreenLab-04

#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"

using namespace std;

Tree::Node::~Node() {
    while (_sibling != nullptr) {
        Node* temp = _sibling;
        _sibling = _sibling->_sibling;
        delete temp;
    }
    while (_child != nullptr) {
        Node* temp = _child;
        _child = _child->_sibling;
        delete temp;
    }
}

Tree::Node* Tree::Node::insert_sibling(Node* p) {
    if (_sibling == nullptr) {
        _sibling = p;
    } else {
        _sibling->insert_sibling(p);
    }
    return p;
}

Tree::Node* Tree::Node::insert_child(Node* p) {
    if (_child == nullptr) {
        _child = p;
    } else {
        _child->insert_sibling(p);
    }
    return p;
}

const Tree::Node& Tree::Node::operator=(const Tree::Node& that) {
    if (this != &that) {
        delete _child;
        delete _sibling;
        if (that._child == nullptr) {
            _child = nullptr;
        } else {
            _child = new Node(*that._child);
        }
        if (that._sibling == nullptr) {
            _sibling = nullptr;
        } else {
            _sibling = new Node(*that._sibling);
        }
        _data = that._data;
    }
    return *this;
}

Tree::Node::Node(const Node& that) : _data(that._data), _sibling(nullptr), _child(nullptr) {
    *this = that;
}

bool Tree::Node::is_equal(const Node* p1, const Node* p2) {
    if (p1 == nullptr && p2 == nullptr) {
        return true;
    } else if (p1 != nullptr && p2 != nullptr && *p1 == *p2) {
        return true;
    }
    return false;
}

bool Tree::Node::operator==(const Node& that) const {
    if (_data != that._data) return false;

    bool result = is_equal(_child, that._child) && is_equal(_sibling, that._sibling);
    return result;
}

bool Tree::Node::operator!=(const Node& that) const {
    return !(*this == that);
}

string Tree::Node::to_string() const {
    string output = _data + " :";
    if (_child != nullptr) {
        Node* temp = _child;
        output += " " + temp->_data;
        while (temp->_sibling != nullptr) {
            temp = temp->_sibling;
            output += " " + temp->_data;
        }
    }

    output += "\n";
    if (_child != nullptr) {
        output += "# Child of " + _data + "\n";
        output += _child->to_string();
    }
    if (_sibling != nullptr) {
        output += "# Next sib of " + _data + "\n";
        output += _sibling->to_string();
    }
    return output;
}

Tree& Tree::operator=(const Tree& that) {
    if (this != &that) {
        delete _root;
        _root = new Node(*that._root);
    }
    return *this;
}

string Tree::to_string() const {
    string output = "# Tree rooted at " + _root->_data + "\n";
    output += "# The following lines are of the form:\n";
    output += "#   node: child1 child2...\n";
    output += _root->to_string();
    output += "# End of Tree\n";
    return output;
}

void Tree::make_special_config_1(const vector<string>& names) {
    Node* root_sib;
    Node* root_sib_child;

    _root->insert_sibling(new Node(names[0]));
    root_sib = _root->_sibling; // AABA
    root_sib->insert_child(new Node(names[4]));
    root_sib_child = root_sib->_child; // COBO
    root_sib_child->insert_child(new Node(names[12]));
    root_sib_child->insert_sibling(new Node(names[5]));
    root_sib_child = root_sib_child->_sibling; // COCO
    root_sib_child->insert_child(new Node(names[13]));

    root_sib->insert_sibling(new Node(names[1]));
    root_sib = root_sib->_sibling; // ABAB
    root_sib->insert_child(new Node(names[6]));
    root_sib_child = root_sib->_child; // CODO
    root_sib_child->insert_child(new Node(names[14]));
    root_sib_child->insert_sibling(new Node(names[7]));
    root_sib_child = root_sib_child->_sibling; // COFO
    root_sib_child->insert_child(new Node(names[15]));

    root_sib->insert_sibling(new Node(names[2]));
    root_sib = root_sib->_sibling; // ABBA
    root_sib->insert_child(new Node(names[8]));
    root_sib_child = root_sib->_child; // COGO
    root_sib_child->insert_child(new Node(names[16]));
    root_sib_child->insert_sibling(new Node(names[9]));
    root_sib_child = root_sib_child->_sibling; // COHO
    root_sib_child->insert_child(new Node(names[17]));

    root_sib->insert_sibling(new Node(names[3]));
    root_sib = root_sib->_sibling; // BABA
    root_sib->insert_child(new Node(names[10]));
    root_sib_child = root_sib->_child; // COJO
    root_sib_child->insert_child(new Node(names[18]));
    root_sib_child->insert_sibling(new Node(names[11]));
    root_sib_child = root_sib_child->_sibling; // COKO
    root_sib_child->insert_child(new Node(names[19]));
}
