#ifndef DIAMOND_H
#define DIAMOND_H

#include "Graph.h"
#include <vector>
#include <string>

class DiamondQuery{

private:

    std::vector<std::string> path1;
    std::vector<std::string> path2;

    std::vector<std::string> dfs(Graph& g, const std::string& start, const std::vector<std::string>& labels);

public:

    void load_query(const std::string& filename);

    void run(Graph& g, bool verbose);
};

#endif