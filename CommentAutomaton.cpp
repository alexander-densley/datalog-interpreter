#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if(index >= input.size()){
        Serr();
    }
    else if (input[index] == '#') { //opens the comment, single or block
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input){
    if(index >= input.size()){
        //Serr();
    }
    else if((input[index] == '|') && (input[index-1] == '#')){//moving to S2, start of block comment
        inputRead++;
        index++;
        S2(input);
    }

        //Exit Condition for single line comments
    else if(input[index] == '\n'){
    }
    else{
        inputRead++;
        index++;
        S2a(input);
    }
}
void CommentAutomaton::S2a(const std::string& input) { // for single line comments
    if(index >= input.size()){
    }
    //Exit Condition for single line comments
    else if(input[index] == '\n'){
    }

    else{
        inputRead++;
        index++;
        S2a(input);
    }
}

//BLOCK COMMENTS ONLY FROM HERE ON OUT
void CommentAutomaton::S2(const std::string& input){
    if(index >= input.size()){
        isUnfinished = 1;
    }
    else if(input[index] == '\n'){
        newLines++;
        index++;
        inputRead++;
        S2(input);
    }

    else if (input[index] == '|'){
        index++;
        inputRead++;
        S3(input);
    }

    else if (input[index] != '|'){
        index++;
        inputRead++;
        S2(input);
    }
    else{
        Serr();
    }

}

void CommentAutomaton::S3(const std::string& input){ // final state for block
    if(index >= input.size()){
        isUnfinished = 1;
    }
    else if(input[index] == '\n'){
        newLines++;
        index++;
        inputRead++;
        S2(input);
    }
    else if (input[index] == '#'){
        index++;
        inputRead++;
    }
    else{
        index++;
        inputRead++;
        S2(input);
    }

}










/*
#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if(index >= input.size()) {} //// implement everywhere
    else if(input[index] == '#'){
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (index >= input.size()) {} //// implement everywhere
    else if (input[index] == '|'){
        inputRead++;
        index++;
        S2a(input);
    }
    else if ((input[index] != '\n') && ((input[index] != '\r' && input[index + 1] != '\n'))){
        inputRead++;
        index++;
        S2b(input);
    }
    else if ((input[index] == '\n') || ((input[index] == '\r' && input[index + 1] == '\n'))){
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S2b(const std::string &input) {
    if(index >= input.size()) {} //// implement everywhere

    else if ((input[index] != '\n') && ((input[index] != '\r' && input[index + 1] != '\n'))){
        inputRead++;
        index++;
        S2b(input);
    }

    else if ((input[index] == '\n') || (input[index] == '\r' && input[index + 1] == '\n')){
        //inputRead++;
    }

    else{
        Serr();
    }
}


void CommentAutomaton::S2a(const std::string &input) {
    if(index >= input.size()) {
        isUnfinished = 1;
    } //// implement everywhere


    else if (input[index] != '|'){
        if(input[index] == '\n'){
            newLines++;
            index++;
            inputRead++;
            S2a(input);
        }
        else if (input[index] == '\r' && input[index + 1] == '\n'){
            newLines++;
            index++;
            index++;
            inputRead++;
            inputRead++;
            S2a(input);
        }
        else{
            inputRead++;
            index++;
            S2a(input);
        }

    }
    else if (input[index] == '|'){
        inputRead++;
        index++;
        S3a(input);
    }

    else if(input[index] == '\n'){
        newLines++;
        index++;
        inputRead++;
        S2a(input);
    }
    else if (input[index] == '\r' && input[index + 1] == '\n'){
        newLines++;
        index++;
        index++;
        inputRead++;
        inputRead++;
        S2a(input);

    }

    else{
        Serr();
    }
}

void CommentAutomaton::S3a(const std::string &input) {
    if(index >= input.size()){
        isUnfinished = 1;

    } //// implement everywhere


    else if ((input[index] != '#')  ){ //
        if(input[index] == '\n'){
            newLines++;
            index++;
            inputRead++;
            S3a(input);
        }
        else if ((input[index] == '\r') && (input[index + 1] == '\n')){
            newLines++;
            index++;
            index++;
            inputRead++;
            inputRead++;
            S3a(input);

        }
        inputRead++;
        index++;
        S2a(input);
    }
    else if(input[index] == '\n'){
        newLines++;
        index++;
        inputRead++;
        S3a(input);
    }
    else if ((input[index] == '\r') && (input[index + 1] == '\n')){
        newLines++;
        index++;
        index++;
        inputRead++;
        inputRead++;
        S3a(input);

    }
    else if ((input[index] == '#') ){
        inputRead++;
    }

    else {
        Serr();
    }
}

*/