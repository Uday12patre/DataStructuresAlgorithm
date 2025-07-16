#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));

    int num = (rand() % 100) + 1;
    cout << num;
    return 0;
}