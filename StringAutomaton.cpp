#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    counter = 0;
    if(index >= input.size()) {} //// implement everywhere
    else if (input[0] == '\'') {
        inputRead++;
        index++;
        counter++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if(index >= input.size()) {
        isUnfinished = 1;
    } //// implement everywhere
    else if(input[index] == '\n'){
        newLines++;
        index++;
        inputRead++;
        S1(input);
    }

    else if (input[index] == '\r' && input[index + 1] == '\n'){
        newLines++;
        index++;
        index++;
        inputRead++;
        inputRead++;
        S1(input);

    }

    else if (input[index] != '\'') {
        inputRead++;
        index++;
        S1(input);
    }
   /* else if ((input[index] == '\'') && (counter%2 != 0)) {
        inputRead++;
        index++;
        counter++;
        S1(input);
    }*/

    else if ((input[index] == '\'')) {
        inputRead++;
        index++;
        counter++;
        S2(input);
    }

    else {
        Serr();
    }
}

void StringAutomaton::S2(const std::string& input) {
    if(index >= input.size()){
    } //// implement everywhere
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        counter++;
        S1(input);
    }
    else if (counter%2 != 0){
        Serr();
    }
    else if ((input[index] != '\'')) {
        //inputRead++;
    }
    else {
        Serr();
    }
}