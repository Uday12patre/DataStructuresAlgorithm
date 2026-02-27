#include <iostream>
using namespace std;

class element
{
public:
    int i;
    int j;
    int x;
};

class sparse
{
private:
    int m;
    int n;
    int num;
    element *e;

public:
    sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new element[this->num];
    }

    ~sparse()
    {
        delete[] e;
    }

    sparse operator+(sparse &s);
    friend istream &operator>>(istream &is, sparse &s);
    friend ostream &operator<<(ostream &os, sparse &s);
};

istream &operator>>(istream &is, sparse &s)
{
    cout << "Enter the non-zero elements:\n";
    for (int i = 0; i < s.num; i++)
    {
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
    return is;
}

ostream &operator<<(ostream &os, sparse &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                cout << s.e[k++].x << "\t";
            }

            else
            {
                cout << "0\t";
            }
        }
        cout << endl;
    }
    return os;
}

sparse sparse::operator+(sparse &s)
{
    int i, j, k;
    if (m != s.m || n != s.n)
        throw invalid_argument("Matrix dimensions do not match");
    sparse *sum = new sparse(m, n, num + s.num);

    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (e[i].i < s.e[j].i)
        {
            sum->e[k++] = e[i++];
        }

        else if (e[i].i > s.e[j].i)
        {
            sum->e[k++] = s.e[j++];
        }

        else
        {
            if (e[i].j < s.e[j].j)
            {
                sum->e[k++] = e[i++];
            }

            else if (e[i].j > s.e[j].j)
            {
                sum->e[k++] = s.e[j++];
            }

            else
            {
                sum->e[k] = e[i];
                sum->e[k++].x = e[i++].x + s.e[j++].x;
            }
        }
    }
    for (; i < num; i++)
        sum->e[k++] = e[i];
    for (; j < s.num; j++)
        sum->e[k++] = e[j];

    sum->num = k;

    return *sum;
}

int main()
{
    sparse s1(3, 3, 3);
    sparse s2(3, 3, 3);
    cin >> s1; // Used Operator Loading for extraction (>>) operator
    cin >> s2; // Used Operator Loading for Insertion (<<) operator

    sparse sum = s1 + s2; // // Used Operator Loading for addition (+) operator

    cout << "First Matrix: \n"
         << s1;
    cout << "Second Matrix: \n"
         << s2;
    cout << "Sum Matrix: \n"
         << sum;

    return 0;
}