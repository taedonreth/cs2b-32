// Student ID: 20586501
// Hanoi.h
// 2B-GreenLab-02

#ifndef Hanoi_h
#define Hanoi_h

#include <iostream>
#include <sstream>
#include <vector>

class Hanoi {
private:
    std::vector<std::vector<std::vector<std::string>>> _cache;
    std::string lookup_moves(int num_discs, int src, int dst) const;
    std::string get_moves(int num_discs, int src, int dst, int tmp);

public:
    // Use freebie default constructor
    std::string solve(int num_discs, int src, int dst, int tmp);
    friend class Tests; // Don't remove this line
};

#endif /*Hanoi_h*/