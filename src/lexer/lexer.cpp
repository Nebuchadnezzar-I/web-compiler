#include "lexer.h"
#include <cstdlib>


void lexerReadChar(Lexer* l);


Lexer* newLexer(const std::string input) {
    Lexer* l = new (std::nothrow) Lexer;
    if (l == nullptr) {
        return nullptr;
    }

    l->ch = 0;
    l->position = 0;
    l->read_position = 0;
    l->input = input;
    l->input_len = input.size();

    lexerReadChar(l);
    return l;
}


uint8_t isLetter(char ch) {
    return ((('a' <= ch) && (ch <= 'z')) || (('A' <= ch) && (ch <= 'Z')) || (ch == '_')) ? 1 : 0;
}


uint8_t isDigit(char ch) {
    return (('0' <= ch) && (ch <= '9')) ? 1 : 0;
}


void skip_white_space(Lexer* l) {
    while ((l->ch == ' ') || (l->ch == '\t') || (l->ch == '\n') || (l->ch == '\r')) {
        lexerReadChar(l);
    }
}


std::string readIdentifier(Lexer* l) {
    size_t start = l->position;

    while (isLetter(l->ch)) {
        lexerReadChar(l);
    }

    return l->input.substr(start, l->position - start);
}


std::string read_number(Lexer* l) {
    size_t start = l->position;

    while (isDigit(l->ch)) {
        lexerReadChar(l);
    }

    return l->input.substr(start, l->position - start);
}


char peek_char(Lexer* l) {
    if (l->read_position >= l->input_len) {
        return 0; // End of input
    }
    return l->input[l->read_position];
}


Token* lexerNextToken(Lexer* l) {
    Token* tok = new Token();
    skip_white_space(l);

    if (tok == NULL) {
        return NULL;
    }

    if (l->ch == '=') {
        lexerReadChar(l);
        if (peek_char(l) == '=') {
            tok->type = TokenKind::EQ;
            tok->literal = "==";
            lexerReadChar(l);
            return tok;
        }
        tok->type = TokenKind::ASSIGN;
        tok->literal = "=";
        return tok;
    }

    if (l->ch == ';') {
        tok->type = TokenKind::SEMICOLON;
        tok->literal = ";";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '.') {
        tok->type = TokenKind::DOT;
        tok->literal = ".";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '"') {
        tok->type = TokenKind::DOUBLEQUOTE;
        tok->literal = '"';
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '(') {
        tok->type = TokenKind::LPAREN;
        tok->literal = "(";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == ')') {
        tok->type = TokenKind::RPAREN;
        tok->literal = ")";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == ',') {
        tok->type = TokenKind::COMMA;
        tok->literal = ",";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '#') {
        tok->type = TokenKind::HASH;
        tok->literal = "#";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '+') {
        tok->type = TokenKind::PLUS;
        tok->literal = "+";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '-') {
        tok->type = TokenKind::MINUS;
        tok->literal = "-";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '!') {
        lexerReadChar(l);
        if (peek_char(l) == '=') {
            tok->type = TokenKind::NOT_EQ;
            tok->literal = "!=";
            lexerReadChar(l);
        }
        tok->type = TokenKind::BANG;
        tok->literal = "!";
        return tok;
    }

    if (l->ch == '*') {
        tok->type = TokenKind::ASTERIK;
        tok->literal = "*";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '/') {
        tok->type = TokenKind::SLASH;
        tok->literal = "/";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '<') {
        tok->type = TokenKind::LT;
        tok->literal = "<";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '>') {
        tok->type = TokenKind::GT;
        tok->literal = ">";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '{') {
        tok->type = TokenKind::LSQUIRLY;
        tok->literal = "{";
        lexerReadChar(l);
        return tok;
    }

    if (l->ch == '}') {
        tok->type = TokenKind::RSQUIRLY;
        tok->literal = "}";
        lexerReadChar(l);
        return tok;
    }

    if ((l->ch == 0) || (l->position > l->input_len)) {
        tok->literal = "";
        tok->type = TokenKind::EOFT;
        lexerReadChar(l);
        return tok;
    }

    if (isLetter(l->ch)) {
        tok->literal = readIdentifier(l);
        tok->type = lookup_ident(tok->literal);
        return tok;
    } else if (isDigit(l->ch)) {
        tok->type = TokenKind::INT;
        tok->literal = read_number(l);
        return tok;
    } else {
        tok->type = TokenKind::ILLEGAL;
        tok->literal = (char*)&(l->ch);
        lexerReadChar(l);
        return tok;
    }

    tok->literal = std::string(1, l->ch);
    tok->type = TokenKind::EOFT;
    lexerReadChar(l);
    return tok;
}


void lexerReadChar(Lexer* l) {
    size_t len;
    len = l->input_len;

    if (l->read_position >= len) {
        l->ch = 0;
    } else {
        l->ch = l->input[l->read_position];
    }

    l->position = l->read_position;
    l->read_position += 1;
}
