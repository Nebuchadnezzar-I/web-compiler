#include "helpers.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <regex>
#include <string>


std::string readFileToString(std::string path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << path << std::endl;
        exit(1);
    }

    std::string file_content;
    std::string line;
    while (getline(file, line)) {
        file_content += line + "\n";
    }

    return file_content;
}


std::vector<std::string> getMainFunctionArgs(int argc, char** argv) {
    std::vector<std::string> args;

    if (argc <= 1) {
        return args;
    }

    for (int idx = 1; idx < argc; idx++) {
        args.push_back(argv[idx]);
    }

    return args;
}

std::vector<std::string> splitStringOnDelimiter(
    std::string input,
    std::string delimiter
) {
    std::regex regexz(delimiter);
    std::vector<std::string> list(
        std::sregex_token_iterator(input.begin(), input.end(), regexz, -1),
        std::sregex_token_iterator()
    );
    return list;
}
