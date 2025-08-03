#pragma once

#include <iostream>
#include <string>
#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F function)
{
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}
