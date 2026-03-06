#include "ListGraph.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

Node::Node(const std::string& l): label(l){}

Edge::Edge(const std::string& l, Node* a, Node* b): label(l), from(a), to(b){}

ListGraph::ListGraph(){}

ListGraph::~ListGraph(){
    for (Edge* e : edges) {
        delete e;
    }
    for (Node* n : nodes) {
        delete n;
    }
}

Node* ListGraph::find_node(const std::string& label) const{
    for (Node* n : nodes) {
        if (n->label == label) {
            return n;
        }
    }
    return nullptr;
}

Node* ListGraph::get_or_create_node(const std::string& label){
    Node* n = find_node(label);

    if (n != nullptr) {
        return n;
    }

    Node* newNode = new Node(label);
    nodes.push_back(newNode);
    return newNode;
}

void ListGraph::insert_edge(const std::string& node_a_label, const std::string& edge_label, const std::string& node_b_label){

    Node* nodeA = get_or_create_node(node_a_label);
    Node* nodeB = get_or_create_node(node_b_label);

    Edge* e = new Edge(edge_label, nodeA, nodeB);

    edges.push_back(e);

    nodeA->incident_edges.push_back(e);
    nodeB->incident_edges.push_back(e);
}

void ListGraph::load_from_file(const std::string& filename){
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

void ListGraph::save_to_file(const std::string& filename) const{
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

void ListGraph::print() const{
    std::cout << "Graph:\n";

    for (Node* n : nodes) {
        std::cout << n->label << ": ";

        for (Edge* e : n->incident_edges) {
            std::cout << e->label << " ";
        }

        std::cout << "\n";
    }
}

void ListGraph::remove_node(const std::string& label){

    Node* node = find_node(label);
    if (!node) return;

    if (!node->incident_edges.empty()) return;

    nodes.erase(
        std::remove(nodes.begin(), nodes.end(), node),
        nodes.end());

    delete node;
}

void ListGraph::disconnect(const std::string& a, const std::string& b){

    Node* nodeA = find_node(a);
    Node* nodeB = find_node(b);

    if (!nodeA || !nodeB) return;

    for (auto it = edges.begin(); it != edges.end();) {
        Edge* e = *it;

        if (e->from == nodeA && e->to == nodeB) {

            nodeA->incident_edges.erase(
                std::remove(nodeA->incident_edges.begin(),
                            nodeA->incident_edges.end(), e),
                nodeA->incident_edges.end());

            nodeB->incident_edges.erase(
                std::remove(nodeB->incident_edges.begin(),
                            nodeB->incident_edges.end(), e),
                nodeB->incident_edges.end());

            delete e;
            it = edges.erase(it);
        }
        else {
            ++it;
        }
    }

    remove_node(a);
    remove_node(b);
}


ListGraph::ListGraph(const ListGraph& other){
    std::unordered_map<Node*, Node*> map;

    for (Node* oldNode : other.nodes) {
        Node* newNode = new Node(oldNode->label);
        nodes.push_back(newNode);
        map[oldNode] = newNode;
    }

    for (Edge* oldEdge : other.edges) {
        Node* newFrom = map[oldEdge->from];
        Node* newTo   = map[oldEdge->to];

        Edge* newEdge = new Edge(oldEdge->label, newFrom, newTo);
        edges.push_back(newEdge);

        newFrom->incident_edges.push_back(newEdge);
        newTo->incident_edges.push_back(newEdge);
    }
}

ListGraph& ListGraph::operator=(const ListGraph& other){
    if (this == &other)
        return *this;

    for (Edge* e : edges)
        delete e;
    for (Node* n : nodes)
        delete n;

    edges.clear();
    nodes.clear();

    std::unordered_map<Node*, Node*> map;

    for (Node* oldNode : other.nodes) {
        Node* newNode = new Node(oldNode->label);
        nodes.push_back(newNode);
        map[oldNode] = newNode;
    }

    for (Edge* oldEdge : other.edges) {
        Node* newFrom = map[oldEdge->from];
        Node* newTo   = map[oldEdge->to];

        Edge* newEdge = new Edge(oldEdge->label, newFrom, newTo);
        edges.push_back(newEdge);

        newFrom->incident_edges.push_back(newEdge);
        newTo->incident_edges.push_back(newEdge);
    }

    return *this;
}

ListGraph::ListGraph(ListGraph&& other) noexcept: nodes(std::move(other.nodes)), edges(std::move(other.edges)){
    other.nodes.clear();
    other.edges.clear();
}

ListGraph& ListGraph::operator=(ListGraph&& other) noexcept{
    if (this == &other)
        return *this;

    for (Edge* e : edges)
        delete e;
    for (Node* n : nodes)
        delete n;

    nodes = std::move(other.nodes);
    edges = std::move(other.edges);

    other.nodes.clear();
    other.edges.clear();

    return *this;
}