#include "Lexer.h"
#include "Parser.h"
#include "DatalogProgram.h"
#include "Interpreter.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    string fileName = argv[1];
    ifstream input(fileName);
    if (!input.is_open()) {
        cout << "File " << fileName << " could not be found or opened." << endl;
        return 1;
    }

    // turns file into one giant string
    string fileString;
    stringstream ssFile;
    ssFile << input.rdbuf();
    fileString = ssFile.str();

    //Runs the lexer with input and then prints
    std::vector<Token*> lexerTokens = lexer->Run(fileString);
    //lexer->Print();
    Parser* parser = new Parser();
    try {
        DatalogProgram* datalogProgram = parser->getStarted(lexerTokens);
        //cout << parser->toString();
        Interpreter interpreter = Interpreter(datalogProgram);
    }
    catch(string stop){
        cout << stop << endl;
    }


    delete lexer;

    return 0;
}

//hello