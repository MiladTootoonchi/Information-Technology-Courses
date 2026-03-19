#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "tarjan.h"
#include "diamond.h"

int main(int argc, char* argv[]) {

    if (argc < 3) {
        std::cout << "Usage: ./main input.txt [scc|diamond] [-v]\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string mode = argv[2];

    bool verbose = false;

    if (argc > 3) {
        if (std::string(argv[3]) == "-v") {
            verbose = true;
        }
    }

    ListGraph g;
    g.load_from_file(filename);

    if (mode == "scc") {

        TarjanSCC t;
        auto comps = t.run(g);

        if (verbose) {
            for (auto& c : comps) {
                std::cout << "Component: ";
                for (auto& n : c) {
                    std::cout << n << " ";
                }
                std::cout << "\n";
            }
        }

    } else if (mode == "diamond") {

        DiamondQuery dq;
        dq.load_query("query.txt");
        dq.run(g, verbose);

    } else {
        std::cout << "Unknown mode\n";
    }

    return 0;
}