#ifndef DATABASE_H
#define DATABASE_H
#include "Relation.h"
#include<map>

class Database {

private:
    std::map<std::string, Relation> relations;
public:
    Relation getRelation(std::string key){
        return relations.at(key);
    }
    Relation& getRelationByRef(std::string key){
        return relations.at(key);
    }
    void addRelation(std::string key, Relation x){
        relations.insert(std::pair<std::string, Relation> (key, x));
    }
    void addTupleToRelation(std::string tupName, Tuple tuple) {
        relations.at(tupName).addTuple(tuple);
    }
    std::map<std::string, Relation> mapAccess(){
        return relations;
    }
    unsigned int getNumTuples(){
        size_t count = 0;
        for(auto curPair : relations){
            count += curPair.second.tuples.size();
        }
        return count;
    }
};

#endif //DATABASE_H
