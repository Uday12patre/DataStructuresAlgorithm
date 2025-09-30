/* Queue Using Stack Having
	enQueue O(n)
	deQueue O(1)
*/

#include<iostream>
#include<climits>
#include<cstdlib>

using namespace std;

class Stack
{
	private:
    	int *A, top;
	public:
    	Stack()
    	{
        	A = new int[100];
        	top = -1;
    	}
   	 
    	int IsFull()
    	{
        	if(top >= 99)
            	return 1;
        	return 0;
    	}
   	 
    	int IsEmpty()
    	{
        	if(top==-1)
            	return 1;
        	return 0;
    	}
   	 
    	void push(int k)
    	{
        	if(IsFull())
        	{
            	cout << "Stack is Full\n";
            	return;
        	}
       	 
        	A[++top] = k;
        	return;
    	}
   	 
    	int pop()
    	{
        	if(IsEmpty())
        	{
            	cout << "Stack is Empty.\n";
            	return INT_MIN;
        	}
       	 
        	return A[top--];
    	}
   	 
    	int peek()
    	{
        	if(IsEmpty())
        	{
            	return INT_MAX;
        	}
       	 
        	return A[top];
    	}
   	 
    	void display()
    	{
        	cout << "List is (From Bottom to Top) ";
        	for(int i = 0; i <=top; i++)
        	{
            	cout << A[i] <<" ";
        	}
        	cout <<endl;
    	}
};

class Queue
{
	Stack S1, S2;
	public:   	 
    	int Full()
    	{
        	if(S1.IsFull())
        	{
            	return 1;
        	}
        	return 0;
    	}
   	 
    	int Empty()
    	{
        	if(S1.IsEmpty())
        	{
            	return 1;
        	}
        	return 0;
    	}
   	
   	// O(n)
    	void enQueue(int n)
    	{
        	if(Full())
        	{
            	cout << "Queue is Full.\n";
            	return;
        	}
        	
        	while(!S1.IsEmpty())
        	{
        		S2.push(S1.pop());
		}
		S1.push(n);
		while(!S2.IsEmpty())
		{
			S1.push(S2.pop());
		}
        	return;
    	}
   	
   	// O(1)
    	int deQueue()
    	{
        	if(Empty())
        	{
            	cout << "Queue is Empty.\n";
            	return INT_MIN;
        	}
        	int k = S1.pop();
        	return k;
    	}
    	void display()
    	{
        	S1.display();
        	return;
    	}
   	 
};

int main()
{
	Queue q;
	for(int i = 0; i < 15; i++)
	{
    	int k = (rand() % 100) + 1;
    	q.enQueue(k);
	}
    
	q.display();
	for(int i = 0; i < 15; i++)
	{
    	cout << q.deQueue() << " deQueued."<< endl;   	 
	}
}
