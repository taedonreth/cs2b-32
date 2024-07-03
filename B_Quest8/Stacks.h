// Student ID: 20586501
// Stacks.h
// 2B-BlueLab-08

#ifndef Stacks_h
#define Stacks_h

#include <vector>
#include <sstream>

class Stack_Int {
private:
    std::vector<int> _data;

public:
    // No explicit constructor or destructor
    size_t size() const {
        return _data.size();
    }

    bool is_empty() const {
        return _data.empty();
    }

    void push(int val) {
        _data.push_back(val);
    }
    
    int top(bool& success) const {
        if (is_empty()) {
            success = false;
            return 0;
        }
        success = true;
        return _data.back();
    }

    bool pop() {
        if (is_empty()) {
            return false;
        }
        _data.pop_back();
        return true;
    }

    bool pop(int& val) {
        if (is_empty()) {
            return false;
        }
        val = _data.back();
        _data.pop_back();
        return true;
    }

    std::string to_string() const {
        std::ostringstream result;

        result << "Stack (" << size() << " elements):\n";

        if (is_empty()) {
            return result.str();
        }

        if (size() > 10) {
            for (size_t i = size(); i > size() - 10; i--) {
                result << _data[i - 1] << "\n";
            }
            result << "...\n";
        } else {
            for (size_t i = size(); i > 0; i--) {
                result << _data[i - 1] << "\n";
            }
        }
        result << "Elements, if listed above, are in increasing order of age.";
        return result.str();
    }

    // Don't remove the following line
    friend class Tests;
};

class Stack_String {
private:
    std::vector<std::string> _data;

public:
    // No explicit constructor or destructor
    size_t size() const {
        return _data.size();
    }

    bool is_empty() const {
        return _data.empty();
    }

    void push(const std::string& word) {
        _data.push_back(word);
    }
    
    std::string top(bool& success) const {
        if (is_empty()) {
            success = false;
            return "";
        }
        success = true;
        return _data.back();
    }

    bool pop() {
        if (is_empty()) {
            return false;
        }
        _data.pop_back();
        return true;
    }

    bool pop(std::string& word) {
        if (is_empty()) {
            return false;
        }
        word = _data.back();
        _data.pop_back();
        return true;
    }

    std::string to_string() const {
        std::ostringstream result;

        result << "Stack (" << size() << " elements):\n";

        if (is_empty()) {
            return result.str();
        }

        if (size() > 10) {
            for (size_t i = size(); i > size() - 10; i--) {
                result << _data[i - 1] << "\n";
            }
            result << "...\n";
        } else {
            for (size_t i = size(); i > 0; i--) {
                result << _data[i - 1] << "\n";
            }
        }
        result << "Elements, if listed above, are in increasing order of age.";
        return result.str();
    }

    // Don't remove the following line
    friend class Tests;
};

#endif /* Stacks_h */