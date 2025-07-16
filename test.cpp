#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
    int a[100];
    ifstream read("100.txt");

    // Check if file opened successfully
    if (!read.is_open())
    {
        cout << "Error: Could not open 100.txt" << endl;
        return 1; // Indicate an error
    }

    for (int i = 0; i < 100; i++)
    {
        read >> a[i];
    }
    read.close(); // Close the file after reading

    int gap;
    int n = 100;
    int countc = 0; // Number of comparisons
    int counts = 0; // Number of swaps/shifts

    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;

            // This loop performs the shifts
            for (j = i; j >= gap && temp < a[j - gap]; j = j - gap)
            {
                a[j] = a[j - gap];
                countc++; // Increment comparison count
                counts++; // Increment swap/shift count for this move
            }

            // If an element was shifted (i.e., j is not equal to i),
            // then the 'temp' value is placed, which also counts as a data movement
            if (j != i)
            {
                a[j] = temp;
                // We count this as part of the overall "swap" process.
                // Each 'a[j] = a[j-gap]' is a shift, and then 'a[j] = temp' is the final placement.
                // If you consider a full swap as two assignments, then each time
                // 'a[j] = a[j - gap]' is executed, it's one assignment,
                // and the final 'a[j] = temp' is another.
                // So, counting `counts++` inside the loop for each shift,
                // and then potentially once more for the final placement of `temp`
                // if any shifts occurred is a reasonable approach.
                // However, for simplicity and common understanding of "swaps" in insertion-like sorts,
                // each `a[j] = a[j - gap]` is often considered a "move" or "shift"
                // and the final `a[j] = temp` completes the effective insertion.
                // Let's increment `counts` for each shift, and the final placement of `temp`
                // *only if* an actual shift happened (j != i).
                // If j != i, it means at least one `a[j] = a[j - gap]` happened,
                // and then `a[j] = temp` completes the insertion.
                // So, `counts++` inside the inner loop is the most direct way to count shifts.
            }
            a[j] = temp; // This is the final placement of the element
        }
    }

    for (int i = 0; i < 100; i++)
    {
        cout << a[i] << ", ";
    }

    cout << "\nNumber of Comparisons in Shell Sort = " << countc;
    cout << "\nNumber of Swaps/Shifts in Shell Sort = " << counts; // Output the swap count
    return 0;
}