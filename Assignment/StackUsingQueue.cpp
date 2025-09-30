/* Stack Using Queue Having
		push() O(n)
		pop()  O(1)
*/

#include<iostream>
#include<climits>
#include<cstdlib>

using namespace std;

class Queue
{
	private:
		int front, rear, *A;
	public:
		Queue()
		{
			front = -1;
			rear = -1;
			A = new int[100];
		}
		
		int IsEmpty()
		{	// Queue is Empty.
			if(front == -1)
				return 1;
			return 0;
		}
		
		int IsFull()
		{
			if(rear >= 99)
				return 1;
			return 0;
		}
		
		void enQueue(int n)
		{
			if(IsFull())
			{
				cout << "Queue is Full.\n";
				return;
			}
			
			if(front == -1)
				front = 0;

			A[++rear] = n;
			return;
		}
		
		int deQueue()
		{
			// if Empty
			if(IsEmpty())
			{
				cout << "Queue is Empty.\n";
				return INT_MIN;
			}
			
			int data = A[front]; 
			// If this was the last element, reset the queue
			if(front == rear)
			{
				front = rear = -1;
			}
			
			else
			{
				front++;
			}
			return data;
		}
		
		void display()
		{
			if (IsEmpty())
			{
			    cout << "List is Empty.\n";
			    return;
			}
        
			cout << "List is ";
			for(int i = front; i <= rear; i++)
			{
				cout << A[i] << " ";
			}
			cout << endl;
		}
};

class Stack 
{
	private:
		Queue Q1, Q2;
	public:
		int IsEmpty()
		{
			if(Q1.IsEmpty())
				return 1;
			return 0;
		}
		
		int IsFull()
		{
			if(Q1.IsFull())
				return 1;
			return 0;
		}
		
		void push(int k)
		{
			if(Q1.IsFull())
			{
				cout << "Stack is Full.\n";
				return;
			}
			
			while(!Q1.IsEmpty())
			{
				Q2.enQueue(Q1.deQueue());
			}
			
			Q1.enQueue(k);
			
			while(!Q2.IsEmpty())
			{
				Q1.enQueue(Q2.deQueue());
			}
			return;
		}
		
		int pop()
		{
			if(Q1.IsEmpty())
			{
				cout << "Stack is Empty.\n";
				return INT_MIN;
			}
			
			return Q1.deQueue();
		}
		
		void display()
		{
			Q1.display();
			return;
		}		
};

int main()
{
	Stack s;
	for(int i = 0; i < 15; i++)
	{
    		int k = (rand() % 100) + 1;
    		s.push(k);
	}
	
	s.display();
	
	for(int i = 0; i < 15; i++)
	{
		cout << s.pop() << " popped." << endl;
	}
	
	return 0;
}
