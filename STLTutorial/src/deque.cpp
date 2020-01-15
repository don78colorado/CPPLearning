#include <iostream>
#include <deque>

using namespace std;

void printIntDeque(deque<int> deq)
{
    cout << "{";
    deque<int>::iterator itr=deq.begin();
    for(; itr+1 != deq.end(); itr++)
        cout << *itr << ", ";
    cout << *itr << "}\n";
}

int main()
{
    //cout << "deque<int> deq = { 4, 6, 7 };\n";
    deque<int> deq = { 4, 6, 7 }; // Can't do this in C++98
    /*deque<int> deq;
    deq.push_back(4);
    deq.push_back(6);
deq.push_back(7);
*/
    printIntDeque(deq);

    cout << "deq.push_front(2);\n";
    deq.push_front(2);  // deq
    printIntDeque(deq);

    cout << "deq.push_back(3);\n";
    deq.push_back(3);
    printIntDeque(deq);

    // Deque has similar interface with vector
    cout << "cout << deq[1] << endl;\n";
    cout << deq[1] << endl;
    return 0;
}
