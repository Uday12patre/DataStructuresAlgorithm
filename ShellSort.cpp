#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
{
    int a[25000];
    ifstream read("25000.txt");
    for (int i = 0; i < 25000; i++)
    {
        read >> a[i];
    }

    int gap;
    int n = 25000;
    int countc = 0, counts = 0, j;

    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
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

    for (int i = 0; i < 25000; i++)
    {
        cout << a[i] << ", ";
    }

    cout << "\nNumber of Comparions in Shell Sort = " << countc;
    return 0;
}