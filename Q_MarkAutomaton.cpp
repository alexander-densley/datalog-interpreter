#include "Q_MarkAutomaton.h"

void Q_MarkAutomaton::S0(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    else if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}