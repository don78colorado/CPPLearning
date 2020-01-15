#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <class InputIterator>
void print(InputIterator begin, InputIterator end)
{
    using namespace std;
    cout << "{";
    --end;
    while(begin!=end)
        cout << *(begin++) << ", ";
    cout << *end << "}\n";
}

void print(std::vector<int> v)
{
    using namespace std;
    /*
    vector<int>::const_iterator cbegin=v.begin();
    vector<int>::const_iterator cend=v.end();
    print(cbegin, cend);
    */
    print(v.begin(), v.end());
}

void reversePrint(std::vector<int> v)
{
    using namespace std;
    /*reverse_iterator<vector<int>::iterator> ritr;
    for (ritr = v.rbegin(); ritr != v.rend(); ritr++)
        cout << *ritr << " ";
    cout << endl;
    reverse_iterator<vector<int>::iterator> rbegin=v.rbegin();
    reverse_iterator<vector<int>::iterator> rend=v.rend();
    print(rbegin, rend);
    */
    print(v.rbegin(), v.rend());
}


int main()
{
    using namespace std;
    std::vector<int> vec1 = { 4,5};
    std::vector<int> vec2 = {12, 14, 16, 18} ;
    print(vec1);
    print(vec2);

    vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
    insert_iterator< vector<int> > i_itr(vec2, it);
    copy(vec1.begin(),vec1.end(), // source
         i_itr);        // destination
    print(vec2);
    // Other insert iterators: back_insert_iterator, front_insert_iterator

    /*
    vector<string> vec4;
    copy(istream_iterator<string>(cin), istream_iterator<string>(),
            back_inserter(vec4));

    copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, " "));

    copy(istream_iterator<string>(cin), istream_iterator<string>(),
         ostream_iterator<string>(cout, " "));
    */
    reversePrint(vec2);

    return 0;
}
