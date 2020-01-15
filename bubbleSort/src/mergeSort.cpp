#include "mergeSort.h"

void mergeSort(int intArray[], const size_t &length)
{
    //std::cout << "mergeSort()\n";
    int i = 0;
    const int stop = length -1;
    while (i < stop && intArray[i] <= intArray[i+1]) {
        //std::cout << intArray[i] << std::endl;
        i++;
    }
    //std::cout << intArray[i] << std::endl;
    if (i == stop)
        return; // array is sorted
    // otherwise i is index of last sorted element
    // sort the rest of the array, then merge
    mergeSort(intArray+i+1, length-i-1);
    merge(intArray, i, length-1);
}


void merge(int intArray[], const std::size_t &end1, const std::size_t &end2)
{
   int x, i, j;
   int tempArray[end2+1];
   for (x = 0, i = 0, j = end1+1; x <= end2; ++x) {
       if ((j>end2) || (i <= end1) && (intArray[i] < intArray[j])) {
           tempArray[x] = intArray[i];
           i++;
       }
       else {
           tempArray[x] = intArray[j];
           j++;
       }
   }
   //copy tempArray back into intArray
   for (x = 0; x <= end2; x++)
       intArray[x] = tempArray[x];
}

