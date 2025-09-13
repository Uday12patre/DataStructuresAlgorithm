#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CSLL
{
private:
    Node *head, *tail;

public:
    CSLL() : head(NULL), tail(NULL) {}

    void append(int k)
    {
        Node *nn = new Node;
        if (!nn)
        {
            cout << "Memory Allocation Failed.\n";
            return;
        }

        nn->data = k;
        nn->next = NULL;

        if (!head)
        {
            head = tail = nn;
            tail->next = head;
        }

        else
        {
            tail->next = nn;
            tail = nn;
            tail->next = head;
        }
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

        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);

        cout << endl;
        return;
    }
};

int main()
{
    CSLL L;
    L.append(10);
    L.append(20);
    L.append(30);
    L.append(40);
    L.append(50);
    L.append(60);
    cout << "CSLL: ";
    L.display();
}