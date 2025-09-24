// Assignment 8 b)Convert Recursive code to a non-recursive code using Stack
// a) Factorial

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

    int input()
    {
        int n;
        cout << "Enter No. to find Fatorial: ";
        cin >> n;
        return n;
    }

    int fact(int n)
    {
        int pro = 1;
        for (int i = n; i >= 1; i--)
        {
            push(i);
            pro = pop() * pro;
        }
        return pro;
    }
};

int main()
{
    Stack s;
    int n = s.input();
    cout << "Fatorial of " << n << " is " << s.fact(n) << endl;
    return 0;
}