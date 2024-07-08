// Student ID: 20586501
// Hanoi.cpp
// 2B-GreenLab-02

#include <iostream>
#include <sstream>
#include <vector>
#include "Hanoi.h"

std::string Hanoi::lookup_moves(int num_discs, int src, int dst) const {
    if (static_cast<size_t>(num_discs) < _cache.size() &&
        static_cast<size_t>(src) < _cache[num_discs].size() &&
        static_cast<size_t>(dst) < _cache[num_discs][src].size()) {
        return _cache[num_discs][src][dst];
    }
    return "";
}

std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp) {
    std::string cached_moves = lookup_moves(num_discs, src, dst);
    if (!cached_moves.empty()) {
        return cached_moves;
    }

    std::stringstream result;
    if (num_discs == 0) {
        return "";
    }
    if (num_discs == 1) {
        result << src << "->" << dst << "\n";
        if (_cache.size() <= static_cast<size_t>(num_discs)) _cache.resize(num_discs + 1);
        if (_cache[num_discs].size() <= static_cast<size_t>(src)) _cache[num_discs].resize(src + 1);
        if (_cache[num_discs][src].size() <= static_cast<size_t>(dst)) _cache[num_discs][src].resize(dst + 1);
        _cache[num_discs][src][dst] = result.str();
        return result.str();
    }

    result << get_moves(num_discs - 1, src, tmp, dst);
    result << src << "->" << dst << "\n";
    result << get_moves(num_discs - 1, tmp, dst, src);

    if (_cache.size() <= static_cast<size_t>(num_discs)) _cache.resize(num_discs + 1);
    if (_cache[num_discs].size() <= static_cast<size_t>(src)) _cache[num_discs].resize(src + 1);
    if (_cache[num_discs][src].size() <= static_cast<size_t>(dst)) _cache[num_discs][src].resize(dst + 1);
    _cache[num_discs][src][dst] = result.str();

    if (num_discs > 1) {
        if (static_cast<size_t>(num_discs - 1) < _cache.size()) {
            _cache[num_discs - 1].clear();
        }
    }

    return result.str();
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp) {
    std::stringstream result;
    result << "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n";
    result << get_moves(num_discs, src, dst, tmp);
    return result.str();
}