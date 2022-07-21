
#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <map>
#include <vector>
#include <sstream>


class Graph {

private:
    std::map<unsigned int, std::set<unsigned int>> graphMap;
    std::vector<bool> isVisited;
    std::vector<unsigned int> postOrderVec;
    std::vector<std::set<unsigned int>> SCC;
public:
    Graph(unsigned int length);
    void addEdges(unsigned int i, unsigned int j);
    std::string toString();
    std::vector<unsigned int> postOrder();
    void visitNode(unsigned int i);


    std::vector<std::set<unsigned int>> calculateSCC(std::vector<unsigned int> postOrder);
};


#endif //GRAPH_H
