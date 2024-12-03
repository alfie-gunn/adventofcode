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

    bool active = true;

    std::ifstream infile(argv[1]);
    std::string fileContents((std::istreambuf_iterator<char>(infile)),
                             std::istreambuf_iterator<char>());

    std::regex pattern ("mul\\((\\d+),(\\d+)\\)|do\\(\\)|don't\\(\\)");
    auto begin = std::sregex_iterator(fileContents.begin(), fileContents.end(), pattern);
    auto end = std::sregex_iterator();

    int total = 0;

    for (auto current = begin; current != end; ++current)
    {
        auto match = *current;
        if (match.str().substr(0, 3) == "mul")
        {
            std::cout << match.str() << std::endl;
            if (active)
            {
                total += std::stoi(match[1].str()) * std::stoi(match[2].str());
            }
        }
        else if (match.str().substr(0, 5) == "don't")
        {
            std::cout << match.str() << std::endl;
            std::cout << "DISABLING" << std::endl;
            active = false;
        }
        else
        {
            active = true;
        }
    }

    std::cout << total << std::endl;
}