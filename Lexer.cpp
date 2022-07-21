#include "Lexer.h"

#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "Left_ParenAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"

using namespace std;


Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {

    // TODO: need to clean up the memory in `automata` and `tokens`
}
void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton());
    automata.push_back(new Left_ParenAutomaton());
    automata.push_back(new Right_ParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
}

void Lexer::Print() {
    for (unsigned int i = 0; tokens.size() > i; ++i){
        cout << tokens.at(i)->toString();
    }
    cout << "Total Tokens = " << to_string(tokens.size());

}

std::vector<Token*> Lexer::Run(std::string& input) {
    int lineNumber = 1;

    while (input.size() > 0) {

        if (isspace(input[0])){  //// checks for new line, erases it and increase line number
             if (input[0] == '\n'){
                 ++lineNumber;
                 input.erase(0,1);
                 continue;
             }
             /*else if (input[0] == '\r' && input.at(1) == '\n'){
                 ++lineNumber;
                 input.erase(0,2);
             }*/
             else {
                 input.erase(0,1);
                 continue;
             }

         }
        int maxRead = 0;
        Automaton *maxAutomaton = automata.at(0);

        // Here is the "Parallel" part of the algorithm
        for (Automaton *currAutomaton: automata) { // (int i =0; i < max
            int inputRead = currAutomaton->Start(input);
            if(inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = currAutomaton;
            }

        }

        // Here is the "Max" part of the algorithm
        if (maxRead > 0 && maxAutomaton->getFinished() == 0) { // usign the is finished allows for unfisnished strings and comments
            string description = input.substr(0,maxAutomaton->getInputRead());
            Token *newToken = maxAutomaton->CreateToken(description, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
            // No automaton accepted input
            // Create single character undefined token
        else {
            if (input.substr(0,1) != "" ){
                if (maxAutomaton->getFinished() == 0) {
                    maxRead = 1;
                }
                string description = input.substr(0,maxRead);
                Token *newToken = new Token(TokenType::UNDEFINED, description, lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();/// maybe
                tokens.push_back(newToken);
            }
        }
        input.erase(0, maxRead);

        if (input[0] == '\n'){
            lineNumber++;
            input.erase(0,1);
        }
        else if (input[0] == '\r' && input.at(1) == '\n'){
            lineNumber++;
            input.erase(0,2);
        }
    }
   // cout << "this is my line number: " << lineNumber << endl;
    tokens.push_back(new Token(TokenType::EOF_TYPE,"",lineNumber));
    return tokens;
        /*
add end of file token to all tokens
    */
}
