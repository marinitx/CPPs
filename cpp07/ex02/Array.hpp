#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;

    public:
        Array() : _array(NULL), _size(0) {}
        Array(unsigned int n) : _array(new T[n]()), _size(n) {}
        Array(const Array& other) : _array(NULL), _size(0)
        {
            *this = other;
        }
        ~Array()
        {
            delete[] _array;
        }
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _array;
                _size = other._size;
                _array = new T[_size]();
                for (unsigned int i = 0; i < _size; ++i)
                {
                    _array[i] = other._array[i];
                }
            }
            return *this;
        }

        //el no constante es para leer y escribir
        T& operator[](unsigned int index)
        {
            if (index >= _size)
            {
                throw std::out_of_range("Index out of range");
            }
            return _array[index];
        }
        //necesito tmb este porque sino no me deja acceder a elementos de arrays constanes
        //el constante es para solo poder leer
        const T& operator[](unsigned int index) const {
            if (index >= _size)
            {
                throw std::out_of_range("Index out of range");
            }
            return _array[index];
        }

        unsigned int size() const { return _size; }
};
