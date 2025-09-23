#include<cstdlib>
#include<iostream>
#include<climits>
#include<vector>
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
        	int p_i = (i-1)/2;
        	while(i!=0)
        	{
            	if(arr[i] > arr[p_i])
            	{
                	swap(i, p_i);
                	i = p_i;
                	p_i = (i-1)/2;
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
        	if(rear == 0)
            	return 1;
        	return 0;
    	}
   	 
    	int IsFull()
    	{
        	if(rear >= size)
            	return 1;
        	return 0;
    	}
   	 
    	void enQueue(int n)
    	{
        	if(IsFull())
            	return;
       	 
        	arr[++rear] = n;
        	Adjust();
    	}
   	 
    	int peek()
    	{
        	if(IsEmpty())
            	return INT_MIN;
        	return arr[0];
    	}
   	 
    	void Display()
    	{
        	for(int i = 0; i <= rear; i++)
        	{
            	cout << arr[i] <<"\t";
        	}
        	cout << endl;
       	 
        	return;
    	}
};

int main()
{
	PriorityQueue Q;
	for(int i = 0; i < 10; i++)
	{
    	int n = (rand() % 100) + 1;
    	cout << n << "\t";
    	Q.enQueue(n);
    	cout << endl;
    	Q.Display();
    	cout << endl;
	}
	return 0;
}

