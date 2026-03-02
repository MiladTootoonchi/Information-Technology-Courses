#include "ListGraph.h"
#include <fstream>
#include <iostream>

Node::Node(const std::string& l)
    : label(l) {}

Edge::Edge(const std::string& l, Node* a, Node* b)
    : label(l), from(a), to(b) {}

ListGraph::ListGraph() {
}

ListGraph::~ListGraph() {
    // delete edges first
    for (Edge* e : edges) {
        delete e;
    }

    // then delete nodes
    for (Node* n : nodes) {
        delete n;
    }
}

Node* ListGraph::find_node(const std::string& label) const {
    for (Node* n : nodes) {
        if (n->label == label) {
            return n;
        }
    }
    return nullptr;
}

Node* ListGraph::get_or_create_node(const std::string& label) {
    Node* n = find_node(label);

    if (n != nullptr) {
        return n;
    }

    Node* newNode = new Node(label);
    nodes.push_back(newNode);
    return newNode;
}

void ListGraph::insert_edge(const std::string& node_a_label,
                            const std::string& edge_label,
                            const std::string& node_b_label) {

    Node* nodeA = get_or_create_node(node_a_label);
    Node* nodeB = get_or_create_node(node_b_label);

    Edge* e = new Edge(edge_label, nodeA, nodeB);

    edges.push_back(e);

    nodeA->incident_edges.push_back(e);
    nodeB->incident_edges.push_back(e);
}

void ListGraph::load_from_file(const std::string& filename) {
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

void ListGraph::save_to_file(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file) {
        std::cout << "Could not open file for writing\n";
        return;
    }

    for (Edge* e : edges) {
        file << e->from->label << " "
             << e->label << " "
             << e->to->label << "\n";
    }
}

void ListGraph::print() const {
    std::cout << "Graph:\n";

    for (Node* n : nodes) {
        std::cout << n->label << ": ";

        for (Edge* e : n->incident_edges) {
            std::cout << e->label << " ";
        }

        std::cout << "\n";
    }
}