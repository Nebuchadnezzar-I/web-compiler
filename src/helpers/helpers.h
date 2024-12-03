#ifndef HELPERS
#define HELPERS


#include <string>
#include <vector>


std::vector<std::string> getMainFunctionArgs(int argc, char** argv);
std::string readFileToString(std::string path);
std::vector<std::string> splitStringOnDelimiter(
    std::string input,
    std::string delimiter
);


#endif // HELPERS
