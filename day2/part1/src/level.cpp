#include "level.hpp"

inline Slope getSlope(int16_t data)
{
    if (data > 0)
    {
        return up;
    }
    else
    {
        return down;
    }
}

void Level::add(int16_t data)
{
    this->data.push_back(data);
}

void Level::from_string(std::string input)
{
    std::stringstream input_stream (input);
    int16_t inputInt;

    while (input_stream >> inputInt)
    {
        this->add(inputInt);
    }
}

void Level::create_diff()
{
    for (int i = 1; i < data.size(); i++)
    {
        diff.push_back(data[i] - data[i-1]);
    }

    for (int i = 0; i < diff.size(); i++)
    {
        std::cout << diff[i] << " ";
    }
    std::cout << std::endl;
}

bool Level::validate_direction()
{
    if (diff[0] == 0)
    {
        return false;
    }

    Slope start = (diff[0] > 0) ? up : down;

    for (int i = 1; i < diff.size(); i++)
    {
        if (start != getSlope(diff[i]))
        {
            return false;
        }
    }

    return true;
}

bool Level::validate_slope()
{
    for (int i = 0; i < diff.size(); i++)
    {
        if (abs(diff[i]) > 3 || abs(diff[i]) < 1)
        {
            return false;
        }
    }

    return true;
}

bool Level::validate()
{
    this->create_diff();
    if (!this->validate_direction())
    {
        return false;
    }
    if (!this->validate_slope())
    {
        return false;
    }
    return true;
}