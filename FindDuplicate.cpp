// Finding Duplicate Elements in a Sorted Array

#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int A[] = {-1, -1, 0, 0, 2, 3, 4, 4, 4, 4, 5, 6, 6, 7, 7, 9, 9};
    int ld = INT_MIN; // Last Duplicate;

    for (int i = 0; i < (sizeof(A) / sizeof(A[0])) - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            if (ld != A[i])
            {
                cout << "Duplicate Number is: " << A[i] << endl;
                ld = A[i];
            }
        }
    }

    return 0;
}