#include "diamond.h"
#include <fstream>
#include <iostream>
#include <unordered_set>

void DiamondQuery::load_query(const std::string& filename){

    std::ifstream file(filename);

    if (!file){
        std::cout << "Could not open query file\n";
        return;
    }

    std::string label;

    path1.clear();
    path2.clear();

    while (file >> label){
        if (label.back() == '.'){
            label.pop_back();
            path1.push_back(label);
            break;
        }
        path1.push_back(label);
    }

    while (file >> label){
        if (label.back() == '.'){
            label.pop_back();
            path2.push_back(label);
            break;
        }
        path2.push_back(label);
    }
}


std::vector<std::string> DiamondQuery::dfs(Graph& g, const std::string& start, const std::vector<std::string>& labels){

    std::vector<std::string> current;
    current.push_back(start);

    for (std::string label : labels){

        std::vector<std::string> next;

        for (std::string node : current){

            auto neighbors = g.get_labeled_neighbors(node);

            for (auto& p : neighbors){

                std::string nextNode = p.first;
                std::string edgeLabel = p.second;

                if (edgeLabel == label){
                    next.push_back(nextNode);
                }
            }
        }

        current = next;
    }

    return current;
}


void DiamondQuery::run(Graph& g, bool verbose){

    auto nodes = g.get_nodes();

    for (std::string start : nodes){

        auto end1 = dfs(g, start, path1);
        auto end2 = dfs(g, start, path2);

        std::unordered_set<std::string> set1(end1.begin(), end1.end());

        for (std::string x : end2){

            if (set1.find(x) != set1.end()) {

                if (verbose) {
                    std::cout << "Pair: " << start << " -> " << x << "\n";
                }
            }
        }
    }
}