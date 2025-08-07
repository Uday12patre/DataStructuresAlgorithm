#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int A[], int lb, int ub)
{
    int pivot = A[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (A[start] <= pivot)
        {
            start++;
        }

        while (A[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            swap(A[start], A[end]);
        }
    }

    swap(A[lb], A[end]);
    return end;
}

void QuickSort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(A, lb, ub);
        QuickSort(A, lb, loc - 1);
        QuickSort(A, loc + 1, ub);
    }
}
int main()
{
    int arr[] = {4, 3, 6, 8, 7, 9, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n - 1);

    cout << "Sorted Array is";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    cout << ".\n";
    return 0;
}