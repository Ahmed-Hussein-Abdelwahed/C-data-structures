#include <iostream>
#include <string>
#include "circularLinkedList.h"
using namespace std;

int main()
{
    string userChoice;
    while (true)
    {
        cout << "[1] Create short list\n"
            << "[2] Create int list\n"
            << "[3] Create float list\n"
            << "[4] Create double list\n"
            << "[5] Create char list\n"
            << "[6] Create string list\n"
            << "[7] Exit\n";
        cin >> userChoice;

        if (userChoice == "1")
        {
            CircLinkedList <short> shortList;
            cout << "Short list has been created successfully\n";
            shortList.interFace();
        }
        else if (userChoice == "2")
        {
            CircLinkedList <int> intList;
            cout << "Int list has been created successfully\n";
            intList.interFace();
        }
        else if (userChoice == "3")
        {
            CircLinkedList <float> floatList;
            cout << "Float list has been created successfully\n";
            floatList.interFace();
        }
        else if (userChoice == "4")
        {
            CircLinkedList <double> doubleList;
            cout << "Double list has been created successfully\n";
            doubleList.interFace();
        }
        else if (userChoice == "5")
        {
            CircLinkedList <char> charList;
            cout << "Char list has been created successfully\n";
            charList.interFace();
        }
        else if (userChoice == "6")
        {
            CircLinkedList <string> stringList;
            cout << "String list has been created successfully\n";
            stringList.interFace();
        }
        else if (userChoice == "7")
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
