// Consider two polynomial expressions of any degree. Design solution to perform addition, and subtraction of these
// two polynomials with suitable data structure and display results.

#include <iostream>
using namespace std;

struct node
{
    int coeff;
    int power;
    node *next;
};

class poly
{
    node *head;

public:
    poly()
    {
        head = NULL;
    }

    void addterm(int coeff, int power)
    {
        if (coeff == 0)
            return; // Ignore 0 terms
        node *nn = new node;
        nn->coeff = coeff;
        nn->power = power;
        nn->next = NULL;

        if (!head)
        {
            head = nn;
            return;
        }

        node *p = head;
        while (p->next)
        {
            p = p->next;
        }
        p->next = nn;
    }

    void display_poly()
    {
        node *p = head;
        while (p)
        {
            cout << p->coeff << "x^" << p->power;
            if (p->next && p->next->coeff >= 0)
            {
                cout << "+";
            }
            p = p->next;
        }
        cout << "\n";
    }

    // Operator overloading for +
    poly operator+(poly &p2)
    {
        poly result;
        node *p1_node = this->head;
        node *p2_node = p2.head;

        while (p1_node && p2_node)
        {
            if (p1_node->power == p2_node->power)
            {
                result.addterm(p1_node->coeff + p2_node->coeff, p1_node->power);
                p1_node = p1_node->next;
                p2_node = p2_node->next;
            }
            else if (p1_node->power > p2_node->power)
            {
                result.addterm(p1_node->coeff, p1_node->power);
                p1_node = p1_node->next;
            }
            else
            {
                result.addterm(p2_node->coeff, p2_node->power);
                p2_node = p2_node->next;
            }
        }

        // If terms remain in p1
        while (p1_node)
        {
            result.addterm(p1_node->coeff, p1_node->power);
            p1_node = p1_node->next;
        }

        // If terms remain in p2
        while (p2_node)
        {
            result.addterm(p2_node->coeff, p2_node->power);
            p2_node = p2_node->next;
        }

        return result;
    }
};

int main()
{
    poly p1, p2, p3;

    // p1 = 8x^3 + 4x^2 + 5
    p1.addterm(8, 3);
    p1.addterm(4, 2);
    p1.addterm(5, 0);

    cout << "p1 = ";
    p1.display_poly();

    // p2 = 1x^3 + 3x^2 + 4
    p2.addterm(1, 3);
    p2.addterm(3, 2);
    p2.addterm(4, 0);

    cout << "p2 = ";
    p2.display_poly();

    // Add polynomials using overloaded operator
    p3 = p1 + p2;

    cout << "p1 + p2 = ";
    p3.display_poly();

    return 0;
}