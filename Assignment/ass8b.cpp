#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};
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

};

class SLL{
	private:
		node *head, *tail;
	public:
		SLL() : head(nullptr), tail(nullptr) {}
		
		void append(int k){
		
		// newnode initialisation
		node *nn = new node;
		if(!nn)
		{
			cout << "Memory Allocation Failed.\n";
			return;
		}
		
		nn->data = k;
		nn->next = nullptr;
		if(!head) // only runs for the first append until head is pointing so something
		{
			head = tail = nn;
			return;
		}
		
		tail->next = nn; // *next pointer will point to next nn
		tail = nn; // *tail pointer will point to next nn
		return;
		}
		
		int RemoveFromhead()
		{
			// if list is Empty
			if(!head){
				cout << "List is Empty!\n";
				return INT_MIN;
			}
			
			// if list has only one element;
			if(head == tail){
				int k = head->data;
				head = tail = nullptr;
				return k;
			// removing elements from head 
			
			node *p = head;
			
			head->next = p->next->next;
			head->data = p->next->data;
			
			delete p; 
			}
			
		}
		
		void display(Node *)
		    {
			if (!head)
			{
			    cout << "List is Empty.\n";
			    return;
			}

			Node *tail = head;

			while (tail)
			{
			    cout << tail->data << "\n";
			    tail = tail->next;
			}

			cout << endl;
			return;
		    }
		
		
};

class Cal
{
	private:
		friend class Stack;
		friend class SLL;
	public:
		void ReverseUsingStack(){
			
		/*The conversion follows these key steps:
Traverse and Store: The first loop traverses the entire original linked list from head to tail. For every node it visits, it pushes the address of that node onto the std::stack. The LIFO property of the stack ensures that the nodes are stored in reverse order, with the last node at the top.
Rebuild and Relink: After the first traversal, the second loop rebuilds the list by popping nodes off the stack one by one. The first node popped becomes the new head. Each subsequent node popped is linked to the next pointer of the previously popped node, effectively reversing the direction of the list's links.
Terminate the List: Finally, the next pointer of the last node in the reversed list must be set to nullptr to properly terminate the list and avoid creating a cycle. */
		
		}
};

int main()
	{
		// append() with random integer using [rand() % 100 + 1]]
		// and display
	}



