#ifndef LEXER
#define LEXER


#include "../token/token.h"
#include <cstddef>
#include <cstdint>
#include <string>


typedef struct {
    std::string input;
    size_t input_len;
    size_t position;
    size_t read_position;
    uint8_t ch;
} Lexer;


typedef struct {
    TokenKind type;
    std::string literal;
} Token;


Lexer* newLexer(std::string input);
Token* lexerNextToken(Lexer* l);


#endif // LEXER
