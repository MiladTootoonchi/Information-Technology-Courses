#include "ListGraph.h"
#include "MatrixGraph.h"

int main() {

    Graph* g = new MatrixGraph();

    g->load_from_file("input.txt");
    g->print();
    g->save_to_file("output.txt");

    delete g;

    return 0;
}