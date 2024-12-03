#include "validators.h"
#include <cstdlib>
#include <iostream>
#include <filesystem>


void validateFunctionArgsForCompiler(std::vector<std::string> args) {
    if (args[0] == "") {
        std::cout << "Empty path" << std::endl;
        exit(1);
    }

    if (!std::filesystem::is_regular_file(args[0])) {
        std::cout << "File does not exist" << std::endl;
        exit(1);
    }
}
