// Student ID: 20586501
// Graph.cpp
// 2B-GreenLab-09

#include "Graph.h"
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Helper function to add edges
void Graph::add_edge(int src, int dst, std::string tag) {
    if (static_cast<size_t>(src) >= _nodes.size() || static_cast<size_t>(dst) >= _nodes.size()) {
        return;
    }
    _nodes[src].emplace_back(dst, tag);
}

void Graph::make_silly_snake() {
    _nodes.clear();
    _nodes.resize(6);

    add_edge(0, 1, "i-see");
    add_edge(1, 2, "the-silly-snake");
    add_edge(2, 3, "i-be");
    add_edge(3, 4, "you-saw-me");
    add_edge(4, 5, "once-like");
    add_edge(5, 0, "kekule");
}

// Function to make Mr Sticky shape
void Graph::make_mr_sticky() {
    _nodes.clear();
    _nodes.resize(7);

    add_edge(0, 1, ".");
    add_edge(1, 2, ".");
    add_edge(1, 3, ".");
    add_edge(1, 4, ".");
    add_edge(4, 5, ".");
    add_edge(4, 6, ".");
}

// Function to make Driftin Dragonfly shape
void Graph::make_driftin_dragonfly() {
    _nodes.clear();
    _nodes.resize(13);

    add_edge(0, 1, "dis-be-me-head");
    add_edge(1, 2, "me");
    add_edge(1, 5, "dis-be-me");
    add_edge(1, 9, "dis-be-me");
    add_edge(2, 3, "long-tail");
    add_edge(3, 4, "be-dis");
    add_edge(5, 6, "front-right");
    add_edge(6, 7, "me-right");
    add_edge(7, 8, "back");
    add_edge(8, 2, "be-dis");
    add_edge(9, 10, "front-left");
    add_edge(10, 11, "and-left");
    add_edge(11, 12, "back");
    add_edge(12, 2, "be-dis");
}

// Function to make Slinky Star shape
void Graph::make_slinky_star() {
    _nodes.clear();
    _nodes.resize(15);

    add_edge(0, 1, "-");
    add_edge(0, 3, "-");
    add_edge(0, 5, "-");
    add_edge(0, 7, "-");
    add_edge(0, 9, "-");
    add_edge(0, 11, "-");
    add_edge(0, 13, "-");
    add_edge(1, 2, "-");
    add_edge(3, 4, "-");
    add_edge(5, 6, "-");
    add_edge(7, 8, "-");
    add_edge(9, 10, "-");
    add_edge(11, 12, "-");
    add_edge(13, 14, "-");
}

// Function to make Kathy da Grate shape
void Graph::make_kathy_da_grate() {
    _nodes.clear();
    _nodes.resize(15);

    add_edge(0, 1, "-");
    add_edge(1, 2, "-");
    add_edge(2, 3, "-");
    add_edge(3, 4, "-");
    add_edge(4, 0, "-");
    add_edge(0, 5, "-");
    add_edge(5, 6, "-");
    add_edge(1, 7, "-");
    add_edge(7, 8, "-");
    add_edge(2, 9, "-");
    add_edge(9, 10, "-");
    add_edge(3, 11, "-");
    add_edge(11, 12, "-");
    add_edge(4, 13, "-");
    add_edge(13, 14, "-");
}

void Graph::make_dodos_in_space() {
    _nodes.clear();
    _nodes.resize(50);

    for (int i = 0; i < 25; ++i) {
        int even_node = 2 * i;
        int odd_node = 2 * i + 1;
        std::stringstream ss;
        ss << "Yippee-Dodo-#" << i * 2;
        add_edge(even_node, odd_node, ss.str());
    }
}

void Graph::make_purty_pitcher() {
    _nodes.clear();
    int num_nodes = pow(2, 3);
    _nodes.resize(num_nodes);

    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < 3; ++j) {
            int neighbor = i ^ (1 << j); // Flip the j-th bit of i
            if (i < neighbor) { // Ensure each edge is only added once
                std::stringstream ss;
                ss << (j + 1) << "D";
                add_edge(i, neighbor, ss.str());
            }
        }
    }
}
