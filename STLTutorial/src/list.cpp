#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printIntList(list<int> l)
{
    cout << "{";
    list<int>::iterator itr_end = l.end();
    --itr_end;
    for(list<int>::iterator itr=l.begin(); itr != itr_end; ++itr)
        cout << *itr << ", ";
    cout << *itr_end << "}\n";
}

int main()
{
    cout << "list<int> mylist = {5, 2, 9};\n";
    list<int> mylist = {5, 2, 9};
    printIntList(mylist);

    cout << "mylist.push_back(6);\n";
    mylist.push_back(6);
    printIntList(mylist);

    cout << "mylist.push_front(4);\n";
    mylist.push_front(4);
    printIntList(mylist);

    list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); //itr -> 2
    mylist.insert(itr, 8);  // O(1), faster than vector/dque
    printIntList(mylist);

    cout << "itr++;\n";
    itr++;  //itr->9
    cout << "mylist.erase(itr);\n";
    mylist.erase(itr); // O(1)
    printIntList(mylist);

    return 0;
}

