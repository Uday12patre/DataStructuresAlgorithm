#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string name;
    int quantity;
    double price;
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
    Node *head;

public:
    ShoppingCart() : head(nullptr) {}

    void addItem(string name, int quantity, double price)
    {
        Item newItem = {name, quantity, price};
        Node *newNode = new Node(newItem);

        if (head == nullptr)
        {
            head = newNode;
        }

        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Added " << quantity << " x " << name << " to the cart.\n";
    }

    /*  void removeItem(const std::string& name) {
        if (head == nullptr) {
            std::cout << "Cart is empty. Nothing to remove." << std::endl;
            return;
        }

        if (head->data.name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Removed " << name << " from the cart." << std::endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data.name != name) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            std::cout << "Removed " << name << " from the cart." << std::endl;
        } else {
            std::cout << "Item '" << name << "' not found in the cart." << std::endl;
        }
    } */

    void displayitem(string itemname)
    {
        Node *current = head;
        while (current)
        {
            if (current->data.name == itemname)
            {
                cout << current->data.name << " x " << current->data.quantity << " @ " << current->data.price << " each\n";
                break;
            }
            current = current->next;
        }

        if (!current)
        {
            cout << itemname << " not found.\n";
        }
        return;
    }

    void updateItem(string itemname, int num)
    {
        Node *current = head;

        if (!current)
        {
            cout << itemname << " not found.\n";
            return;
        }

        while (current)
        {
            if (current->data.name == itemname)
            {
                current->data.quantity = num;
                cout << "Quantity Updated! \n";
                cout << current->data.name << " x " << current->data.quantity << " @ " << current->data.price << " each\n";
            }

            current = current->next;
        }
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
            cout << "Item: " << current->data.name
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
};

int main()
{
    ShoppingCart mycart;
    int choice;
    string name;
    int quantity;
    double price;
    double total;
    string itemname;
    int num;

    do
    {
        cout << "\n--- Shopping Cart Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Item details\n";
        cout << "4. Display Cart Items\n";
        cout << "5. Update item quantity\n";
        cout << "6. Calculate Total Cost\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter item name: ";
            cin >> name;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;

            mycart.addItem(name, quantity, price);
            break;
        case 2:
            cout << "Funtion yet to write! Try next function!\n";
            /* std::cout << "Enter item name to remove: ";
                std::getline(std::cin, name);
                myCart.removeItem(name); */
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
            cout << "Enter name of item: ";
            cin >> itemname;
            cout << "Enter updated quantity of item: ";
            cin >> num;
            mycart.updateItem(itemname, num);
            break;
        case 6:
            total = mycart.calculateTotalCost();
            cout << "Total cost of all items: $" << total << "\n";
            break;
        case 7:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 7);
    return 0;
}