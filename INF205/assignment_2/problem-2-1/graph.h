#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

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

class Graph {
private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;

    Node* find_node(const std::string& label) const;
    Node* get_or_create_node(const std::string& label);

public:
    Graph();
    ~Graph();

    // Prevents unsafe copying since we use raw pointers.
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;

    void insert_edge(const std::string& node_a_label,
                     const std::string& edge_label,
                     const std::string& node_b_label);

    void print() const;
};

#endif