#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <exception>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        throw std::runtime_error("No argument given");
    }
    std::ifstream infile(argv[1]);
    std::vector<int32_t> first;
    std::vector<int32_t> second;
    if (infile.is_open())
    {
        std::string line;
        while (getline(infile, line))
        {
            first.push_back(std::stoi(line.substr(0, 5)));
            second.push_back(std::stoi(line.substr(8, 5)));
        }
        infile.close();
    }

    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
}