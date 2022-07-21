#ifndef RULE_H
#define RULE_H

#include "Predicate.h"

class Rule{
private:
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicate;

public:

    Rule(Predicate* startPredicate){
        headPredicate = startPredicate;
    }

    void setHeadPredicate(Predicate* tmp){
        headPredicate = tmp;
    }
    Predicate* getPred(){
        return headPredicate;
    }
    Predicate* getBodyPred(unsigned int i){
        return bodyPredicate.at(i);
    }
    std::vector<Predicate*> getBodyPredVec(){
        return bodyPredicate;
    }

    unsigned int getPredSize(){
        return bodyPredicate.size();
    }

    void addPredicate(Predicate* tmp){
        bodyPredicate.push_back(tmp);
    }

    std::string toString(){
        std::string final = "";
        final += headPredicate->toString();
        final += " :- ";

        for (unsigned int i = 0; i < bodyPredicate.size(); ++i){
            final += bodyPredicate.at(i)->toString();
            if ((i + 1) == bodyPredicate.size()){
                final += ".";
            }
            else{
                final += ",";
            }
        }

        return final;
    }


};

#endif //RULE_H
