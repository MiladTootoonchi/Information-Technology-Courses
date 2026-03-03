#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "Graph.h"
#include <vector>
#include <string>

class MatrixGraph : public Graph {
private:
    std::vector<std::string> nodes;
    std::vector<std::vector<std::vector<std::string>>> matrix;

    int find_node_index(const std::string& label) const;
    int get_or_create_node_index(const std::string& label);

public:
    MatrixGraph();
    ~MatrixGraph();

    void insert_edge(const std::string& node_a_label,
                     const std::string& edge_label,
                     const std::string& node_b_label) override;

    void print() const override;
    void load_from_file(const std::string& filename) override;
    void save_to_file(const std::string& filename) const override;

    void disconnect(const std::string& node_a_label,
                const std::string& node_b_label) override;

    void remove_node(const std::string& node_label) override;

    MatrixGraph(const MatrixGraph& other);
    MatrixGraph& operator=(const MatrixGraph& other);

    MatrixGraph(MatrixGraph&& other) noexcept;
    MatrixGraph& operator=(MatrixGraph&& other) noexcept;
};

#endif