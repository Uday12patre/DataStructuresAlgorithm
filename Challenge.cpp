#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{

    string f;

    ofstream fin(argv[1]);

    srand(55423454);

    for (int i = 0; i < atoi(argv[2]); i++)
    {
        fin << rand() % 1000 << "\n";
    }

    fin.close();

    int a[atoi(argv[2])];
    int j, temp, countc = 0;

    ifstream fi(argv[1]);
    for (int i = 0; i < atoi(argv[2]); i++)
    {
        fi >> a[i];
    }

    fi.close();

    // Insertion Sort

    for (int i = 1; i < atoi(argv[2]); i++)
    {
        temp = a[i];
        j = i - 1;

        while (j >= 0)
        {
            if (temp < a[j])
            {
                a[j + 1] = a[j];
                j = j - 1;
                countc++;
            }

            else
            {
                break;
            }

            a[j + 1] = temp;
        }
    }

    cout << "\n************************************** Sorted Vectors ******************************************\n"
         << endl;
    cout << "Number of Comparisions in Insertion Sort is " << countc << endl;
    for (int i = 0; i < atoi(argv[2]); i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}
