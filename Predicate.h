#ifndef PREDICATE_H
#define PREDICATE_H

#include "Parameter.h"
#include <vector>
#include <string>

class Predicate {
private:
    std::string id;
    std::vector<Parameter*> parameters;
public:
    Predicate(std::string str) {id = str;}
    void setId(std::string tmpStr){
        id = tmpStr;
    }
    std::string getPredicateId(){
        return id;
    }

    void addParameter(Parameter* parameter){
        parameters.push_back(parameter);
    }

    std::string toString(){
        std::string final = "";

        final += id;
        final += "(";

        for (unsigned int i = 0; i < parameters.size(); ++i){
            final += parameters.at(i)->toString();
            if ((i + 1) != parameters.size()){
                final += ",";
            }
        }
        final += ")";

        return final;
    }

    const std::vector<Parameter *> &getParameters() const {
        return parameters;
    }

};

#endif //PREDICATE_H
