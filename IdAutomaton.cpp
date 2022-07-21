#include "IdAutomaton.h"

void IdAutomaton::S0(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    else if (((input.substr(0, 7) == "Schemes") && std::isspace(input[7])) ||
    ((input.substr(0, 5) == "Facts") && std::isspace(input[5])) ||
    ((input.substr(0, 5) == "Rules") && std::isspace(input[5])) ||
    ((input.substr(0, 7) == "Queries") && std::isspace(input[7]))) {
        Serr();
    }
    else if (isalpha(input[0])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input) {
    if(index >= input.size()){ //// implement everywhere
    }
    else if ((isalpha(input[index])) || isdigit(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else if (isspace(input[index]) || input[index] == '\n' || index >= input.size() || (!(isalpha(input[index])) && !isdigit(input[index]))) // checks for end of the ID
    {
    }

    else {
        Serr();
    }
}