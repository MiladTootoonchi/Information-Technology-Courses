#ifndef TARJAN_H
#define TARJAN_H

#include "Graph.h"
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

class TarjanSCC{
private:
    std::unordered_map<std::string,int> index;
    std::unordered_map<std::string,int> lowlink;
    std::unordered_map<std::string,bool> onStack;
    std::stack<std::string> S;
    int currentIndex;
    std::vector<std::vector<std::string>> components;

    void strongconnect(Graph& g, const std::string& v);

public:
    TarjanSCC();
    std::vector<std::vector<std::string>> run(Graph& g);

};

#endif