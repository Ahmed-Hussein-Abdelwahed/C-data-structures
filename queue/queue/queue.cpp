#include <iostream>
#include "queue.h"
#include <string>
using namespace std;
int main()
{
    string userChoice;

    // interface to pass template objects

    while (true)
    {
        cout << "\n ================================================\n"
            << " [1] Create a short queue\n"
            << " [2] Create an int queue\n"
            << " [3] Create a float queue\n"
            << " [4] Create a double queue\n"
            << " [5] Create a char queue\n"
            << " [6] Create a string queue [strings not contain spaces]\n"
            << " [7] Exit\n";
        cin >> userChoice;

        if (userChoice == "1")
        {
            Queue <short> shortQueue;
            cout << "\n A short queue has been created successfully\n";
            shortQueue.queueInterface();
        }
        else if (userChoice == "2")
        {
            Queue <int> intQueue;
            cout << "\n An int queue has been created successfully\n";
            intQueue.queueInterface();
        }
        else if (userChoice == "3")
        {
            Queue <float> floatQueue;
            cout << "\n A float queue has been created successfully\n";
            floatQueue.queueInterface();
        }
        else if (userChoice == "4")
        {
            Queue <double> doubleQueue;
            cout << "\n A double queue has been created successfully\n";
            doubleQueue.queueInterface();
        }
        else if (userChoice == "5")
        {
            Queue <char> charQueue;
            cout << "\n A char queue has been created successfully\n";
            charQueue.queueInterface();
        }
        else if (userChoice == "6")
        {
            Queue <string> stringQueue;
            cout << "\n A string queue has been created successfully\n";
            stringQueue.queueInterface();
        }
        else if (userChoice == "7")
        {
            exit(0);
        }
        else
        {
            cout << "\n Invalid choice ... try again\n";
        }
    }
    return 0;
}

