#include "AddAutomaton.h"

void AddAutomaton::S0(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    if (input[index] == '+') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}