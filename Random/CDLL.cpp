#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class CDLL
{
private:
    Node *head, *tail;

public:
    CDLL() : head(NULL), tail(NULL) {}

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
            tail->next = head;
        }

        else
        {
            nn->prev = tail;
            tail->next = nn;
            tail = tail->next;
            tail->next = head;
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

        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);

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

        do
        {
            cout << p->data << " ";
            p = p->prev;
        } while (p != tail);

        cout << endl;
        return;
    }
};

int main()
{
    CDLL L;
    L.append(10);
    L.append(20);
    L.append(30);
    L.append(40);
    L.append(50);
    L.append(60);

    cout << "CDLL: ";
    L.display();
    cout << "CDLLRev: ";
    L.displayRev();
}
