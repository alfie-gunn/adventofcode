#include "level.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        throw std::runtime_error("No input path");
    }

    std::ifstream infile (argv[1]);
    std::string line;
    if (infile.is_open())
    {
        int count = 0;
        while (std::getline(infile, line))
        {
            std::cout << line << std::endl;
            Level current;
            current.from_string(line);
            if (current.validateWithDampener())
            {
                count++;
            }
        }

        std::cout << count << std::endl;
    }
}