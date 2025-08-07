#include <iostream>
using namespace std;

int findMax(int A[], int n)
{
    int limit = A[0];
    for (int i = 1; i < n; i++)
    {
        if (limit < A[i])
        {
            limit = A[i];
        }
    }

    return limit;
}

void ZeroArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    return;
}

int CountSort(int A[], int n)
{
    int m = findMax(A, n); // passed array within the function

    int *counts = new int[m + 1]; // dynamic array declarations

    ZeroArray(counts, m + 1);

    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0 && A[i] <= m)
        {
            counts[A[i]]++;
        }
    }

    cout << "Sorted Array is ";
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < counts[i]; j++)
        {
            cout << i << " ";
        }
    }

    cout << endl;
    delete[] counts;
    counts = nullptr;
    return 0;
}

int main()
{
    int A[] = {20, 10, 10, 00, 20, 50, 40, 00, 20, 80, 70, 70, 90, 20, 00, 10, 900};
    int n = sizeof(A) / sizeof(A[0]);
    CountSort(A, n);

    return 0;
}

// limitations of Counting sort is that: it can only sort positive numbers;
// The time complexity of Counting Sort is O(n + k), where:
// n is the number of elements in the input array.
// k is the range of the input numbers.