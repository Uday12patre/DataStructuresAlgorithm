#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
    srand(783478326);
    int a;

    ofstream write("25000.txt");
    for (int i = 0; i < 25000; i++)
    {
        a = (rand() % 25000) + 1;
        write << a << "\n";
    }
    return 0;
}