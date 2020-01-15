#ifndef MERGESORT_H
#define MERGESORT_H

#include <cstddef>
#include <vector>

/* merges two parts of an array
 * elements [0,end1] must be sorted
 * elements (end1,end2] must be sorted
 * after function call, intArray will be sorted
 */
void merge(int intArray[], const std::size_t &end1, const std::size_t &end2);
void mergeSort(int intArray[], const size_t &length);

template <class Iter>
void merge(Iter begin, Iter end1, Iter end2)
{
    std::size_t x;
    Iter i, j;
    const Iter begin2 = end1+1;
    const std::size_t length = end2-begin;
    typename std::iterator_traits<Iter>::value_type tmpArray[length];
    for (x = 0, i = begin, j = begin2; x < length ; ++x) {
        //std::cout << "*i:" << *i << " *j:" << *j << " end1:" << *end1 << " end2:" << *end2 << std::endl;
        if (j==end2 || ((i != begin2) && (*i < *j)))
            tmpArray[x] = *i++;
        else
            tmpArray[x] = *j++;
    }
    //copy tmpArray back into original container
    std::copy(tmpArray, tmpArray+length, begin);
    /* below uses a vector.  array size not limited by size_t
    Iter i, j;
    std::vector<typename std::iterator_traits<Iter>::value_type> tempVector;
    for (i = begin, j = end1+1; i <= end1 && j != end2 ; ) {
        //std::cout << "*i:" << *i << " *j:" << *j << " end1:" << *end1 << " end2:" << *end2 << std::endl;
        if ((j==end2 || i <= end1) && (*i < *j)) {
            tempVector.push_back(*i);
            i++;
        }
        else {
            tempVector.push_back(*j);
            j++;
        }
    }
    // copy remaining
    while (i <= end1) {
        tempVector.push_back(*i);
        i++;
    }
    while (j != end2) {
        tempVector.push_back(*j);
        j++;
    }
    std::copy(tempVector.begin(), tempVector.end(), begin);
    */
}

template <class InputIterator>
void mergeSort(InputIterator begin, InputIterator end)
{
    InputIterator i = begin;
    const InputIterator stop = end-1;
    while (i != stop && *i < *(i+1)) {
        ++i;
    }
    if (i == stop)
        return;
    mergeSort(i+1, end);
    merge(begin, i, end);
}

template <typename Container>
void merge(Container &v, typename Container::iterator begin, typename Container::const_iterator end1)
{
    typename Container::const_iterator end2 = v.end();
    std::size_t x;
    std::size_t length = end2-begin;
    typename Container::const_iterator i, j;
    typename Container::value_type tmpArray[length];
    for (x = 0, i = begin, j = end1+1; x < length ; ++x) {
        //std::cout << "*i:" << *i << " *j:" << *j << " end1:" << *end1 << " end2:" << *end2 << std::endl;
        if (j==end2 || ((i <= end1) && (*i <= *j))) {
            tmpArray[x] = *i;
            i++;
        }
        else {
            tmpArray[x] = *j;
            j++;
        }
    }
    std::copy(tmpArray, tmpArray+length, begin);
}

template <typename Container, class InputIterator>
void mergeSort(Container &c, InputIterator begin, InputIterator end)
{
    typename Container::iterator i = begin;
    //int blah;
    const InputIterator stop = end-1;
    while (i != stop && *i < *(i+1)) {
        //blah = *i;
        //std::cout << "blah:" << blah << std::endl;
        ++i;
    }
    if (i == stop)
        return;
    mergeSort(c, i+1, end);
    merge(c, begin, i);
}

template <typename Container>
void mergeSort(Container &c) {
    mergeSort(c, c.begin(), c.end());
}

#endif // MERGESORT_H
