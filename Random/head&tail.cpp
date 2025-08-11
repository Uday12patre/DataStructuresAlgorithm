#include <iostream>
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
    SLL() : head(nullptr), tail(nullptr) {}

    void append(int key)
    {
        Node *nn = new Node;

        if (!nn)
            return;

        nn->data = key;
        nn->next = nullptr;

        if (!head)
        {
            head = nn;
            tail = nn;
            return;
        }

        tail->next = nn;
        tail = nn;
        return;
    }

    void display()
    {
        if (!head)
        {
            cout << "List is Empty.\n";
            return;
        }

        Node *tail = head;

        while (tail)
        {
            cout << tail->data << "\n";
            tail = tail->next;
        }

        cout << endl;
        return;
    }
};

int main()
{
    SLL L;
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);
    L.append(10);
    L.display();
    return 0;
}