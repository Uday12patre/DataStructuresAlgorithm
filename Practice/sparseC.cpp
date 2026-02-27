#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct element
{
    int i;
    int j;
    int x;
};

struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};

void create(struct sparse *s)
{
    printf("Enter Dimensions: ");
    scanf("%d%d", &s->m, &s->n);

    printf("Enter No. of Non-zero: ");
    scanf("%d", &s->num);

    s->e = (struct element *)malloc(s->num * sizeof(struct element));
    printf("Enter All non-zero elements: \n");

    for (int i = 0; i < s->num; i++)
    {
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
        s->e[i].i--;
        s->e[i].j--;
    }

    return;
}

void display(struct sparse s)
{
    printf("\nMatrix of Size %dx%d\n", s.m, s.n);
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (k < s.num && i == s.e[k].i && j == s.e[k].j)
            {
                printf("%d\t", s.e[k++].x);
            }
            else
            {
                printf("0\t");
            }
        }

        printf("\n");
    }
}

struct sparse *add(struct sparse *s1, struct sparse *s2)
{
    struct sparse *sum;
    int i, j, k;
    i = j = k = 0;

    sum = (struct sparse *)malloc(sizeof(struct sparse));
    sum->e = (struct element *)malloc((s1->num + s2->num) * sizeof(struct element));

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)
        {
            sum->e[k++] = s1->e[i++];
        }

        else if (s1->e[i].i > s2->e[j].i)
        {
            sum->e[k++] = s2->e[j++];
        }

        else
        {
            if (s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++];
            }

            else if (s1->e[i].j > s2->e[j].j)
            {
                sum->e[k++] = s2->e[j++];
            }

            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }

    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
};

int main()
{
    struct sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);

    cout << "first matrix: \n";
    display(s1);

    cout << "\nsecond matrix: \n";
    display(s2);

    cout << "\nsum matrix: \n";
    display(*s3);

    return 0;
}