// Finding Missing Numbers in Unsorted Array

#include <iostream>
using namespace std;

int max(int A[], int n)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }

    return max;
}

void display(int A[], int n)
{
    cout << "Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "\t";
    }
}

int main()
{
    int A[] = {4, 3, 1, 10, 0, 5, 2};
    int n = sizeof(A) / sizeof(A[0]);
    display(A, n);
    cout << endl;

    int B[(max(A, n) + 1)] = {0};
    int m = sizeof(B) / sizeof(B[0]);
    display(B, m);

    for (int i = 0; i < n; i++)
    {
        B[A[i]]++;
    }

    cout << endl;

    for (int i = 0; i < max(A, n); i++)
    {
        if (B[i] == 0)
        {
            cout << "Missing Number is: " << i << endl;
        }
    }

    return 0;
}