#pragma once
#include <iostream>
#include <limits>
#include <string>
using namespace std;

template <class T>

// first type of circular linked list last node connected with head

class CircLinkedList 
{
    struct Node
    {
        T data;
        Node* next;
    };
    Node* head;
    int size;

public:
    CircLinkedList()
    {
        head = NULL;
        size = 0;
    }
    ~CircLinkedList()
    {
        // deallocation the list from the heap
        Node* deleteNode1 = head, * deleteNode2 = NULL;

        do
        {
            deleteNode2 = deleteNode1->next;
            delete deleteNode1;
            deleteNode1 = deleteNode2;
        } while (deleteNode1 != head);
        head = NULL;
        size = 0;
    }

    void pushFront()
    {
        // insert element after head

        Node* firstNode = new Node;

        cout << "Enter an element to push front\n";
        elementValidation(firstNode->data);

        if (head == NULL)
        {
            head = firstNode;
            firstNode->next = head;
        }
        else
        {
            Node* insertPointer = head;

            while (insertPointer->next != head)
            {
                insertPointer = insertPointer->next;
            }
            insertPointer->next = firstNode;
            firstNode->next = head;
            head = firstNode;
        }
        this->size++;
        cout << "Element has been pushed front successfully\n";
    }

    void insertAt()
    {
        // insert at any position but list must contains elements not to be empty

        if (isEmpty())
        {
            cout << "List is empty ... push some elements first\n";
        }
        else
        {
            int index;
            cout << "Eneter an index to insert at\n";

            if (indexValidation(index) == 1)
            {
                pushFront();
            }
            else if (indexValidation(index) == this->size)
            {
                pushBack();
            }
            else
            {
                Node* insertNode = new Node, * insertPointer = head;

                cout << "Eneter an element to insert\n";
                elementValidation(insertNode->data);

                for (int num = 0; num < index - 1; num++)
                {
                    insertPointer = insertPointer->next;
                }

                insertNode->next = insertPointer->next;
                insertPointer = insertNode;
                this->size++;
                cout << "Element has been inserted successfully\n";
            }
        }
    }

    void pushBack()
    {
        // push element in the end

        Node* lastNode = new Node;

        cout << "Enter an element to push back\n";

        elementValidation(lastNode->data);

        if (head == NULL)
        {
            head = lastNode;
        }
        else
        {
            Node* insertPointer = head;

            while (insertPointer->next != head)
            {
                insertPointer = insertPointer->next;
            }

            insertPointer->next = lastNode;
        }

        lastNode->next = head;
        this->size++;
        cout << "Element has been pushed back successfully\n";
    }

    void eraseAt()
    {
        // erase elements from the list 

        if (isEmpty())
        {
            cout << "List is empty\n";
        }
        else
        {
            int index;
            cout << "Eneter an index to erase it\n";

            if (indexValidation(index) == 1) // erase front
            {
                Node* deleteNode1 = head;
                while (deleteNode1->next != head)
                {
                    deleteNode1 = deleteNode1->next;
                }

                deleteNode1->next = head->next;
                delete head;
                head = deleteNode1->next;
            }
            else if (indexValidation(index) == this->size) // erase back
            {
                Node* deleteNode2 = head, * deleteNode3 = NULL;

                for (int num = 0; num < this->size - 2; num++)
                {
                    deleteNode2 = deleteNode2->next;
                }

                deleteNode3 = deleteNode2->next;
                deleteNode2->next = head;
                delete deleteNode3;
            }
            else // erase at any position except 1 and list size
            {
                Node* deleteNode4 = head, * deleteNode5 = NULL;

                for (int num = 0; num < index - 2; num++)
                {
                    deleteNode4 = deleteNode4->next;
                }
                deleteNode5 = deleteNode4->next;
                deleteNode4->next = deleteNode5->next;
                delete deleteNode5;
            }
           
            this->size--;
            cout << "Element has been erased successflly\n";
        }
    }

    void displayList()
    {
        // dispaly list elements

        if (isEmpty())
        {
            cout << "List is empty\n";
        }
        else
        {
            Node* displayNode = head;
            cout << "List contains: ";
            do
            {
                cout << displayNode->data << " ";
                displayNode = displayNode->next;
            } while (displayNode != head);
            cout <<endl;
        }
    }

    T elementValidation(T& element)
    {
        // validat element to insert at the list

        cin >> element;
        
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid element ... try again\n";
            cin >> element;
        }
        return element;
    }

    int indexValidation(int& index)
    {
        // validat index to insert in

        cin >> index;

        while (cin.fail() || index > this->size || index <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid index ... try again\n";
            cin >> index;
        }
        return index;
    }

    bool isEmpty()
    {
        // check list empty

        if (this->size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void interFace()
    {
        // circualar linked list interface

        string userChoice;

        while (true)
        {
            cout << "==================================================\n"
                 << "[1] Push front\n"
                 << "[2] Insert at\n"
                 << "[3] Push back\n"
                 << "[4] Erase at\n"
                 << "[5] List size\n"
                 << "[6] Display list\n"
                 << "[7] Back to main menu\n"
                 << "[8] Exit\n";
            cin >> userChoice;
            if (userChoice == "1")
            {
                pushFront();
            }
            else if (userChoice == "2")
            {
                insertAt();
            }
            else if (userChoice == "3")
            {
                pushBack();
            }
            else if (userChoice == "4")
            {
                eraseAt();
            }
            else if (userChoice == "5")
            {
                cout << "list contains: " << this->size << " element/s\n";
            }
            else if (userChoice == "6")
            {
                displayList();
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
