#include "Token.h"


Token::Token(TokenType type, std::string description, int line) {
    Token::type = type;
    Token::tokenDescription = description;
    Token::lineNumber = line;

    // TODO: initialize all member variables
}

std::string Token::toString(){
    std::string finalString = "";

    switch(Token::type){
        case TokenType::COMMA:
            finalString = "(COMMA,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::COLON:
            finalString = "(COLON,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::COLON_DASH:
            finalString = "(COLON_DASH,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::PERIOD:
            finalString = "(PERIOD,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::Q_MARK:
            finalString = "(Q_MARK,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::LEFT_PAREN:
            finalString = "(LEFT_PAREN,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::RIGHT_PAREN:
            finalString = "(RIGHT_PAREN,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::MULTIPLY:
            finalString = "(MULTIPLY,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::ADD:
            finalString = "(ADD,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::SCHEMES:
            finalString = "(SCHEMES,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::FACTS:
            finalString = "(FACTS,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::RULES:
            finalString = "(RULES,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::QUERIES:
            finalString = "(QUERIES,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::ID:
            finalString = "(ID,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::STRING:
            finalString = "(STRING,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::COMMENT:
            finalString = "(COMMENT,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::UNDEFINED:
            finalString = "(UNDEFINED,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
        case TokenType::EOF_TYPE:
            finalString = "(EOF,\"" + Token::tokenDescription + "\"," + std::to_string(lineNumber) + ")" + "\n";
            break;
    }
    return finalString;
}

TokenType Token::getTokenType() {
    return type;
}

std::string Token::getTokenDescription(){
    return tokenDescription;
}
int Token::getLineNumber(){
    return lineNumber;
}

std::string Token::getTokenName() {
    std::string tokenName = "";

    switch(Token::type){
        case TokenType::COMMA:
            tokenName = "COMMA";
            break;
        case TokenType::COLON:
            tokenName = "COLON";
            break;
        case TokenType::COLON_DASH:
            tokenName = "COLON_DASH";
            break;
        case TokenType::PERIOD:
            tokenName = "PERIOD";
            break;
        case TokenType::Q_MARK:
            tokenName = "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            tokenName = "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            tokenName = "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            tokenName = "MULTIPLY";
            break;
        case TokenType::ADD:
            tokenName = "ADD";
            break;
        case TokenType::SCHEMES:
            tokenName = "SCHEMES";
            break;
        case TokenType::FACTS:
            tokenName = "FACTS";
            break;
        case TokenType::RULES:
            tokenName = "RULES";
            break;
        case TokenType::QUERIES:
            tokenName = "QUERIES";
            break;
        case TokenType::ID:
            tokenName = "ID";
            break;
        case TokenType::STRING:
            tokenName = "STRING";
            break;
        case TokenType::COMMENT:
            tokenName = "COMMENT";
            break;
        case TokenType::UNDEFINED:
            tokenName = "UNDEFINED";
            break;
        case TokenType::EOF_TYPE:
            tokenName = "EOF";
            break;
    }
    return tokenName;
}
