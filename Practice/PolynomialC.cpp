#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For C
// #include<cmath> // for C++

using namespace std;
struct term
{
    int coeff;
    int power;
};

struct poly
{
    int n;
    struct term *t;
};

void read(struct poly *p)
{
    printf("Enter no. of terms: ");
    scanf("%d", &p->n);

    p->t = (struct term *)malloc(p->n * sizeof(struct term));

    for (int i = 0; i < p->n; i++)
    {
        printf("Enter Polynomial Term %d: ", i + 1);
        scanf("%d%d", &p->t[i].coeff, &p->t[i].power);
    }
}

long int PolyEval(struct poly p, int x)
{
    int eval = 0;
    for (int i = 0; i < p.n; i++)
    {
        eval = eval + (p.t[i].coeff * (long int)pow(x, p.t[i].power));
    }

    return eval;
}

void display(struct poly p)
{
    printf("Polynomial: ");
    for (int i = 0; i < p.n; i++)
    {
        printf("%dx^%d", p.t[i].coeff, p.t[i].power);

        if (i < p.n - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

struct poly add(struct poly p1, struct poly p2)
{
    struct poly p3;
    p3.t = (struct term *)malloc((p1.n + p2.n) * sizeof(struct term));
    int i = 0, j = 0, k = 0;

    while (i < p1.n && j < p2.n)
    {
        if (p1.t[i].power > p2.t[j].power)
        {
            p3.t[k++] = p1.t[i++];
        }

        else if (p1.t[i].power < p2.t[j].power)
        {
            p3.t[k++] = p2.t[j++];
        }

        else if (p1.t[i].power == p2.t[j].power)
        {
            p3.t[k].coeff = p1.t[i].coeff + p2.t[j].coeff;
            p3.t[k++].power = p1.t[i].power;
            i++;
            j++;
        }
    }

    while (i < p1.n)
        p3.t[k++] = p1.t[i++];
    while (j < p2.n)
        p3.t[k++] = p2.t[j++];

    p3.n = k;
    return p3;
}

int main()
{
    struct poly p1, p2, p3;
    read(&p1);
    read(&p2);

    display(p1);
    display(p2);
    printf("Addition ");
    display(add(p1, p2));

    return 0;
}