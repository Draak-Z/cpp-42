#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define SIZE 10

int main(int, char**)
{
    Array<int> nb(SIZE);
    int *m = new int[SIZE];

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        const int value = rand() % 1000;
        nb[i] = value;
        m[i] = value;
    }
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "m: " << m[i] << " nb: " << nb[i] << std::endl;
        if (m[i] != nb[i])
        {
            std::cerr << "different values" << std::endl;
            return (1);
        }
    }
    Array<int> tmp = nb;
    Array<int> test(tmp);
    for (int i = 0; i < SIZE; i++)
    {
        nb[i] = rand() % 1000;
    }
    for (int i = 0; i < SIZE; i++)
        std::cout << "nb: " << nb[i] << " tmp: " << tmp[i] << " test: " << test[i] << std::endl;
    try
    {
        nb[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        nb[SIZE] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete [] m;
    return 0;
}
