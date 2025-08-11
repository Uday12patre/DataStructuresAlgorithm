// Array name is constant pointer to its first element.
// For pointers Read Arabic 
#include <iostream>
using namespace std;
int main()
{
    int *p = nullptr, A[10];
    for (int i = 0; i < 10; i++)
    {
        A[i] = i + 1;
    }

    p = A;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << *p << endl;
    //     p = p + 1;
    // }

    for (int i = 0; i < 10; i++)
    {
        cout << "A[" << i << "] = " << p[i] << endl;
        cout << "A[" << i << "] = " << *(A + i) << endl;
        cout << "A[" << i << "] = " << A[i] << endl;
    }

    return 0;
}
