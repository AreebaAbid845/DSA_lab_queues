#include <iostream>
using namespace std;

class Node
{
	public:
	Node *next;
	int data;
};

class cQueue
{
	public:
		Node *front;
		Node *rear;

	cQueue()
	{
		front=rear=NULL;
		
	}
	
	void display()
	{
		Node *temp = front;
		if(front==NULL)
		{
			cout<<"queue is empty nothing to display!"<<endl;
			return;
		}
		else
		{
			cout<<"displaying data!"<<endl;
			
			do
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
			while(temp!=front);
		}
	}
	
	void enqueue(int data)
	{
		Node *temp = new Node;
		temp->data=data;
	
		if(isEmpty()) //means empty queue
		{
			front = rear = temp;
			temp->next=front;
		}
		else
		{
			rear->next=temp;
			rear = temp;
			rear->next=front;
			
			
		}
		//cout<<"enqueued!"<<endl;
		
	}
	
	int dequeue()
	{
		if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }

        int data = front->data;
        Node *temp = front;

        if (front == rear) // Only one element in the queue
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front; // Maintain circular link
        }

        delete temp;
        return data;
    }
		
	
	
	bool isEmpty()
    {
        return (front == NULL && rear == NULL);
    }
	
	
	
};

int main()
{
	cQueue c1;
	c1.enqueue(45);
	c1.enqueue(65);
	c1.enqueue(87);
	c1.enqueue(90);
	c1.enqueue(100);
	
	//cout<<c1.isEmpty()<<endl;
	c1.display();
	
	c1.dequeue();
	c1.dequeue();
	
	c1.display();
	
	c1.enqueue(546);
	
	c1.display();
	
}