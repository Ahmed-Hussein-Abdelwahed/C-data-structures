#include <iostream>
#include <string>
#include "single linked list.h"
using namespace std;
int main()
{
    string choice;

    while (true)
    {
        cout << "=======================================\n"
            << "[1] Create shorts list\n"
            << "[2] Create integers list\n"
            << "[3] Create floats list\n"
            << "[4] Create doubles list\n"
            << "[5] Create characters list\n"
            << "[6] Create strings list\n"
            << "[7] Exit\n";
        cin >> choice;
        if (choice == "1")
        {
            cout << "Shorts list was created successfully\n"
                << "=========================================\n";
            SLinkedList <short> shortList;
            shortList.interFace();
        }
        else if (choice == "2")
        {
            cout << "Integers list was created successfully\n"
                << "===========================================\n";
            SLinkedList <int> intList;
            intList.interFace();
        }
        else if (choice == "3")
        {
            cout << "Floats list was created successfully\n"
                << "=========================================\n";
            SLinkedList <float> floatList;
            floatList.interFace();
        }
        else if (choice == "4")
        {
            cout << "Doubles list was created successfully\n"
                << "==========================================\n";
            SLinkedList <double> doubleList;
            doubleList.interFace();
        }
        else if (choice == "5")
        {
            cout << "Characters list was created successfully\n"
                << "=============================================\n";
            SLinkedList <char> charList;
            charList.interFace();
        }
        else if (choice == "6")
        {
            cout << "Strings list was created successfully\n"
                << "=============================================\n";
            SLinkedList <string> stringList;
            stringList.interFace();
        }
        else if (choice == "7")
        {
            exit(0);
        }
        else
        {
            cout << "Invalid choice ... try again\n";
        }
    }
    return 0;
}
