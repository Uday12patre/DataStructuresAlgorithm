#include <iostream>
using namespace std;

void sort1(int a[], int n)
{
    int temp, j, countc = 0;
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            temp = a[i];
            j = i - gap;

            while (j >= 0)
            {
                if (temp < a[j])
                {
                    a[j + gap] = a[j];
                    j = j - gap;
                    countc++;
                }

                else
                {
                    break;
                }
            }
            a[j + gap] = temp;
        }
    }
    cout << "\nNumber of comparisions in Insertion sort is " << countc << endl;

    return;
}
int main()
{
    int a[] = {23, 87, 6, 44, 91, 38, 76, 59, 12, 67, 5, 99, 18, 33, 74, 40, 86, 20, 95, 62, 7, 29, 48, 71, 13, 89, 58, 36, 90, 9, 1, 25, 80, 31, 41, 27, 60, 45, 64, 14, 77, 8, 56, 50, 22, 32, 98, 35, 3, 73};
    int n = sizeof(a) / sizeof(a[0]);
    sort1(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}