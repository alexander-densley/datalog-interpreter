#include "ColonDashAutomaton.h"

void ColonDashAutomaton::S0(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    if (input[index] == ':') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void ColonDashAutomaton::S1(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    else if (input[index] == '-') {
        inputRead++;
    }
    else {
        Serr();
    }
}