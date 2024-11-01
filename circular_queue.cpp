#include <iostream>
using namespace std;
const int size=5;
class cList
{
	private:
		int arr[size];
		int front;
		int rear;
		int count;
	public:	
		cList()
		{
			front = rear = count = 0;
		}
		
	
		
		void enqueue(int value)
		{
			if(!isFull())
			{
				arr[rear] = value;
				rear = (rear+1) % size;  //here for example after insertion at 4 it would do : (4+1) % 5 = 0 so rear would move to 0
				count++;
			}
			else
			{
				cout<<"queue overflow!"<<endl;
			}
		}
		
		int dequeue()
		{
			if(!isEmpty())  
			{
				int val =  arr[front];
				front = (front + 1) % size;
				count--;
				return val;
			}
			else
			{
				cout<<"queue underflow!"<<endl;
				return -1;
			}
		}
		
		bool isEmpty()
		{
			if(count==0)
			{
				return true;
				
			}
			else
			{
				return false;
			}
		}
		
		bool isFull()
		{
			if(count==size)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		
		void display()
		{
			if(!isEmpty())
			{
				cout<<"displaying queue items: "<<endl;
				int index = front;
				for(int i = 0; i<count; i++)
				{
					cout<<arr[index]<<endl;
					index = (index+1) % size;
				}
			}
			else
			{
				cout<<"no items to display!"<<endl;
				return;
			}
		}
		
};




int main()
{
	cList l1;
	l1.enqueue(34);
	l1.enqueue(45);
	l1.enqueue(56);
	l1.enqueue(87);
	l1.enqueue(12);
	
	cout<<l1.dequeue()<<endl;
	cout<<l1.dequeue()<<endl;
	
	l1.display();
	
	l1.enqueue(123);
	l1.enqueue(65);
	
	l1.enqueue(657);
	
	cout<<l1.isFull()<<endl;
	
	
	l1.display();
}