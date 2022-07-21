#ifndef RELATION_H
#define RELATION_H

#include "Tuple.h"
#include "Header.h"
#include <set>
#include <sstream>
#include <iostream>

class Relation {

private:
    std::string name;
    Header header;
public:
    std::set<Tuple> tuples;
    Relation() {};
    Relation(const std::string &name, const Header &header) : name(name), header(header) {}
    Relation(Header relHeader) : header(relHeader) {}

    Relation project(std::vector<unsigned int> indices);
    Relation rename(std::vector<std::string> names);
    Relation select1(unsigned int index, std::string stringVal);
    Relation select2(unsigned int index1, unsigned int index2);

    std::string tupleToString();
    bool addTuple(Tuple t);
    void setName(std::string newName);
    void setHeader(Header myHeader);
    Header getHeader();

    const std::string &getName() const;

    std::set<Tuple> getTuples();

    Relation joinRelation(Relation newRelation);
    Header combineHeaders(Header inputHeader, std::vector<int> &vector);
    bool isJoinable(Tuple firstTuple, Tuple secondTuple, std::vector<int> fTuple, std::vector<int> sTuple);
    Tuple combineTuples(Tuple firstTuple, Tuple secondTuple, std::vector<int> indexes);
    Relation unionRelation(Relation inputRelation);
};

#endif //RELATION_H
