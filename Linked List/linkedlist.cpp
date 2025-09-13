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

    void remove(int key)
    {
        if (!head) // if list is MT.
        {
            cout << "List Is Empty.\n";
            return;
        }

        Node *p1 = head;
        Node *p2 = nullptr;

        if (p1->data == key) // if first node itself is a key!
        {
            head = p1->next;
            delete p1;
            return;
        }

        while (p1 && p1->data != key) // General case // also fo searching / Traversing the key
        {
            p2 = p1;
            p1 = p1->next;
        }

        if (!p1) // if Key Not Found.
        {
            cout << "Key Not Found.\n";
            return;
        }

        p2->next = p1->next;
        delete p2;  
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
    L.display();

    L.remove(100);
    L.remove(10);
    L.remove(120);

    L.display();
    return 0;
}