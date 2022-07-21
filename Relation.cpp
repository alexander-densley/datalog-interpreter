#include "Relation.h"

std::string Relation::tupleToString(){
    std::string tupleString;
    std::stringstream ssTuple;

    for (Tuple x : tuples){
        if (header.getSize() != 0){
            ssTuple << "  ";
        }
        for (unsigned int i = 0; i < header.getSize(); ++i){
            ssTuple << header.find(i) << '=' << x.find(i);
            if (i < header.getSize() - 1) {
                ssTuple << ", ";
            }
        }
        if (header.getSize() != 0){
            ssTuple << '\n';
        }
    }
    tupleString = ssTuple.str();


    return tupleString;
}
bool Relation::addTuple(Tuple t) {
    return tuples.insert(t).second;
}
void Relation::setName(std::string newName) {
    name = newName;
}
void Relation::setHeader(Header myHeader) {
    header = myHeader;
}
Header Relation::getHeader(){
    return header;
}
const std::string &Relation::getName() const {
    return name;
}
std::set<Tuple> Relation::getTuples() {
    return tuples;
}


Relation Relation::select1(unsigned int index, std::string stringVal) {
    Relation newRelation;
    newRelation.setName(name);
    newRelation.setHeader(header);

    for(Tuple x : tuples){
        if(x.find(index) == stringVal){
            newRelation.addTuple(x);
        }
    }
    return newRelation;
}

Relation Relation::select2(unsigned int index1, unsigned int index2) {
    Relation newRelation;
    newRelation.setName(name);
    newRelation.setHeader(header);

    for(Tuple x : tuples){
        if(x.find(index1) == x.find(index2)){
            newRelation.addTuple(x);
        }
    }
    return newRelation;
}

Relation Relation::project(std::vector<unsigned int> indices) {
    Relation newRelation;
    newRelation.setName(name);

    for(Tuple x : tuples){
        Tuple tempTuple;
        for(unsigned int i = 0; i < indices.size(); ++i){
            tempTuple.addValue(x.find(indices.at(i)));
        }
        newRelation.addTuple(tempTuple);
    }
    Header tempHeader;
    for(unsigned int i = 0; i < indices.size(); ++i){
        tempHeader.addAttribute(header.find(indices.at(i)));
    }
    newRelation.setHeader(tempHeader);
    return newRelation;
}

Relation Relation::rename(std::vector<std::string> names) {
    Relation newRelation;
    Header newHeader;
    newHeader.assignHeader(names);
    newRelation.setName(name);
    newRelation.setHeader(newHeader);
    for(Tuple x : tuples) {
        newRelation.addTuple(x);
    }
    return newRelation;
}

Relation Relation::joinRelation(Relation joinRelation){
    std::vector<int> originalRelationIndexes;
    std::vector<int> joinRelationIndexes;
    std::vector<int> columnsToAdd;

    // FIND WHERE IN THE SPECIFIC RELATION HEADERS WHERE THEY MATCH
    for(unsigned int i = 0; i < joinRelation.getHeader().getSize(); ++i){
        for(unsigned int j = 0; j < this->header.getSize(); ++j){
            if(joinRelation.getHeader().find(i) == this->header.find(j)) {
                originalRelationIndexes.push_back(j);
                joinRelationIndexes.push_back(i);
            }
        }
    }

    // FINDS WHICH COLUMNS OF THE JOIN RELATION HEADER THAT NEED TO BE ADDED
    bool isFound = false;
    for(unsigned int i = 0; i < joinRelation.getHeader().getSize(); ++i){
        isFound = false;
        for(unsigned int j = 0; j < this->header.getSize(); ++j){
            if (joinRelation.getHeader().find(i) == this->header.find(j)){
                isFound = true;
                break;
            }
        }
        if (isFound == false){
            columnsToAdd.push_back(i);
        }
    }
    // MAKES NEW HEADER
    Header newHeader = combineHeaders(joinRelation.getHeader(), columnsToAdd);
    Relation newRelation(newHeader);

    //COMBINES TUPLES AND ADDS THEM TO NEW RELATION
    for(Tuple x : tuples){
        for(Tuple y :joinRelation.getTuples()){
            if(isJoinable(x, y, originalRelationIndexes, joinRelationIndexes)){
                Tuple z = combineTuples(x, y, columnsToAdd);
                newRelation.addTuple(z);
            }
        }
    }
    // SET NAME OF NEW RELATION
    newRelation.setName(this->name + '+' + joinRelation.getName());
    return newRelation;
}

Header Relation::combineHeaders(Header inputHeader, std::vector<int> &vector) {
    std::vector<std::string> curHeader = this->header.getAttributes();
    std::vector<std::string> newHeader = inputHeader.getAttributes();
    std::vector<std::string> finalHeader = curHeader;

    // BASED ON THE COLUMNS TO ADD INDEXES ADDS TO FINAL HEADER
    for(unsigned int i = 0; i < vector.size(); ++i){
        finalHeader.push_back(newHeader.at(vector.at(i)));
    }
    Header returnHeader(finalHeader);

    return returnHeader;
}
bool Relation::isJoinable(Tuple firstTuple, Tuple secondTuple, std::vector<int> fTuple, std::vector<int> sTuple){
    //CHECKS THAT THE DATA AT THE LOCATION UNDER THE SHARED HEADER IS THE SAME SO THE TUPLES CAN BE JOINED
    for(unsigned int i = 0; i < fTuple.size(); ++i){
        if(firstTuple.find(fTuple.at(i)) != secondTuple.find(sTuple.at(i))){
            return false;
        }
    }
    return true;
}
Tuple Relation::combineTuples(Tuple firstTuple, Tuple secondTuple, std::vector<int> indexes){
    Tuple x = firstTuple;
    //CREATES NEW TUPLES BASED ON THE INDEXES OF THE SECOND TUPLE WHERE THEY CAN BE ADDED
    for(unsigned int i = 0; i < indexes.size(); ++i){
       x.addValue(secondTuple.find(indexes.at(i)));
    }
    return x;
}
Relation Relation::unionRelation(Relation inputRelation) {
    // IF YOU CAN ADD A TUPLE (IF IT RETURNS TRUE) COUT THE TUPLE
    for(Tuple x : inputRelation.tuples){
        if(this->addTuple(x)){
            std::cout << "  " << x.toString(header) << std::endl;
        }
    }

    return Relation();
}


