#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int a[25000];
    int countc = 0;
    ifstream read("25000.txt");
    for (int i = 0; i < 25000; i++)
    {
        read >> a[i];
    }

    for (int i = 1; i < 25000; i++) // Insertion Sort
    {
        int temp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
            countc++;
        }
        a[j + 1] = temp;
    }

    for (int i = 0; i < 25000; i++)
    {
        cout << a[i] << ", ";
    }

    cout << "\nNumber of Comparision in Insertion Sort = " << countc;
    return 0;
}