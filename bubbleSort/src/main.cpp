#include <vector>
#include <algorithm>
#include "Config.h"
#include "bubbleSort.h"
#include "util.h"

using namespace std;


int main(int argc, char *argv[])
{
    cout << "bubbleSort " << bubbleSort_VERSION_MAJOR << "." << bubbleSort_VERSION_MINOR << endl;
    const std::size_t randomVectorLength = 10;
    const int maxRandomNumber = 100;
    int testarray[] = { 5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1 } ;//c-style array
    int testarray2[] = { 5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1 } ;//c-style array
    const size_t testArrayLength = sizeof(testarray)/sizeof(*testarray);
    vector<int> intVector(testarray, testarray+sizeof(testarray)/sizeof(testarray[0]));
    vector<int> intVectorCopy(intVector);
    cout << "testarray: ";
    printIntArray(testarray, testArrayLength);
    cout << "sizeof(testarray): " << sizeof(testarray) << "\nsizeof(*testarray): " << sizeof(*testarray)
         << "\nsizeof(testarray[0]): " << sizeof(testarray[0]) << endl;
    cout << "intVector: ";
    print(intVector);
    cout << "intVectorCopy: ";
    print(intVectorCopy);

    cout << endl;
    sort(testarray, testarray+testArrayLength);
    cout << "std::sorted array: ";
    printIntArray(testarray, testArrayLength);
    cout << "bubblesorted array: ";
    bubbleSort(testarray2, testArrayLength);
    printIntArray(testarray2, testArrayLength);
    cout << "bubblesorted vector: ";
    bubbleSort(intVector);
    print(intVector);

    cout << "std::sorted intVectorCopy: ";
    sort(intVectorCopy.begin(), intVectorCopy.end());
    print(intVectorCopy);

    (intVector==intVectorCopy) ? cout << "intVector and intVectorCopy are equal\n" : cout << "intVector and intVectorCopy are NOT equal\n";

    cout << "\nrandomVector:";
    vector<int> randomVector;
    generate_n(back_insert_iterator<vector<int>>(randomVector),
               randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
    print(randomVector.begin(), randomVector.end());
    is_sorted(randomVector.begin(), randomVector.end()) ? cout << "sorted\n" : cout << "not sorted\n";
    bubbleSort(randomVector.begin(), randomVector.end());
    is_sorted(randomVector.begin(), randomVector.end()) ? cout << "sorted\n" : cout << "not sorted\n";

    return 0;
}

template <typename T>
void printVector(vector<T> v)
{
    typename vector<T>::const_iterator cbegin=v.begin();
    typename vector<T>::const_iterator cend=v.end();
    print(cbegin, cend);
    /*
cout << "printVector(vector<T> v):\n";
cout << "array method:\n";
for(int i=0; i < v.size(); i++)
    cout << v[i] << " ";
cout << endl;
cout << "iterator method:\n";
for(typename vector<T>::iterator itr = v.begin(); itr!= v.end(); ++itr)
cout << *itr << " ";
cout << endl;
cout << "for( : ) method\n";
for(it: v)
cout << it << " ";
cout << endl;
*/
}


/*
    template <typename T>
void print(T t)
{
    cout << "print(T t):\n";
    cout << "array method:\n";
    for(int i=0; i < t.size(); i++)
    cout << t[i] << " ";
    cout << endl;
    cout << "iterator method:\n";
    for(typename T::iterator itr = t.begin(); itr!= t.end(); ++itr)
    cout << *itr << " ";
    cout << endl;
    cout << "for( : ) method\n";
    for (it: t)
    cout << it << " ";
    cout << endl;
}
*/

void printIntVector(vector<int> v)
{
    printVector(v);
    /*    vector<int>::const_iterator cbegin=v.begin();
    vector<int>::const_iterator cend=v.end();
    print(cbegin, cend);
*/
}

