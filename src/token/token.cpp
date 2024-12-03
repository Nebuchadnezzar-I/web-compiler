#include "token.h"
#include <cstdlib>
#include <cstring>
#include <vector>

std::vector<std::string> key_words {
    "fn", "let", "true", "false", "if", "else", "return"
};

TokenKind lookup_ident(std::string ident) {
    size_t keyword_index = 999;
    for (size_t idx = 0; idx < key_words.size(); idx++) {
        if (ident == key_words[idx]) {
            keyword_index = idx;
        }
    }

    switch (keyword_index) {
        case 0: return TokenKind::FUNCTION;
        case 1: return TokenKind::LET;
        case 2: return TokenKind::TRUE;
        case 3: return TokenKind::FALSE;
        case 4: return TokenKind::IF;
        case 5: return TokenKind::ELSE;
        case 6: return TokenKind::RETURN;
        default: return TokenKind::IDENT;
    }
}


std::string lookup_token(TokenKind token) {
    switch (token) {
        case TokenKind::ILLEGAL: return "ILLEGAL";
        case TokenKind::HASH: return "HASH";
        case TokenKind::DOUBLEQUOTE: return "DOUBLEQUOTE";
        case TokenKind::DOT: return "DOT";
        case TokenKind::EOFT: return "EOFT";
        case TokenKind::IDENT: return "IDENT";
        case TokenKind::INT: return "INT";
        case TokenKind::ASSIGN: return "ASSIGN";
        case TokenKind::PLUS: return "PLUS";
        case TokenKind::MINUS: return "MINUS";
        case TokenKind::BANG: return "BANG";
        case TokenKind::ASTERIK: return "ASTERIK";
        case TokenKind::SLASH: return "SLASH";
        case TokenKind::LT: return "LT";
        case TokenKind::GT: return "GT";
        case TokenKind::COMMA: return "COMMA";
        case TokenKind::SEMICOLON: return "SEMICOLON";
        case TokenKind::LPAREN: return "LPAREN";
        case TokenKind::RPAREN: return "RPAREN";
        case TokenKind::LSQUIRLY: return "LSQUIRLY";
        case TokenKind::RSQUIRLY: return "RSQUIRLY";
        case TokenKind::FUNCTION: return "FUNCTION";
        case TokenKind::LET: return "LET";
        case TokenKind::TRUE: return "TRUE";
        case TokenKind::FALSE: return "FALSE";
        case TokenKind::IF: return "IF";
        case TokenKind::ELSE: return "ELSE";
        case TokenKind::RETURN: return "RETURN";
        case TokenKind::EQ: return "EQ";
        case TokenKind::NOT_EQ:return "NOT_EQ";
        default: return "illegal";
    }
}
