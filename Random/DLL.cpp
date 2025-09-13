#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DLL
{
private:
    Node *head, *tail;

public:
    DLL() : head(NULL), tail(NULL) {}

    void append(int k)
    {
        Node *nn = new Node;
        if (!nn)
        {
            cout << "Memory Allocation Failed.\n";
            return;
        }

        nn->data = k;
        nn->prev = NULL;
        nn->next = NULL;

        if (!head)
        {
            head = tail = nn;
        }

        else
        {
            nn->prev = tail;
            tail->next = nn;
            tail = tail->next;
        }
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

    void displayRev()
    {
        if (!head)
        {
            cout << "List is Empty!\n";
            return;
        }

        Node *p = tail;

        while (p)
        {
            cout << p->data << " ";
            p = p->prev;
        }

        cout << endl;
        return;
    }
};

int main()
{
    DLL L;
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
    L.displayRev();
}
