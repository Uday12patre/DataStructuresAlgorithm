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
            cout << p->data << "\n";
            p = p->next;
        }
        cout << endl;
        return;
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
    L.append(10);
    L.append(10);
    L.append(10);
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