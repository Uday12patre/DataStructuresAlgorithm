// Counting Duplicates in a Sorted Array.

#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int A[] = {2, 2, 2, 4, 4, 4, 6, 6, 8, 8, 99, 100, 100};
    for (int i = 0; i < (sizeof(A) / sizeof(A[0])) - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            int j = i + 1;

            while (A[j] == A[i])
            {
                j++;
            }

            printf("%d is Appearing %d times.\n", A[i], j - i);
            i = j - 1;
        }
    }
    return 0;
}