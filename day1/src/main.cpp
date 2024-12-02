#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <numeric>

int abs(int a)
{
    if (a < 0)
    {
        return a * -1;
    }
    else
    {
        return a;
    }
}

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

    std::vector<int32_t> diff_vector;
    diff_vector.reserve(first.capacity());
    for (int i = 0; i < first.size(); i++)
    {
        diff_vector.push_back(abs(first[i] - second[i]));
    }

    std::cout << std::accumulate(diff_vector.begin(), diff_vector.end(), 0) << std::endl;
}