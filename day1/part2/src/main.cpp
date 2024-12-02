#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <numeric>
#include <unordered_map>

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
    std::unordered_map<int32_t, int32_t> second;
    if (infile.is_open())
    {
        std::string line;
        while (getline(infile, line))
        {
            first.push_back(std::stoi(line.substr(0, 5)));
            int secondIndex = std::stoi(line.substr(8, 5));
            second[secondIndex] += 1;
        }
        infile.close();
    }

    std::vector<int32_t> similarity_vector;
    similarity_vector.reserve(first.capacity());
    for (int i = 0; i < first.size(); i++)
    {
        auto value = first[i];
        auto indexScore = value * second[value];
        similarity_vector.push_back(indexScore);
    }

    std::cout << std::accumulate(similarity_vector.begin(), similarity_vector.end(), 0) << std::endl;
}