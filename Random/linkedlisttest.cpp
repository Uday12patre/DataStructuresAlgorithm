#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node a, b, c, d;
    Node *head = nullptr;

    a.data = 10;
    b.data = 20;
    c.data = 30;
    d.data = 40;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = nullptr;

    cout << "Data in Node 'a' = " << a.data << " & " << "address of 'a' is " << head << endl;
    cout << "Data in Node 'b' = " << b.data << " & " << "address of 'b' is " << a.next << endl;
    cout << "Data in Node 'c' = " << c.data << " & " << "address of 'c' is " << b.next << endl;
    cout << "Data in Node 'd' = " << d.data << " & " << "address of 'd' is " << d.next << endl;

    (*head).data = 10;
    return 0;
}