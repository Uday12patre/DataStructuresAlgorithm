// Assignment 7
// Convert a given infix expression to post fix then evaluate

#include <iostream>
#include <cctype>
#include <string>
#include <climits>
using namespace std;

class stack
{
private:
    int *A, size, top = -1;

public:
    stack(int s = 10)
    {
        A = new int[s];
        size = s;
    }

    void push(int K)
    {
        if (top >= size - 1)
        {
            cout << "Stack Overflow";
            return;
        }
        // not full
        A[++top] = K;
        return;
    }

    int pop()
    {
        // empty
        if (IsEmpty())
        {
            return INT_MIN;
        }
        return A[top--];
    }

    int peek()
    {
        if (IsEmpty())
        {
            cout << "Stack is Empty!\n";
            return INT_MIN;
        }

        return A[top];
    }

    int IsEmpty()
    {
        return top == -1;
    }

    int IsFull()
    {
        return top == size - 1;
    }

    void display()
    {
        if (top < 0)
        {
            cout << "Stack is Empty!";
            return;
        }

        for (int i = 0; i <= top; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";
        return;
    }
};

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixTopostfix(string exp)
{
    stack st(exp.size());
    string r = "";

    for (char c : exp) // for each loop
    {
        if (isdigit(c))
        {
            r = r + c;
        }

        else if (c == '(')
        {
            st.push(c);
        }

        else if (c == ')')
        {
            while (!st.IsEmpty() && st.peek() != '(')
            {
                r = r + (char)st.pop();
                r = r + " ";
            }
            st.push(c);
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            r = r + " ";
            while (!st.IsEmpty() && prec((char)st.peek()) >= prec(c))
            {
                r = r + (char)st.pop();
                r = r + " ";
            }
            st.push(c);
        }
    }

    while (!st.IsEmpty())
    {
        r = r + " ";
        r = r + (char)st.pop();
    }
    return r;
}

int eval(string exp)
{
    int n = exp.size();
    stack st(n);
    int num = 0;
    bool readingNum = false;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(exp[i]))
        {
            num = num * 10 + (exp[i] - '0');
            readingNum = true;
        }

        else if (exp[i] == ' ')
        {
            if (readingNum)
            {
                st.push(num);
                num = 0;
                readingNum = false;
            }
        }

        else
        {
            int b = st.pop();
            int a = st.pop();
            switch (exp[i])
            {
            case '+':
                return (a + b);
                break;
            case '-':
                return (a - b);
                break;
            case '*':
                return (a * b);
                break;
            case '/':
                return (a / b);
                break;
            case '^':
            {
                int r = 1;
                for (int j = 0; j < b; j++)
                {
                    r = r * a;
                    st.push(r);
                }
                break;
            }
            }
        }
    }
    return st.pop();
}
int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixTopostfix(infix);
    cout << "Postfix: " << postfix << endl;

    int result = eval(postfix);
    cout << "result: " << result << endl;
    return 0;
}
