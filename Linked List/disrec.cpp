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
    Node *head;

public:
    SLL() : head(nullptr) {} // Constructor initialization

    void display() // Wraping Function
    {
        disrec(head);
    }

    void disrec(Node *P)
    {
        if (!P)
            return;
        Node *p = P;

        cout << p->data << "\t";
        disrec(p->next);
    }

    void displayRev() // Wraping Function
    {
        disrecRev(head);
    }

    void disrecRev(Node *P)
    {
        if (!P)
            return;
        Node *p = P;

        disrecRev(p->next);
        cout << p->data << "\t";
    }

    void append(int key)
    {
        Node *nn = new Node;

        if (!nn) // Checks if Dynamic memory is allocatd or not by the OS // !nn is a condition that checks if the pointer nn is a null pointer. In C++, if the new operator fails to allocate the requested memory (for example, if the system is out of memory), it returns a null pointer (nullptr).
            return;

        nn->data = key;
        nn->next = NULL;

        Node *p = head; // head pointer can't move so, pointer p is declared;

        if (!head) // checks if head is NULL or Not;
        {
            head = nn; // That means linked list is Empty;
            return;
        }

        while (p->next) // jab tak next NULL nahi hota tab tak ye loop chalega
        {
            p = p->next;
        }
        p->next = nn;
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
    L.append(70);
    L.append(80);
    L.append(90);
    L.append(100);
    L.append(110);
    L.append(120);
    cout << "Linked List:\n";
    L.display();
    cout << "\nReverse Linked List:\n";
    L.displayRev();
    return 0;
}