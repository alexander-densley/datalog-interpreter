#include "MultiplyAutomaton.h"

void MultiplyAutomaton::S0(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    else if (input[index] == '*') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
