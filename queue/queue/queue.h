// queue using linked list
// queue elements are [FIFO]

#pragma once
#include <iostream>
#include <limits>
#include <string>
using namespace std;

template <class T>
class Queue
{
private:
	
	struct Node
	{
		T data;
		Node* next;
	};
	Node* first, * last;
	int size;

public:
	Queue()
	{
		// intializing variables

		first = last = NULL;
		size = 0;
	}

	~Queue()
	{
		// deallocation the heap

		Node* eraseNode1 = first, * eraseNode2 = NULL;

		while (eraseNode1 != NULL)
		{
			eraseNode2 = eraseNode1->next;
			delete eraseNode1;
			eraseNode1 = eraseNode2;
		}
		first = last = NULL;
		size = 0;
	}

	void firstData()
	{
		// get first element data 

		if (isEmpty())
		{
			cout << "\n Queue is empty\n";
		}
		else
		{
			cout << "\n First element in the queue = " << first->data << endl;
		}
	}

	void lastData()
	{
		// get last element data  

		if (isEmpty())
		{
			cout << "\n Queue is empty\n";
		}
		else
		{
			cout << "\n Last element in the queue = " << last->data << endl;
		}
	}

	void enQueue()
	{
		// add new element to the queue 

		Node* insertNode = new Node;

		if (insertNode == NULL) // there is no space in the heap
		{
			cout << "\n Queue is full\n";
		}
		else
		{
			cout << " Enter an element to enqueue\n";
			insertNode->data = elementValidation();

			if (first == NULL)
			{
				insertNode->next = last;
				first = last = insertNode;
			}
			else
			{
				last->next = insertNode;
				last = insertNode;
				last->next = NULL;
			}
			this->size++;
			cout << "\n Element has been queued successfully\n";
		}
	}

	void deQueue()
	{
		// delete element from the queue

		if (isEmpty())
		{
			cout << "\n Queue is empty\n";
		}
		else
		{
			Node* eraseNode = first;

			first = first->next;
			delete eraseNode;

			this->size--;
			cout << "\n Element has been dequeued successfully\n";
		}
	}

	bool isEmpty()
	{
		// check weather queue is empty or not

		if (this->size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void queueDisplay()
	{
		// display queue elements

		if (isEmpty())
		{
			cout << "\n Queue is empty\n";
		}
		else
		{
			Node* showNodeData = first;

			cout << "\n Queue contains: ";
			while (showNodeData != NULL)
			{
				cout << showNodeData->data << " ";
				showNodeData = showNodeData->next;
			}
			cout << endl;
		}
	}

	T elementValidation()
	{
		// validate element before queue that 

		T element;
		cin >> element;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n Invalid element ... try agian\n";
			cin >> element;
		}
		return element;
	}

	void queueInterface()
	{
		// interface for queue class

		string userChoice;

		while (true)
		{
			cout << "\n ========== Welcome to queue program ==========\n"
				<< " [1] Queue first\n"
				<< " [2] Queue last\n"
				<< " [3] EnQueue\n"
				<< " [4] Dequeue\n"
				<< " [5] Is empty\n"
				<< " [6] Queue size\n"
				<< " [7] Display\n"
				<< " [8] Back main menu\n"
				<< " [9] Exit\n";
			cin >> userChoice;

			if (userChoice == "1")
			{
				firstData();
			}
			else if (userChoice == "2")
			{
				lastData();
			}
			else if (userChoice == "3")
			{
				enQueue();
			}
			else if(userChoice == "4")
			{
				deQueue();
			}
			else if (userChoice == "5")
			{
				(isEmpty()) ? cout << "\n True\n" : cout << "\n False\n";
			}
			else if (userChoice == "6")
			{
				cout << "\n Queue contains " << this->size << " element(s)\n";
			}
			else if (userChoice == "7")
			{
				queueDisplay();
			}
			else if (userChoice == "8")
			{
				break;
			}
			else if (userChoice == "9")
			{
				exit(0);
			}
			else
			{
				cout << "\n Invalid choice ... try agian\n";
			}
		}
	}
};
