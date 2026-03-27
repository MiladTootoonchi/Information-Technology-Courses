#include "tarjan.h"
#include <iostream>

TarjanSCC::TarjanSCC() {
    currentIndex = 0;
}

void TarjanSCC::strongconnect(Graph& g, const std::string& v){

    index[v] = currentIndex;
    lowlink[v] = currentIndex;
    currentIndex++;

    S.push(v);
    onStack[v] = true;

    std::vector<std::string> neighbors = g.get_neighbors(v);

    for (std::string w : neighbors){

        if (index.find(w) == index.end()){

            strongconnect(g, w);

            if (lowlink[w] < lowlink[v])
                lowlink[v] = lowlink[w];

        }
        else if (onStack[w]){

            if (index[w] < lowlink[v])
                lowlink[v] = index[w];
        }
    }

    if (lowlink[v] == index[v]){

        std::vector<std::string> component;

        while (true){

            std::string w = S.top();
            S.pop();

            onStack[w] = false;

            component.push_back(w);

            if (w == v) break;
        }

        components.push_back(component);
    }
}

std::vector<std::vector<std::string>> TarjanSCC::run(Graph& g) {

    components.clear();
    index.clear();
    lowlink.clear();
    onStack.clear();

    while (!S.empty()) {
        S.pop();
    }

    currentIndex = 0;

    std::vector<std::string> nodes = g.get_nodes();

    for (std::string v : nodes) {

        if (index.find(v) == index.end()) {
            strongconnect(g, v);
        }

    }

    return components;
}