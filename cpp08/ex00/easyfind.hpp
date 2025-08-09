#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &array, int num)
{
    typename T::iterator it = std::find(array.begin(), array.end(), num);
    if (it == array.end())
    {
        throw std::runtime_error("Value not found");
    }
    return it;
}
