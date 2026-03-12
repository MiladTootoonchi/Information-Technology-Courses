#include "ListGraph.h"
#include "MatrixGraph.h"
#include <iostream>
#include "tarjan.h"

int main(int argc, char* argv[]){

    if (argc < 2){
        std::cout << "Usage: program inputfile [-v]\n";
        return 1;
    }

    std::string filename = argv[1];
    bool verbose = false;

    if (argc > 2){
        std::string flag = argv[2];
        if (flag == "-v") {
            verbose = true;
        }
    }

    ListGraph g;

    g.load_from_file(filename);

    TarjanSCC t;

    auto comps = t.run(g);

    if (verbose){
        for (auto& c : comps) {
            std::cout << "Component: ";
            for (auto& n : c) {
                std::cout << n << " ";
            }

            std::cout << "\n";
        }
    }

}