#include <iostream>
#include <vector>

using namespace std;

void printIntVector(vector<int> v)
{
    for (vector<int>::iterator itr = v.begin(); itr!= v.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}

int main()
{
    vector<int> vec;  // vec.size() == 0
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8); // vec: {4, 1, 8};  vec.size() == 3

    // Vector specific operations:
    cout << "vec[2]:";
    cout << vec[2] << endl;  // 8 (no range check)
    cout << "vec.at(2)";
    cout << vec.at(2)<< endl;  // 8 (throw range_error exception of out of range)

    cout << "Printing using array method:";
    for (int i=0; i < vec.size(); i++) {
        cout << vec[i] << " ";
     }
    cout << endl;
    cout << "Printing using iterator method:";
    for (vector<int>::iterator itr = vec.begin(); itr!= vec.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
/*    for (it: vec) // C++ 11
        cout << it << " ";
*/
    // Vector is a dynamically allocated contiguos array in memory
    cout << "int *p = &vec[0]; p[2] = 6;\n";
    int *p = &vec[0]; p[2] = 6;
    printIntVector(vec);

    // Common member functions of all containers.
// vec: {4, 1, 8}
    if (vec.empty()) { cout << "Not possible.\n"; }

    cout << "vec.size():";  //3
    cout << vec.size() << endl;  //3

    vector<int> vec2(vec);  // Copy constructor, vec2: {4, 1, 8}

    vec.clear();  // Remove all items in vec;  vec.size() == 0

    vec2.swap(vec);     // vec2 becomes empty, and vec has 3 items.

    // Notes:  No penalty of abstraction, very efficient.

    return 0;
}
