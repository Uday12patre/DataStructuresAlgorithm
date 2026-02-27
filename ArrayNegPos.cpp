#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array *arr)
{
    cout << endl;
    for (int i = 0; i < arr->length; i++)
    {
        cout << arr->A[i] << "\t";
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Rearrange(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }

    return;
}

void merge(struct Array *arr, struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] > arr2->A[j])
        {
            arr->A[k++] = arr2->A[j++];
        }

        else
        {
            arr->A[k++] = arr1->A[i++];
        }
    }

    if (i != arr1->length)
    {
        for (; i < arr1->length; i++)
        {
            arr->A[k++] = arr1->A[i++];
        }
    }

    if (j != arr2->length)
    {
        for (; j < arr2->length; j++)
        {
            arr->A[k++] = arr2->A[j++];
        }
    }

    arr->length = arr1->length + arr2->length;

}

int main()
{
    struct Array arr = {{0}, 20, 0};

    struct Array arr1 = {{1, 3, 5, 7, 9}, 10, 5};
    struct Array arr2 = {{0, 2, 4, 6, 8}, 10, 5};

    cout << "Array 1: ";
    display(&arr1);
    cout << "\nArray 2: ";
    display(&arr2);

    cout << endl;
    merge(&arr, &arr1, &arr2);
    display(&arr);

    return 0;
}