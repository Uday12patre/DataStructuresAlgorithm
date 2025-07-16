#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    cout << "Enter Size of array: ";
    cin >> n;
    int A[n], Max, Min;
    for (int i = 0; i < n; i++) // Populating Array with Random Numbers
    {
        A[i] = (rand() % 100) + 1;
    }

    cout << "Array in Forward Order: " << endl;
    for (int i = 0; i < n; i++) // Display Array in Forward
    {
        cout << A[i] << " ";
        cout << endl;
    }

    cout << "Array in Backward Order: " << endl;
    for (int i = n - 1; i >= 0; i--) // Display Array in Backward
    {
        cout << A[i] << " ";
        cout << endl;
    }

    Min = A[0];
    Max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > Max) // Finding Max Value
        {
            Max = A[i];
        }

        if (A[i] < Min) // Finding Min Value
        {
            Min = A[i];
        }
    }

    cout << "Maximum Value: " << Max << endl;
    cout << "Minimum Value: " << Min << endl;
    return 0;
}