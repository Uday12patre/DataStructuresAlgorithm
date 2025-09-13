#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SLL
{
private:
    Node *head, *tail;

public:
    SLL() : head(NULL), tail(NULL) {}

    void append(int k)
    {
        Node *nn = new Node;
        if (!nn)
        {
            cout << "Memory Allocation Failed.\n";
            return;
        }

        if (!head)
        {
            head = tail = nn;
        }

        nn->data = k;
        nn->next = NULL;

        tail->next = nn;
        tail = nn;
        return;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is Empty!\n";
            return;
        }

        Node *p = head;

        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
        return;
    }
};

int main()
{
    SLL L;
    L.append(10);
    L.append(20);
    L.append(30);
    L.append(40);
    L.append(50);
    L.append(60);
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);

    L.display();
}