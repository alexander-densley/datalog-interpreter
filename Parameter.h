#ifndef PARAMETER_H
#define PARAMETER_H

#include "Token.h"
#include <vector>
#include <string>

class Parameter {
private:
    std::string pString;
    /// is id? or is string? implement this concept
public:
    Parameter(std::string str) {pString = str;}

    void setString(std::string tmpStr){
        pString = tmpStr;
    }
    std::string getPredicateStr(){
        return pString;
    }

    std::string toString(){
        return pString;

    }

};

#endif //PARAMETER_H
