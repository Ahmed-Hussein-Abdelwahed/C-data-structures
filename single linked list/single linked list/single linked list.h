#pragma once
#include <iostream>
#include <limits>
#include <string>
using namespace std;

template <class T>

class SLinkedList ///single linked list
{
    struct Node
    {
        T data;
        Node* next;
    };
    Node* Head, * Last;
    int Size;

public:
    SLinkedList()
    {
        Head = Last = NULL;
        Size = 0;
    }
    ~SLinkedList()
    {
     
        Node* deleteNode1 = Head, * deleteNode2 = NULL;

        while (deleteNode1 != NULL)
        {
            deleteNode2 = deleteNode1->next;
            delete deleteNode1;
            deleteNode1 = deleteNode2;
        }
        Head = Last = NULL;
        Size = 0;
    }

    void pushFront()
    {
        /// insert in the list beginning

        cout << "\n Enter an element to push front\n";

        Node* firstNode;
        firstNode = new Node;

        if (firstNode == NULL) // make sure that there is space in the heap
        {
            cout << "\n Memory if full\n";
        }
        else
        {
            firstNode->data = elementValidation();
            firstNode->next = NULL;

            if (Head == NULL)
            {
                Head = Last = firstNode;
            }
            else
            {
                firstNode->next = Head;
                Head = firstNode;
            }
            this->Size++;
            cout << "\n Element was pushed front successfully\n"
                << "============================================\n";
        }

    }

    void insertAtIndex()
    {
        /// insert it specific index

        if (isEmpty())
        {
            cout << "\n List is empty push some elements first\n";
        }
        else
        {
            Node* indexedNode, * insertPointer = Head;
            indexedNode = new Node;
            int index;

            if (indexedNode == NULL)
            {
                cout << "\n Memory is full\n";
            }
            else
            {
                cout << "\n Enter an element to push front\n";
                indexedNode->data = elementValidation();

                cout << "\n Enter an index\n";
                index = indexValidation();

                for (int num = 0; num < index - 1; num++)
                {
                    insertPointer = insertPointer->next;
                }

                indexedNode->next = insertPointer->next;
                insertPointer->next = indexedNode;

                this->Size++;
                cout << "\n Element was inserted successfully\n"
                    << "========================================\n";
            }
        }
    }

    void pushBack()
    {
        /// insert at the list end

        Node* lastNode = new Node;

        if (lastNode == NULL)
        {
            cout << "\n Memory is full\n";
        }
        else
        {
            cout << "\n Enter an element to push back\n";

            lastNode->data = elementValidation();
            lastNode->next = NULL;

            if (Head == NULL)
            {
                Head = Last = lastNode;
            }
            else
            {
                Last->next = lastNode;
                Last = lastNode;
            }
            this->Size++;
            cout << "\n Element was pushed back successfully\n"
                << "===========================================\n";
        }
    }

    void eraseAt()
    {
        ///  erase at any were in the list
       
        if (isEmpty())
        {
            cout << "\n List is empty\n";
        }
        else
        {
            Node* delete1 = Head;
            int index;

            cout << "\n Enter an index\n";
            index = indexValidation();

            if (index == 1)
            {
                Head = Head->next;
                delete delete1;
            }
            else
            {
                Node* delete2 = NULL;
                for (int num = 0; num < index - 1; num++)
                {
                    delete2 = delete1;
                    delete1 = delete1->next;
                }
                delete2->next = delete1->next;
                delete delete1;
            }

            this->Size--;
            cout << "\n Element was erased successfully\n"
                << "======================================\n";
        }
    }

    void displayList()
    {
        /// displaying list elements
        if (isEmpty())
        {
            cout << "\n List is empty\n";
        }
        else
        {
            Node* display = Head;
            cout << "\n List contains: ";
            while (display != NULL)
            {
                cout << display->data << " ";
                display = display->next;
            }
            cout << "\n=================================\n";
        }
    }

    bool isEmpty()
    {
        /// check if the list is empty or not
        if (this->Size == 0)
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
        /// validation index to insert at
        int index;

        cin >> index;
        while (cin.fail() || index <= 0 || index > this->Size)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (index > this->Size)
            {
                cout << "\n Index is out of range\n";
            }
            else if (index <= 0)
            {
                cout << "\n Index must be greater than 0 only\n";
            }
            else
            {
                cout << "\n Invalid input ... try again\n";
            }
            cin >> index;
        }
        return index;
    }

    T elementValidation()
    {
        /// validation element to insert
        T element;

        cin >> element;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n Invalid input ... try again\n";
            cin >> element;
        }

        return element;
    }

    void interFace()
    {
        /// class user interface
        string choice;

        while (true)
        {
            cout << "\n [1] Push front\n"
                << " [2] Insert at\n"
                << " [3] Push back\n"
                << " [4] Erase at\n"
                << " [5] List size\n"
                << " [6] Display list\n"
                << " [7] Back to main menu\n"
                << " [8] Exit\n";
            cin >> choice;

            if (choice == "1")
            {
                pushFront();
            }
            else if (choice == "2")
            {
                insertAtIndex();
            }
            else if (choice == "3")
            {
                pushBack();
            }
            else if (choice == "4")
            {
                eraseAt();
            }
            else if (choice == "5")
            {
                cout << "\n List size = " << this->Size << endl;
            }
            else if (choice == "6")
            {
                displayList();
            }
            else if (choice == "7")
            {
                break;
            }
            else if (choice == "8")
            {
                exit(0);
            }
            else
            {
                cout << "\n Invalid choice ... try again\n";
            }
        }
    }
};
