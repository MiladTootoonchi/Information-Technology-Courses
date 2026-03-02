#include "Graph.h"
#include "iostream"

Node::Node(const std::string& l)
    : label(l) {}

Edge::Edge(const std::string& l, Node* a, Node* b)
    : label(l), from(a), to(b) {}

Graph::Graph() {}

Graph::~Graph() {
    // Delete all edges first
    for (Edge* e : edges) {
        delete e;
    }

    // Then delete all nodes
    for (Node* n : nodes) {
        delete n;
    }
}

Node* Graph::find_node(const std::string& label) const {
    for (Node* n : nodes) {
        if (n->label == label) {
            return n;
        }
    }
    return nullptr;
}

Node* Graph::get_or_create_node(const std::string& label) {
    Node* existing = find_node(label);

    if (existing != nullptr) {
        return existing;
    }

    Node* new_node = new Node(label);
    nodes.push_back(new_node);

    return new_node;
}

void Graph::insert_edge(const std::string& node_a_label,
                        const std::string& edge_label,
                        const std::string& node_b_label) {

    Node* nodeA = get_or_create_node(node_a_label);
    Node* nodeB = get_or_create_node(node_b_label);

    Edge* new_edge = new Edge(edge_label, nodeA, nodeB);

    edges.push_back(new_edge);

    // the edge is registered in both nodes
    nodeA->incident_edges.push_back(new_edge);
    nodeB->incident_edges.push_back(new_edge);
}

void Graph::print() const {
    std::cout << "Graph contents:\n";

    for (Node* n : nodes) {
        std::cout << "Node " << n->label << " is connected by edges: ";

        for (Edge* e : n->incident_edges) {
            std::cout << e->label << " ";
        }

        std::cout << "\n";
    }
}