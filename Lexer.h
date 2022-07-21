#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <iostream>
#include <ostream>
#include "Automaton.h"
#include "Token.h"

using namespace std;

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    std::vector<Token*> Run(std::string& input);


    void Print();


    // TODO: add other public methods here

};

#endif // LEXER_H

