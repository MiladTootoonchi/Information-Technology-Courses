#include "ListGraph.h"
#include "MatrixGraph.h"
#include <iostream>

int main() {

    std::cout << "Testing ListGraph\n";

    ListGraph g;

    g.insert_edge("A", "e1", "B");
    g.insert_edge("A", "e2", "B");
    g.insert_edge("B", "e3", "C");

    std::cout << "\nGraph after inserting edges:\n";
    g.print();

    std::cout << "\nTesting copy constructor\n";
    ListGraph g2(g);
    g2.print();

    std::cout << "\nTesting copy\n";
    ListGraph g3;
    g3 = g;
    g3.print();

    std::cout << "\nTesting disconnect A B\n";
    g.disconnect("A", "B");
    g.print();

    std::cout << "\nTesting remove_node C\n";
    g.remove_node("C");
    g.print();

    std::cout << "\nSaving to file output_list.txt\n";
    g.save_to_file("output_list.txt");


    std::cout << "\n\nTesting MatrixGraph\n";

    MatrixGraph m;

    m.insert_edge("A", "e1", "B");
    m.insert_edge("A", "e2", "B");
    m.insert_edge("B", "e3", "C");

    std::cout << "\nMatrixGraph after inserting edges:\n";
    m.print();

    std::cout << "\nTesting copy constructor\n";
    MatrixGraph m2(m);
    m2.print();

    std::cout << "\nTesting copy\n";
    MatrixGraph m3;
    m3 = m;
    m3.print();

    std::cout << "\nTesting disconnect A B\n";
    m.disconnect("A", "B");
    m.print();

    std::cout << "\nTesting remove_node C\n";
    m.remove_node("C");
    m.print();

    std::cout << "\nSaving to file output_matrix.txt\n";
    m.save_to_file("output_matrix.txt");


    std::cout << "\n\nTesting load_from_file with ListGraph\n";

    ListGraph fileTest;
    fileTest.load_from_file("input.txt");
    fileTest.print();

    return 0;
}