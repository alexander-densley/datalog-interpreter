#ifndef PARSER_H
#define PARSER_H

#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"
#include "DatalogProgram.h"

#include "Token.h"
#include <vector>

class Parser {
private:
    std::vector<Token*> parseTokens;
    int curIndex = 0;

    Predicate* tempPredicate;
    Rule* tempRule;

    DatalogProgram* datalogProgram;

public:
    Parser();
    std::string toString();
    DatalogProgram* getStarted(std::vector<Token*> input);
    void match(int index, TokenType type);


    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQueryList();

    void parseScheme();
    void parseFact();
    void parseRule();
    void parseQuery();

    void parseHeadPredicate();
    void parsePredicate();

    void parsePredicateList();
    void parseParameterList();
    void parseStringList();
    void parseIdList();
    void parseParameter();






    void Start();

};


#endif //PARSER_H
