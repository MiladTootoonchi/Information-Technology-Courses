#ifndef GRAPH_H
#define GRAPH_H

#include <string>

class Graph {
public:
    virtual ~Graph() {}

    virtual void insert_edge(const std::string& node_a_label,
                             const std::string& edge_label,
                             const std::string& node_b_label) = 0;

    virtual void print() const = 0;

    virtual void load_from_file(const std::string& filename) = 0;
    virtual void save_to_file(const std::string& filename) const = 0;
};

#endif