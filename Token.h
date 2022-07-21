#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {

    COLON, // DONE
    COLON_DASH, // DONE
    COMMA, // DONE
    PERIOD, // DONE
    Q_MARK, // DONE
    LEFT_PAREN, //DONE
    RIGHT_PAREN, //DONE
    MULTIPLY, // DONE
    ADD, //DONE
    SCHEMES, //DONE
    FACTS, // DONE
    RULES, // DONE
    QUERIES, //DONE
    ID, //DONE
    STRING, // DONE
    COMMENT,
    UNDEFINED,
    EOF_TYPE

};

class Token
{
private:
    TokenType type;
    std:: string tokenDescription;
    int lineNumber;
    // TODO: add member variables for information needed by Token

public:
    Token(TokenType type, std::string description, int line);
    std::string toString();

    TokenType getTokenType();
    std::string getTokenDescription();
    int getLineNumber();
    std::string getTokenName();
    // TODO: add other needed methods
};

#endif // TOKEN_H

