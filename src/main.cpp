#include "lexer/lexer.h"
#include "validators/validators.h"
#include "helpers/helpers.h"
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    std::vector<std::string> args = getMainFunctionArgs(argc, argv);
    validateFunctionArgsForCompiler(args);

    // args[0] is safe
    std::string file_content = readFileToString(args[0]);

    Lexer* lexer = newLexer(file_content);

    Token* token;
    while ((token = lexerNextToken(lexer)) != nullptr) {
        if (token->type == TokenKind::EOFT) break;

        std::cout
            << "Token Type: "
            << lookup_token(token->type)
            << ", Literal: "
            << token->literal
            << std::endl;

        delete token;
    }

    delete lexer;

    return EXIT_SUCCESS;
}
