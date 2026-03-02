#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include "Graph.h"
#include <vector>
#include <string>

class Edge;

class Node {
public:
    std::string label;
    std::vector<Edge*> incident_edges;

    Node(const std::string& l);
};

class Edge {
public:
    std::string label;
    Node* from;
    Node* to;

    Edge(const std::string& l, Node* a, Node* b);
};

class ListGraph : public Graph {
private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;

    Node* find_node(const std::string& label) const;
    Node* get_or_create_node(const std::string& label);

public:
    ListGraph();
    ~ListGraph();

    ListGraph(const ListGraph&) = delete;
    ListGraph& operator=(const ListGraph&) = delete;

    void insert_edge(const std::string& node_a_label,
                     const std::string& edge_label,
                     const std::string& node_b_label) override;

    void print() const override;

    void load_from_file(const std::string& filename) override;
    void save_to_file(const std::string& filename) const override;
};

#endif