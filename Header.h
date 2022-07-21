#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

class Header {
private:
    std::vector<std::string> attributes;
public:
    Header(){}
    Header(std::vector<std::string> newVec){
        attributes = newVec;
    }
    const std::vector <std::string> getAttributes() const {
        return attributes;
    }
    std::string getAttribute(int i) {
        return attributes.at(i);
    }
    void addAttribute(std::string attribute){
        attributes.push_back(attribute);
    }
    std::string find(int i){
        return (attributes.at(i));
    }
    void assignHeader(std::vector<std::string> headerVector){
        attributes = headerVector;
    }

    unsigned int getSize(){
        return attributes.size();
    }
};
#endif //HEADER_H
