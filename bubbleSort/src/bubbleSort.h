#include <cstddef>
#include <vector>

template <class InputIterator>
void bubbleSort(InputIterator begin, InputIterator end);
void bubbleSort(int intArray[], const size_t &length);
template <typename T>
void bubbleSort(std::vector<T> &v);

#include "bubbleSort_impl.tcc"
