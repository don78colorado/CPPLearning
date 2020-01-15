#include "bubbleSort.h"
#include <algorithm>

void bubbleSort(int intArray[], const size_t &length)
{
    for(size_t j = 0; j < length-1; j++)
    {
        for(size_t i = 0; i < length-1; i++)
        {
            //intArray[i]>intArray[i+1] ? cout << "higher\n" : cout << "lower\n";
            if(intArray[i]>intArray[i+1])
                std::swap(intArray[i], intArray[i+1]);
        }
    }
}

