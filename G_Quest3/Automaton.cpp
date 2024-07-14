// Student ID: 20586501
// Automaton.cpp
// 2B-GreenLab-03

#include "Automaton.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Automaton::Automaton(size_t num_parents, size_t rule) {
    _num_parents = num_parents;
    _rules.resize(1 << num_parents);

    if (!set_rule(rule)) {
        _is_valid = false;
        return;
    }

    _is_valid = true;
    _extreme_bit = 0;
}

size_t Automaton::translate_n_bits_starting_at(const std::vector<int>& bits, size_t pos, size_t n) {
    if ((pos + n) > bits.size()) {
        return 0;
    }
    
    size_t result = 0;
    for (size_t i = 0; i < n; ++i) {
        result = (result << 1) | bits[pos + i];
    }

    return result;
}

string Automaton::generation_to_string(const vector<int>& gen, size_t width) {
    if (width % 2 == 0) {
        return "";
    }

    stringstream temp;
    for (size_t i = 0; i < gen.size(); ++i) {
        if (gen[i] == 1) {
            temp << '*';
        } else if (gen[i] == 0) {
            temp << ' ';
        }
    }

    string temp_str = temp.str();

    int padding = 0;
    if (width > temp_str.length()) {
        padding = (width - temp_str.length()) / 2;
    }
    stringstream result;
    char padChar;
    if (_extreme_bit == 1) {
        padChar = '*';
    } else {
        padChar = ' ';
    }
    result << string(padding, padChar) << temp_str << string(padding, padChar);

    if (result.str().length() < width) {
        result << padChar;
    }

    return result.str();
}

bool Automaton::set_rule(size_t rule) {
    if (_num_parents > MAX_PARENTS) {
        return false;
    }

    size_t max_rule_value = (1 << (1 << _num_parents)) - 1;
    if (rule > max_rule_value) {
        return false;
    }

    for (size_t i = 0; i < _rules.size(); i++) {
        _rules[i] = (rule & (1 << i)) != 0;
    }
    return true;
}

bool Automaton::equals(const Automaton& that) {
    // both are invalid -> they are equal
    if (!this->_is_valid && !that._is_valid) {
        return true;
    } 
    // exact same properties
    if ((this->_is_valid) && (that._is_valid) && 
        (this->_num_parents == that._num_parents) && 
        (this->_extreme_bit == that._extreme_bit) && 
        (this->_rules == that._rules)) {
        return true;
    }

    // else, return unequal
    return false;
}

bool Automaton::make_next_gen(const vector<int>& current_gen, vector<int>& next_gen) {
    // Ensure the automaton is valid and the current generation length is not even (except for length 0)
    if (!_is_valid || (current_gen.size() % 2 == 0 && current_gen.size() != 0)) {
        return false;
    }

    next_gen.clear();

    // Handle the case where the current generation length is 0
    if (current_gen.empty()) {
        next_gen.push_back(1);
        _extreme_bit = 0;  // Reset extreme bit for the new generation
        return true;
    }

    // Determine the number of bits to pad on each side
    int padding_size = (_num_parents - 1) / 2;

    // Process the main window of non-extreme bits
    for (size_t i = 0; i < current_gen.size(); ++i) {
        int left, center, right;

        // Determine left, center, and right bits for current index i
        if (i == 0) {
            left = _extreme_bit;
        } else {
            left = current_gen[i - 1];
        }

        center = current_gen[i];

        if (i == current_gen.size() - 1) {
            right = _extreme_bit;
        } else {
            right = current_gen[i + 1];
        }

        // Compute the combination index
        int combination = (left << 2) | (center << 1) | right;

        // Append the next bit to next_gen
        next_gen.push_back(_rules[combination]);
    }

    // If the next generation size is less than the required size, pad with the extreme bit
    while (next_gen.size() < current_gen.size() + 2 * padding_size) {
        next_gen.insert(next_gen.begin(), _extreme_bit);
        next_gen.push_back(_extreme_bit);
    }

    // Update the extreme bit for the next generation
    _extreme_bit = _rules[(_extreme_bit << 2) | (_extreme_bit << 1) | _extreme_bit];

    return true;
}



string Automaton::get_first_n_generations(size_t n, size_t width) {
    // Preliminary checks: width is 0, even, or invalid automaton
    if (width == 0 || width % 2 == 0 || !_is_valid) {
        return "";
    }
    
    vector<int> current_gen = {1};
    vector<int> next_gen;
    stringstream result;

    // Generate n generations
    for (size_t gen = 0; gen < n; ++gen) {
        // Convert the current generation to string and add to the result
        result << generation_to_string(current_gen, width) << '\n';

        // Generate the next generation
        if (!make_next_gen(current_gen, next_gen)) {
            return "";
        }

        // Swap current_gen and next_gen for the next iteration
        current_gen.swap(next_gen);
    }

    return result.str();
}