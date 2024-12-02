#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

enum Slope {down, up};

Slope getSlope(int16_t data);

class Level
{
private:
    std::vector<int16_t> data;
    std::vector<int16_t> diff;

    void create_diff();
    bool validate_direction();
    bool validate_slope();

public:
    void add(int16_t data);
    void from_string(std::string input);
    bool validate();
    bool validateWithDampener();
};