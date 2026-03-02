#include "matrixgraph.h"
#include <fstream>
#include <iostream>

MatrixGraph::MatrixGraph() {
}

MatrixGraph::~MatrixGraph() {
}

int MatrixGraph::find_node_index(const std::string& label) const {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i] == label) {
            return i;
        }
    }
    return -1;
}

int MatrixGraph::get_or_create_node_index(const std::string& label) {
    int index = find_node_index(label);

    if (index != -1) {
        return index;
    }

    // add new node
    nodes.push_back(label);

    // add new column to all existing rows
    for (size_t i = 0; i < matrix.size(); ++i) {
        matrix[i].push_back(std::vector<std::string>());
    }

    // add new row
    std::vector<std::vector<std::string>> newRow(nodes.size());
    matrix.push_back(newRow);

    return nodes.size() - 1;
}

void MatrixGraph::insert_edge(const std::string& node_a_label,
                              const std::string& edge_label,
                              const std::string& node_b_label) {

    int i = get_or_create_node_index(node_a_label);
    int j = get_or_create_node_index(node_b_label);

    matrix[i][j].push_back(edge_label);
}

void MatrixGraph::load_from_file(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Could not open file\n";
        return;
    }

    std::string a, edgeLabel, b;

    while (file >> a >> edgeLabel >> b) {
        insert_edge(a, edgeLabel, b);
    }
}

void MatrixGraph::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file) {
        std::cout << "Could not open file for writing\n";
        return;
    }

    for (size_t i = 0; i < nodes.size(); ++i) {
        for (size_t j = 0; j < nodes.size(); ++j) {
            for (const std::string& edgeLabel : matrix[i][j]) {
                file << nodes[i] << " "
                     << edgeLabel << " "
                     << nodes[j] << "\n";
            }
        }
    }
}

void MatrixGraph::print() const {
    std::cout << "Graph (adjacency matrix):\n";

    for (size_t i = 0; i < nodes.size(); ++i) {
        for (size_t j = 0; j < nodes.size(); ++j) {
            if (!matrix[i][j].empty()) {
                std::cout << nodes[i] << " -> " << nodes[j] << ": ";
                for (const std::string& label : matrix[i][j]) {
                    std::cout << label << " ";
                }
                std::cout << "\n";
            }
        }
    }
}

void MatrixGraph::remove_node(const std::string& label) {

    int index = find_node_index(label);
    if (index == -1) return;

    bool isolated = true;

    for (size_t i = 0; i < nodes.size(); ++i) {
        if (!matrix[index][i].empty() ||
            !matrix[i][index].empty()) {
            isolated = false;
            break;
        }
    }

    if (!isolated) return;

    // remove row
    matrix.erase(matrix.begin() + index);

    // remove column
    for (auto& row : matrix) {
        row.erase(row.begin() + index);
    }

    nodes.erase(nodes.begin() + index);
}

void MatrixGraph::disconnect(const std::string& a,
                             const std::string& b) {

    int i = find_node_index(a);
    int j = find_node_index(b);

    if (i == -1 || j == -1) return;

    matrix[i][j].clear();

    // remove isolated nodes
    remove_node(a);
    remove_node(b);
}