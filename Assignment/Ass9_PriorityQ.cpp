#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
    int *arr, size, n, rear;

    void swap(int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void Adjust()
    {
        int i = rear;
        int p_i = (i - 1) / 2;
        while (i != 0)
        {
            if (arr[i] > arr[p_i])
            {
                swap(i, p_i);
                i = p_i;
                p_i = (i - 1) / 2;
            }
            else
                return;
        }
    }

public:
    PriorityQueue()
    {
        rear = -1;
        size = 100;
        arr = new int[size];
    }

    int IsEmpty()
    {
        if (rear == -1)
            return 1;
        return 0;
    }

    int IsFull()
    {
        if (rear >= size)
            return 1;
        return 0;
    }

    void enQueue(int n)
    {
        if (IsFull())
            return;

        arr[++rear] = n;
        Adjust();
    }

    int peek()
    {
        if (IsEmpty())
            return INT_MIN;
        return arr[0];
    }

    void Display()
    {
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;

        return;
    }

    int deQueue()
    {
        // empty
        if (IsEmpty())
            return INT_MIN;

        // only one element
        if (rear == 0)
        {
            return arr[rear--];
        }

        int k = arr[0];
        arr[0] = arr[rear--];

        for (int i = 0; i <= rear;)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int max;

            // left and right don't exist
            if (left > rear)
                return k;

            // left exit and right don't
            if (left <= rear && right > rear)
            {
                max = left;
                if (arr[left] > arr[i])
                {
                    swap(i, left);
                    i = max;
                }
                else
                {
                    i = max;
                    return k;
                }
            }

            // left and right exist
            if (left <= rear && right <= rear)
            {
                if (arr[left] > arr[right])
                    max = left;
                else
                    max = right;

                if (arr[max] > arr[i])
                {
                    swap(max, i);
                    i = max;
                }

                else
                {
                    i = max;
                    return k;
                }
            }
        }

        return k;
    }
};

int main()
{
    PriorityQueue Q;
    for (int i = 0; i < 10; i++)
    {
        int n = (rand() % 100) + 1;
        cout << n << " enQueued\t";
        Q.enQueue(n);
        cout << endl;
        Q.Display();
        cout << endl;
    }

    cout << "After deQueue: \n";

    while (!Q.IsEmpty())
    {
        Q.deQueue();
        cout << endl;
        Q.Display();
    }

    return 0;
}