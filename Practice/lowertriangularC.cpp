#include <iostream>
using namespace std;

class LowerTriangular
{

private:
    int *A;
    int n;

public:
    LowerTriangular(int n)
    {
        this->n = n;
        A = new int[(n * (n + 1)) / 2];
    }

    ~LowerTriangular()
    {
        delete[] A;
    }

    void set1(int i, int j, int x);
    int get1(int i, int j);
    void display1();

    void set2(int i, int j, int x);
    int get2(int i, int j);
    void display2();
};

void LowerTriangular::set1(int i, int j, int x) // Index are calculated by Row-Major Formula
{
    if (i >= j)
    {
        A[((i - 1) * i) / 2 + (j - 1)] = x;
    }
    return;
}

int LowerTriangular::get1(int i, int j) // Index are calculated by Row-Major Formula
{
    if (i >= j)
    {
        return A[((i - 1) * i) / 2 + (j - 1)];
    }
    else
    {
        return 0;
    }
}

void LowerTriangular::set2(int i, int j, int x) // Index are calculated by Column-Major Formula
{
    if (i >= j)
    {
        A[n * (j - 1) - ((j - 2) * (j - 1)) / 2 + i - j] = x;
    }
}

int LowerTriangular::get2(int i, int j) // Index are calculated by Column-Major Formula
{
    if (i >= j)
    {
        return A[n * (j - 1) - ((j - 2) * (j - 1)) / 2 + i - j];
    }
    else
    {
        return 0;
    }
}

void LowerTriangular::display1()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                printf("%d ", A[((i - 1) * i) / 2 + (j - 1)]);
            }

            else
            {
                printf("0 ");
            }
        }
        cout << endl;
    }
}

void LowerTriangular::display2()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                printf("%d ", A[n * (j - 1) - ((j - 2) * (j - 1)) / 2 + i - j]);
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
    int d;
    cout << "Enter the Dimension of Square Matrix: ";
    cin >> d;

    LowerTriangular lt(d);
    int x;
    cout << "Enter all elements: " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lt.set1(i, j, x);
        }
    }

    cout << "\nThe Matrix: \n";
    lt.display1();

    return 0;
}