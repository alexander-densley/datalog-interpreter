#include "Parser.h"
#include <sstream>
#include <iostream>


Parser::Parser() {
    datalogProgram = new DatalogProgram();
}
std::string Parser::toString(){
    return datalogProgram->toString();
}

DatalogProgram* Parser::getStarted(std::vector<Token*> input){
    parseTokens = input;
    Start();

    return datalogProgram;

}

void Parser::match(int index, TokenType type) {
    if (parseTokens[index]->getTokenType() == type){
        curIndex++;
    }
    else{
        std::string tokenException = "";
        std::ostringstream tokenString;

        tokenString << "Failure!\n  (" << parseTokens.at(curIndex)->getTokenName()
        << ",\"" << parseTokens.at(curIndex)->getTokenDescription() << "\","
        << std::to_string(parseTokens.at(curIndex)->getLineNumber())
        << ")\n";

        tokenException = tokenString.str();

        throw tokenException;
    }
}

void Parser::Start(){
    for (unsigned int i = 0; i < parseTokens.size(); i++){
        if (parseTokens.at(i)->getTokenType() == TokenType::COMMENT){
            parseTokens.erase(parseTokens.begin() + i);
            i--;
        }
    }
    match(curIndex, TokenType::SCHEMES);
    match(curIndex, TokenType::COLON);

    parseScheme();
    datalogProgram->addScheme(tempPredicate);
    parseSchemeList();

    match(curIndex,TokenType::FACTS);
    match(curIndex,TokenType::COLON);

    parseFactList();

    match(curIndex,TokenType::RULES);
    match(curIndex,TokenType::COLON);

    parseRuleList();

    match(curIndex,TokenType::QUERIES);
    match(curIndex,TokenType::COLON);

    parseQuery();
    datalogProgram->addQuery(tempPredicate);
    parseQueryList();

    match(curIndex,TokenType::EOF_TYPE);

}


void Parser::parseSchemeList(){ // done
    if(parseTokens.at(curIndex)->getTokenType() == TokenType::FACTS){}
    else{
        parseScheme();
        datalogProgram->addScheme(tempPredicate);
        parseSchemeList();
    }
}
void Parser::parseFactList(){
    if(parseTokens.at(curIndex)->getTokenType() == TokenType::RULES){}
    else{
        parseFact();
        datalogProgram->addFact(tempPredicate);
        parseFactList();
    }

}
void Parser::parseRuleList(){
    if(parseTokens.at(curIndex)->getTokenType() == TokenType::QUERIES){}
    else{
        parseRule();
        datalogProgram->addRule(tempRule);
        parseRuleList();
    }
}
void Parser::parseQueryList(){
    if(parseTokens.at(curIndex)->getTokenType() == TokenType::EOF_TYPE){}
    else{
        parseQuery();
        datalogProgram->addQuery(tempPredicate);
        parseQueryList();
    }
}

void Parser::parseScheme(){
    match(curIndex, TokenType::ID);

    tempPredicate = new Predicate(parseTokens.at(curIndex - 1)->getTokenDescription());

    match(curIndex, TokenType::LEFT_PAREN);
    match(curIndex, TokenType::ID);

    tempPredicate->addParameter(new Parameter(parseTokens.at(curIndex - 1)->getTokenDescription()));

    parseIdList();

    match(curIndex, TokenType::RIGHT_PAREN);
};
void Parser::parseFact() {
    match(curIndex,TokenType::ID);

    tempPredicate = new Predicate(parseTokens.at(curIndex - 1)->getTokenDescription());

    match(curIndex,TokenType::LEFT_PAREN);
    match(curIndex,TokenType::STRING);

    tempPredicate->addParameter(new Parameter(parseTokens.at(curIndex - 1)->getTokenDescription()));

    parseStringList();

    match(curIndex,TokenType::RIGHT_PAREN);
    match(curIndex,TokenType::PERIOD);
}
void Parser::parseRule() {
    parseHeadPredicate();

    tempRule = new Rule(tempPredicate);

    match(curIndex,TokenType::COLON_DASH);

    parsePredicate();

    tempRule->addPredicate(tempPredicate);

    parsePredicateList();

    match(curIndex,TokenType::PERIOD);
}
void Parser::parseQuery(){
    parsePredicate();
    match(curIndex, TokenType::Q_MARK);
}

void Parser::parseHeadPredicate() {
    match(curIndex,TokenType::ID);
    tempPredicate = new Predicate(parseTokens.at(curIndex - 1)->getTokenDescription());

    match(curIndex,TokenType::LEFT_PAREN);
    match(curIndex,TokenType::ID);

    tempPredicate->addParameter(new Parameter(parseTokens.at(curIndex - 1)->getTokenDescription()));


    parseIdList();

    match(curIndex,TokenType::RIGHT_PAREN);
}
void Parser::parsePredicate() {
    match(curIndex,TokenType::ID);

    tempPredicate = new Predicate(parseTokens.at(curIndex - 1)->getTokenDescription());

    match(curIndex,TokenType::LEFT_PAREN);

    parseParameter();

    tempPredicate->addParameter(new Parameter(parseTokens.at(curIndex - 1)->getTokenDescription()));

    parseParameterList();

    match(curIndex,TokenType::RIGHT_PAREN);
}

void Parser::parsePredicateList() {
    if (parseTokens.at(curIndex)->getTokenType() == TokenType::PERIOD) {}
    else {
        match(curIndex, TokenType::COMMA);

        parsePredicate();

        tempRule->addPredicate(tempPredicate);

        parsePredicateList();
    }
}
void Parser::parseParameterList() {
    if (parseTokens.at(curIndex)->getTokenType() == TokenType::RIGHT_PAREN) {}
    else {
        match(curIndex, TokenType::COMMA);

        parseParameter();

        tempPredicate->addParameter(new Parameter(parseTokens.at(curIndex - 1)->getTokenDescription()));

        parseParameterList();
    }
}
void Parser::parseStringList() {
    if (parseTokens.at(curIndex)->getTokenType() == TokenType::RIGHT_PAREN) {}
    else {
        match(curIndex, TokenType::COMMA);
        match(curIndex,TokenType::STRING);

        tempPredicate->addParameter(new Parameter(parseTokens.at(curIndex - 1)->getTokenDescription()));
        // added here

        parseStringList();
    }
}
void Parser::parseIdList() {
    if (parseTokens.at(curIndex)->getTokenType() == TokenType::RIGHT_PAREN) {}
    else {
        match(curIndex, TokenType::COMMA);
        match(curIndex,TokenType::ID);

        tempPredicate->addParameter(new Parameter(parseTokens.at(curIndex - 1)->getTokenDescription()));

        parseIdList();
    }
}
void Parser::parseParameter() {

    if (parseTokens.at(curIndex)->getTokenType() == TokenType::ID) {
        match(curIndex,TokenType::ID);
    }
    else if (parseTokens.at(curIndex)->getTokenType() == TokenType::STRING){
        match(curIndex,TokenType::STRING);
    }
}


