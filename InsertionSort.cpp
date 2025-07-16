#include <iostream>
using namespace std;

void sort1(int a[], int n)
{
    int temp, j, countc = 0;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while (j >= 0)
        {
            if (temp < a[j])
            {
                a[j + 1] = a[j];
                j--;
                countc++;
            }

            else
            {
                break;
            }
        }
        a[j + 1] = temp;
    }
    cout << "\nNumber of comparisions in Insertion sort is " << countc << endl;

    return;
}
int main()
{
    int a[] = {6, 5, 4, 9, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    sort1(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}