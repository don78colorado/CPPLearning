#include <iostream>
using namespace std;
#define DEBUG

#define MIN(a,b) (((a)<(b)) ? a : b)

#define MKSTR( x ) #x
#define concat(a, b) a ## b

int main ()
{
    int i, j;
    int xy = 100;
    i = 100;
    j = 30;
#ifdef DEBUG
    cerr <<"Trace: Inside main function" << endl;
#endif

#if 0
    /* This is commented part */
    cout << MKSTR(HELLO C++) << endl;
#endif

    cout << MKSTR(HELLO C++) << endl;

    cout <<"The minimum is " << MIN(i, j) << endl;

    cout << concat(x, y);
#ifdef DEBUG
    cerr <<"Trace: Coming out of main function" << endl;
#endif
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    return 0;
}

