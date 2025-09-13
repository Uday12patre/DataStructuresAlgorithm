#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int new_data)
    {
        this->data = new_data;
        this->next = NULL;
    }
};

class Lstack
{
private:
    Node *head;

public:
    Lstack() : head(NULL) {}

    bool IsEmpty()
    {
        return head == NULL;
    }

    void push(int k)
    {
        Node *nn = new Node(k);
        if (!nn)
        {
            cout << "Memory Allocation Failed.\n";
            return;
        }

        nn->next = head;
        head = nn;
        return;
    }

    void pop()
    {
        if (IsEmpty())
            INT_MIN;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int peek()
    {
        if (!IsEmpty())
            return head->data;
        return INT_MIN;
    }
};

int main()
{
    Lstack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    cout << s.peek();
    cout << endl;
    cout << s.IsEmpty();
    return 0;
}
