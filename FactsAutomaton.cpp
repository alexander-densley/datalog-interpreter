#include "FactsAutomaton.h"

void FactsAutomaton::S0(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    if (input[index] == 'F') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S1(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    if (input[index] == 'a') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S2(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    if (input[index] == 'c') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S3(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    if (input[index] == 't') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S4(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    else if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}