#include <iostream>
using namespace std;
int main()
{

    int *p, **a, n = 123;

    p = &n;
    a = &p;

    cout << "n = " << n << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "a = " << a << endl;
    cout << "**a = " << **a << endl;

    return 0;
}