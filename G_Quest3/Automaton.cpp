// Student ID: 20586501
// Automaton.cpp
// 2B-GreenLab-03

#include "Automaton.h"
#include <string>
#include <vector>

using namespace std;

Automaton::Automaton(size_t num_parents, size_t rule) {
    if (num_parents <= MAX_PARENTS) {
        _is_valid = true;
        _num_parents = num_parents;
        set_rule(rule);
    } else {
        _is_valid = false;
        _num_parents = 0;
    }
    _extreme_bit = 0;
}

bool Automaton::set_rule(size_t rule) {
    _rules.clear();
    _rules.resize(pow_2(_num_parents));

    if (_num_parents > MAX_PARENTS || rule >= pow_2(pow_2(_num_parents))) {
        _is_valid = false;
        return false;
    }

    for (size_t i = 0; rule > 0; ++i) {
        _rules[i] = rule % 2;
        rule /= 2;
    }

    _is_valid = true;
    return true;
}

bool Automaton::equals(const Automaton& that) {
    if (!_is_valid && !that._is_valid) {
        return true;
    }

    if (_is_valid && that._is_valid &&
        _num_parents == that._num_parents &&
        _extreme_bit == that._extreme_bit &&
        _rules == that._rules) {
        return true;
    }

    return false;
}

bool Automaton::make_next_gen(const vector<int>& current_gen, vector<int>& next_gen) {
    if (!_is_valid || (current_gen.size() % 2 == 0 && !current_gen.empty())) {
        return false;
    }

    if (current_gen.empty()) {
        next_gen = {1};
        _extreme_bit = 0;
    } else {
        vector<int> temp(current_gen);

        // Pad with extreme bits
        temp.insert(temp.begin(), _num_parents - 1, _extreme_bit);
        temp.insert(temp.end(), _num_parents - 1, _extreme_bit);

        next_gen.resize(current_gen.size() + _num_parents - 1);

        for (size_t i = 0; i < next_gen.size(); ++i) {
            next_gen[i] = _rules[translate_n_bits_starting_at(temp, i, _num_parents)];
        }

        if (_extreme_bit) {
            _extreme_bit = _rules.back();
        } else {
            _extreme_bit = _rules.front();
        }
    }

    return true;
}

string Automaton::get_first_n_generations(size_t n, size_t width) {
    string result;

    if (!_is_valid || width % 2 == 0) {
        return result;
    }

    vector<int> temp;

    while (n--) {
        make_next_gen(temp, temp);
        result += generation_to_string(temp, width) + "\n";
    }

    return result;
}

string Automaton::generation_to_string(const vector<int>& gen, size_t width) {
    string result;

    if (!_is_valid || width % 2 == 0) {
        return result;
    }

    size_t gen_size = gen.size();
    string extreme_bit_char = " ";
    if (_extreme_bit) {
        extreme_bit_char = "*";
    }

    if (gen_size > width) {
        size_t start = (gen_size - width) / 2;
        size_t end = start + width;
        for (size_t i = start; i < end; ++i) {
            if (gen[i]) {
                result += "*";
            } else {
                result += " ";
            }
        }
    } else {
        size_t pad_size = (width - gen_size) / 2;
        result.append(pad_size, extreme_bit_char[0]);
        for (const int bit : gen) {
            if (bit) {
                result += "*";
            } else {
                result += " ";
            }
        }
        result.append(pad_size, extreme_bit_char[0]);
    }

    return result;
}

size_t Automaton::translate_n_bits_starting_at(const vector<int>& bits, size_t pos, size_t n) {
    size_t result = 0;

    if (pos + n <= bits.size()) {
        for (size_t i = pos; i < pos + n; ++i) {
            result = (result << 1) | bits[i];
        }
    }

    return result;
}
