#include <iostream>
using namespace std;

int getMax(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (max < A[i])
            max = A[i];
    }
    return max;
}

void CountSort(int A[], int n, int pos)
{
    int count[10] = {0};
    int B[n];
    for (int i = 0; i < n; i++)
        ++count[(A[i] / pos) % 10];

    for (int i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        B[--count[(A[i] / pos) % 10]] = A[i];

    for (int i = 0; i < n; i++)
        A[i] = B[i];
}

void RadixSort(int A[], int n)
{
    int max = getMax(A, n);
    for (int pos = 1; max / pos > 0; pos = pos * 10)
        CountSort(A, n, pos);
}
int main()
{
    int arr[] = {4, 3, 21, 1, 67, 45, 32, 23, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    RadixSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}