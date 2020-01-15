#ifndef UTIL_H
#define UTIL_H

#include <iostream>

void swap(int &a, int &b)
{
    std::cout << "my swap(" << a << ", " << b << ")\n" ;
    int c = a;
    a = b;
    b = c;
}

template <class InputIterator>
void print(InputIterator begin, InputIterator end)
{
    std::cout << "{";
    --end;
    while(begin!=end)
        std::cout << *(begin++) << ", ";
    std::cout << *end << "}\n";
}

void print(std::vector<int> v)
{
    using namespace std;
    print(v.begin(), v.end());
}

void reversePrint(std::vector<int> v)
{
    using namespace std;
    print(v.rbegin(), v.rend());
}

void printIntArray(const int intArray[], const size_t &length)
{
    std::cout << "{";
    for(size_t i = 0; i < length-1; i++)
        std::cout << intArray[i] << ", ";
    std::cout << intArray[length-1] << "}\n";
}


#endif // UTIL_H
