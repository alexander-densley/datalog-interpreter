#ifndef TUPLE_H
#define TUPLE_H

#include <vector>
#include <string>
#include <sstream>
#include "Header.h"

class Tuple {

private:
    std::vector<std::string> values;


public:
    inline bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }
    std::vector <std::string> getValues(){
        return values;
    }
    void addValue(std::string value){
        values.push_back(value);
    }
    std::string find(int i){
        return (values.at(i));
    }

    unsigned int getSize(){
        return values.size();
    }
    std::string toString(Header h){
        std::stringstream ss;
        for (unsigned int i = 0; i < h.getSize(); ++i){
            ss << h.find(i) + "=" + values.at(i);
            if (i != h.getSize() - 1){
                ss << ", ";
            }
        }
        return ss.str();
    }


};

#endif //TUPLE_H
