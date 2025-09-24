#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int top;
    int arr[100];

public:
    Stack() : top(-1) {}

    void push(int k)
    {
        if (top >= 99)
        {
            cout << "Stack is Full.\n";
            return;
        }

        arr[++top] = k;
        return;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack is Empty!\n";
            return INT_MIN;
        }

        return arr[top--];
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty!\n";
            return INT_MIN;
        }
        return arr[top];
    }

    bool IsEmpty()
    {
        return (top < 0);
    }

    bool IsFull()
    {
        return (top >= 99);
    }

    void display()
    {
        if (top < 0)
        {
            cout << "Stack is Empty!\n";
            return;
        }

        cout << "Stack (Top to Bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }

    void insertAtBottom(int item)
    {
        if (IsEmpty())
        {
            push(item);
        }
        else
        {
            int temp = pop();
            insertAtBottom(item);
            push(temp);
        }
    }

    void reverse()
    {
        if (!IsEmpty())
        {
            int temp = pop();
            reverse();
            insertAtBottom(temp);
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);

    s.display();

    cout << "After Reversing: ";
    s.reverse();
    s.display();
    return 0;
}