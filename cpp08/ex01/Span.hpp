#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span
{
    private:
        unsigned int    _maxSize;
        std::vector<int> _numbers;

    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);

        template <typename T>
        void addRange(T begin, T end) {
            if (_numbers.size() + std::distance(begin, end) > _maxSize)
                throw std::runtime_error("Not enough space to add numbers");
            _numbers.insert(_numbers.end(), begin, end);
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};
