/* Queue Using Stack Having
	enQueue O(1)
	deQueue O(n)
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
        	cout << "List is (From Top to Bottom): ";
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
   	
   	// O(1)
    	void enQueue(int n)
    	{
        	if(Full())
        	{
            	cout << "Queue is Full.\n";
            	return;
        	}
        	S1.push(n);
        	return;
    	}
   	
   	// O(n)
    	int deQueue()
    	{
        	if(Empty())
        	{
            	cout << "Queue is Empty.\n";
            	return INT_MIN;
        	}
        	while(!S1.IsEmpty())
        	{
            	S2.push(S1.pop());
        	}    
       	 
        	int K = S2.pop();
       	 
        	while(!S2.IsEmpty())
        	{
            	S1.push(S2.pop());
        	}
       	 
        	return K;
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
