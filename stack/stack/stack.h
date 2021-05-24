// stack using linked list
  // stack elemets are last-in first-out [LIFO]  

#pragma once
#include <iostream>
#include <limits>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* top;
	int size;

public:
	Stack()
	{
		// initialing variables

		top = NULL;
		size = 0;
	}

	~Stack()
	{
		// deallocation the heap

		Node* deleteNode1 = top, * deleteNode2 = NULL;

		while (deleteNode1 != NULL)
		{
			deleteNode2 = deleteNode1->next;
			delete deleteNode1;
			deleteNode1 = deleteNode2;
		}
		top = NULL;
		size = 0;
	}

	void push()
	{
		// pushing new elements inside the stack

		Node* insertNode = new Node;

		if (insertNode == NULL) // make sure that there is a space in the heap 
		{
			cout << "Stack is full\n";
		}
		else
		{
			cout << "\nEnter an element to push\n";
			insertNode->data = elementValidation();

			if (top == NULL)
			{
				insertNode->next = NULL;
			}
			else
			{
				insertNode->next = top;
			}
			top = insertNode;

			this->size++;
			cout << "\nElement has been pushed successfully\n";
		}
	}

	void pop()
	{
		// delete the list in node

		if (isEmpty())
		{
			cout << "\nStack is empty\n";
		}
		else
		{
			Node* eraseNode = top;

			top = top->next;
			delete eraseNode;

			this->size--;
			cout << "\nElement has been poped successfully\n";
		}
	}

	void peak()
	{
		// get node data at a specific position 

		if (isEmpty())
		{
			cout << "\nStack is empty\n";
		}
		else
		{
			Node* showNodeData = top;

			cout << "\nEnter a position to get its data\n";
			int index = indexValidation();

			for (int num = 0; num < index - 1; num++)
			{
				showNodeData = showNodeData->next;
			}

			cout << "Position number " << index << " has data = " << showNodeData->data << endl;
		}
	}

	void stackTop()
	{
		// get first node data

		if (isEmpty())
		{
			cout << "\nStack is empty\n";
		}
		else
		{
			cout << "\nTop's data = " << top->data << endl;
		}
	}

	void stackDisplay()
	{
		// display stack elements

		if (isEmpty())
		{
			cout << "\nStack is empty\n";
		}
		else
		{
			Node* nodeDisplay = top;

			cout << "\nStack contains: ";
			while (nodeDisplay != NULL)
			{
				cout << nodeDisplay->data << " ";
				nodeDisplay = nodeDisplay->next;
			}
			cout << endl;
		}
	}

	bool isEmpty()
	{
	
		if (this->size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int indexValidation()
	{
		// validate index

		int index;
		cin >> index;

		while (cin.fail() || index <= 0 || index > this->size)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if (index > this->size)
			{
				cout << "\nPosition is out of range ... try again\n";
			}
			else if (index <= 0)
			{
				cout << "\nPosition must be greater than 0 only ... try again\n";
			}
			else
			{
				cout << "\nInvalid position ... try again\n";
			}
			cin >> index;
		}
		return index;
	}

	T elementValidation()
	{
		// validate pushed element
		T element;

		cin >> element;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid element ... try again\n";
			cin >> element;
		}

		return element;
	}

	void stackInterface()
	{
		string userChoice;

		while (true)
		{
			cout << "\n========== welcome to stack program ==========\n"
				<< "[1] Stack top\n"
				<< "[2] Push\n"
				<< "[3] Pop\n"
				<< "[4] Peak\n"
				<< "[5] Display\n"
				<< "[6] Stack size\n"
				<< "[7] Back to main menu\n"
				<< "[8] Exit\n";
			cin >> userChoice;

			if (userChoice == "1")
			{
				stackTop();
			}
			else if (userChoice == "2")
			{
				push();
			}
			else if (userChoice == "3")
			{
				pop();
			}
			else if (userChoice == "4")
			{
				peak();
			}
			else if (userChoice == "5")
			{
				stackDisplay();
			}
			else if (userChoice == "6")
			{
				cout << "Stack contains: " << this->size << " element(s)\n";
			}
			else if (userChoice == "7")
			{
				break;
			}
			else if (userChoice == "8")
			{
				exit(0);
			}
			else  
			{
				cout << "Invalid choice ... try again\n";
			}
		}
	}
};
