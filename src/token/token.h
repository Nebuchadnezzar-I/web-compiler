#ifndef TOKEN
#define TOKEN


#include <string>


typedef enum {
    ILLEGAL, EOFT, IDENT, INT, ASSIGN, PLUS, MINUS, BANG, ASTERIK, SLASH,
    LT, GT, COMMA, SEMICOLON, LPAREN, RPAREN, LSQUIRLY, RSQUIRLY, FUNCTION,
    LET, TRUE, FALSE, IF, ELSE, RETURN, EQ, NOT_EQ, HASH, DOT, DOUBLEQUOTE
} TokenKind;


TokenKind lookup_ident(std::string ident);
std::string lookup_token(TokenKind token);


#endif // TOKEN
