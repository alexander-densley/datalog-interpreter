#include "Graph.h"

Graph::Graph(unsigned int length) {

    for(unsigned int i = 0; i < length; ++i){
        isVisited.push_back(false);
        graphMap.insert({i,std::set<unsigned int>()});
    }
}

void Graph::addEdges(unsigned int i, unsigned int j) {
    graphMap[i].insert(j);
}
std::string Graph::toString() {
    std::stringstream oSS;
    oSS << "Dependency Graph\n";
    for(auto x : graphMap){
        oSS << "R" << x.first << ":";
        std::set<unsigned int>::iterator it = x.second.begin();
        while(it != x.second.end()){
            oSS << "R" << (*it);
            it++;

            if(it != x.second.end()){
                oSS << ",";
            }

        }
        oSS << std::endl;
    }

    std::string finalString = oSS.str();
    return finalString;
}

std::vector<unsigned int> Graph::postOrder(){
    for(unsigned int i = 0; i < graphMap.size(); ++i){
        if(!isVisited.at(i)){
            SCC.push_back(std::set<unsigned int>());
            visitNode(i);
        }
    }
    return postOrderVec;
}
void Graph::visitNode(unsigned int i){
    isVisited.at(i) = true;
    for(unsigned int x : graphMap.at(i)){
        if(!isVisited.at(x)){
            visitNode(x);
        }
    }
    SCC.back().insert(i);
    postOrderVec.push_back(i);

}

std::vector<std::set<unsigned int>> Graph::calculateSCC(std::vector<unsigned int> postOrder) {
    for(unsigned int i = postOrder.size() - 1; i < postOrder.size(); --i){
        if(!isVisited.at(postOrder.at(i))){
            SCC.push_back(std::set<unsigned int>());
            visitNode(postOrder.at(i));
        }
    }

    return SCC;
}



