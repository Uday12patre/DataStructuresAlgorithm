#include <iostream>
#include <stdio.h>
using namespace std;

class diagonal
{
private:
    int n;
    int *A;

public:
    diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }

    diagonal()
    {
        this->n = 2;
        A = new int[2];
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();

    ~diagonal()
    {
        delete[] A;
    }
};

void diagonal::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}

int diagonal::get(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    else
    {
        return 0;
    }
}

void diagonal::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("%d ", A[i]);
            }

            else
            {
                printf("0 ");
            }
        }
        cout << endl;
    }
}

int main()
{
    diagonal z;
    /* z.set(1, 1, 1);
    z.set(2, 2, 2);
    z.set(3, 3, 3);
    z.set(4, 4, 4); */

    z.display();

    cout << "Value at (3,2): " << z.get(3, 2);

    return 0;
}