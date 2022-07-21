#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"

class Interpreter {
private:
    DatalogProgram datalogProgram;
    Database database;
    unsigned int schemeCounter = 0;
public:
    Interpreter(DatalogProgram* datalogProgram1){
        datalogProgram = *datalogProgram1;
        schemesToDatabase(datalogProgram.getSchemes());
        factsToDatabase(datalogProgram.getFacts());
        datalogProgram.createDG();
        std::cout << "\nRule Evaluation\n";
        evaluateRules();
        //std::cout << "\nSchemes populated after " + std::to_string(schemeCounter) +" passes through the Rules.\n";
        std::cout << "\nQuery Evaluation\n";
        evaluateQueries(datalogProgram.getQueries());

    }
    void schemesToDatabase(std::vector<Predicate*> Schemes);
    void factsToDatabase(std::vector<Predicate*> Facts);
    void evaluateQueries(std::vector<Predicate*> Queries);

    void evaluateRules();
    void evaluateRule(Rule inputRule);

    Relation evaluatePredicate(Predicate* p);
    std::string toString();

    void evaluateRuleVec(std::vector<Rule*> myRules);////////////////////////////

};


#endif //INTERPRETER_H
