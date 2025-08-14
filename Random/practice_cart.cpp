#include <iostream>
#include <cstring>
using namespace std;

struct Item
{
    string name;
    int quantity;
    float price;
};

struct Node
{
    Item data;
    Node *next;

    Node(Item item) : data(item), next(nullptr) {}
};

class cart
{
private:
    Node *head, *tail;

public:
    cart() : head(nullptr), tail(nullptr) {}

    void additem(string name, int quantity, float price)
    {
        Item newItem = {name, quantity, price}; // created object of structure Item and initialize it with name, quantity & price
        Node *nn = new Node(newItem);

        if (!head)
        {
            head = nn;
            tail = nn;
        }

        else
        {
            tail->next = nn; // tail ka jo next hai voh ab nn(newnode) ko point karega
            tail = nn;
        }

        cout << name << " x " << quantity << " added to the cart.\n";
    }

    void remove()
    {
        if (!head)
        {
            cout << "Cart is Empty.";
            return;
        }

        Node *p1 = head;
        Node *p2 = head;

        while (!p1)
        {
            p2 = p1;
            p1 = p1->next;
            delete p2;
        }

        head = nullptr;
    }

    void display()
    {
        if (!head)
        {
            cout << "Cart is Empty.\n";
            return;
        }

        Node *current = head;

        while (current)
        {
            cout << current->data.name << " x " << current->data.quantity << " @ " << current->data.price << "each.\n";
            current = current->next;
        }
    }
};

int main()
{
    bool a = false;
    cart c;
    string name;
    int quantity;
    float price;

    char ans;
    while (!a)
    {
        cout << "Enter Name of Item: ";
        cin >> name;
        cout << "Enter Quantity of Item: ";
        cin >> quantity;
        cout << "Enter price of Item: ";
        cin >> price;

        c.additem(name, quantity, price);
        cout << " add other item?(y/n): ";
        cin >> ans;

        if (ans == 'n')
        {
            a = true;
            break;
        }
    }

    c.display();

    cout << " Want to Empty Cart?(y/n)";
    cin >> ans;

    if (ans == 'y')
    {
        c.remove();
        c.display();
    }

    else
    {
        cout << "All Funtions Executed successfully!\n";
    }
    return 0;
}