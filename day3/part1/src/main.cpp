#include <stdexcept>
#include <fstream>
#include <iostream>
#include <regex>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        throw std::runtime_error("No path provided");
    }

    std::ifstream infile(argv[1]);
    std::string fileContents((std::istreambuf_iterator<char>(infile)),
                             std::istreambuf_iterator<char>());

    std::regex pattern ("mul\\((\\d+),(\\d+)\\)");
    auto begin = std::sregex_iterator(fileContents.begin(), fileContents.end(), pattern);
    auto end = std::sregex_iterator();

    int total = 0;

    for (auto current = begin; current != end; ++current)
    {
        auto match = *current;
        std::cout << match.str() << std::endl;
        std::cout << match[1].str() << std::endl;
        std::cout << match[2].str() << std::endl;
        total += std::stoi(match[1].str()) * std::stoi(match[2].str());
    }

    std::cout << total << std::endl;
}