#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string name;
    int quantity;
    double price;
    string type;
};

struct Node
{
    Item data;
    Node *next;

    Node(Item item) : data(item), next(nullptr) {}
};

class ShoppingCart
{
private:
    Node *head, *tail;

public:
    ShoppingCart() : head(nullptr), tail(nullptr) {}

    void addItem(string name, int quantity, double price, string type)
    {
        Item newItem = {name, quantity, price, type};
        Node *newNode = new Node(newItem);

        if (head == nullptr) // if(head)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        return;

        /* Node* current = head;
        while (current -> next != nullptr) // if(!current->next)
        {
            current = current -> next;
        }
        current -> next = newNode; */

        cout << "Added " << quantity << " x " << name << " of type " << type << " to the cart.\n";
    }

    void displayitem(string itemname)
    {
        int flag = 0;
        Node *current = head;
        while (current)
        {
            if (current->data.name == itemname)
            {

                flag = 1;
                cout << "Type: " << current->data.type << "\t" << current->data.name << " x " << current->data.quantity << " @ " << current->data.price << " each\n";
                break;
            }
            current = current->next;
        }

        if (!flag)
        {
            cout << itemname << " not found.\n";
        }
        return;
    }

    void displaybyType(string Type)
    {
        int flag = 0;

        if (head == nullptr)
        {
            cout << "Your shopping cart is for this type is empty.\n";
            return;
        }
        cout << "\n---Your Shopping Cart ---\n";

        Node *current = head;

        while (current != nullptr)
        {
            if (current->data.type == Type)
            {
                flag = 1;
                cout << "Type: " << current->data.type
                     << " Item: " << current->data.name
                     << ", Quantity: " << current->data.quantity
                     << ", Price: $" << current->data.price
                     << " each\n";
            }
            current = current->next;
        }

        cout << "--------------------\n";
        if (!flag)
        {
            cout << Type << " Not Found.";
        }
        return;
    }

    void updateItem(string itemname, int num)
    {
        int flag = 0;
        Node *current = head;
        while (current)
        {
            if (current->data.name == itemname)
            {
                flag = 1;
                current->data.quantity = num;
                cout << " Quantity Updated! \n";
                cout << current->data.name << " x " << current->data.quantity << " @ " << current->data.price << " each\n";
            }

            current = current->next;
        }

        if (!flag)
        {
            cout << itemname << " not found.\n";
        }
        return;
    }

    void displayCartItems()
    {
        if (head == nullptr)
        {
            cout << "Your shopping cart is empty.\n";
            return;
        }
        cout << "\n---Your Shopping Cart ---\n";
        Node *current = head;
        while (current != nullptr)
        {
            cout << "Type: " << current->data.type
                 << " Item: " << current->data.name
                 << ", Quantity: " << current->data.quantity
                 << ", Price: $" << current->data.price
                 << " each\n";
            current = current->next;
        }
        cout << "--------------------\n";
        return;
    }

    double calculateTotalCost()
    {
        double totalCost = 0.0;
        Node *current = head;
        while (current != nullptr)
        {
            totalCost = totalCost + current->data.quantity * current->data.price;
            current = current->next;
        }
        return totalCost;
    }

    void remove(string key)
    {
        if (!head) // if list is MT.
        {
            cout << "List Is Empty.\n";
            return;
        }

        Node *current = head;
        Node *p2 = nullptr;

        if (current->data.name == key) // if first node itself is a key!
        {
            head = current->next;
            delete current;
            return;
        }

        while (current && current->data.name != key) // General case // also fo searching / Traversing the key
        {
            p2 = current;
            current = current->next;
        }

        if (!current) // if Key Not Found.
        {
            cout << "Key Not Found.\n";
            return;
        }

        p2->next = current->next;
        delete current;
    }

    void EmptyCart()
    {
        if (!head)
        {
            cout << "List is Empty.";
            return;
        }

        Node *current = head;
        Node *p2 = nullptr;

        while (current)
        {
            p2 = current;
            current = current->next;
            delete p2;
        }

        head = nullptr;
    }
};

int main()
{
    ShoppingCart mycart;
    int choice;
    string name;
    int quantity;
    double price;
    double total;
    string itemname, ty;
    int num;

    do
    {
        cout << "\n--- Shopping Cart Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Item details\n";
        cout << "4. Display Cart Items\n";
        cout << "5. Display by Type\n";
        cout << "6. Update item quantity\n";
        cout << "7. Calculate Total Cost\n";
        cout << "8. Empty Cart\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter item type: ";
            cin >> ty;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;

            mycart.addItem(name, quantity, price, ty);
            break;
        case 2:
            cout << "Enter item name to remove: ";
            cin >> name;
            mycart.remove(name);
            break;
        case 3:
            cout << "Enter name of item: ";
            cin >> itemname;

            mycart.displayitem(itemname);
            break;
        case 4:
            mycart.displayCartItems();
            break;
        case 5:
            cout << "Enter type of item: ";
            cin >> ty;
            mycart.displaybyType(ty);
            break;
        case 6:
            cout << "Enter name of item: ";
            cin >> itemname;
            cout << "Enter updated quantity of item: ";
            cin >> num;
            mycart.updateItem(itemname, num);
            break;
        case 7:
            total = mycart.calculateTotalCost();
            cout << "Total cost of all items: $" << total << "\n";
            break;
        case 8:
            mycart.EmptyCart();
            break;
        case 9:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 9);
    return 0;
}
