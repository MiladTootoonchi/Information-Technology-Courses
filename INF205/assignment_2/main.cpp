#include "Graph.h"

int main() {
    Graph g;

    g.insert_edge("A", "e1", "B");
    g.insert_edge("A", "e2", "C");
    g.insert_edge("B", "e3", "C");
    g.insert_edge("C", "e4", "C");

    return 0;
}