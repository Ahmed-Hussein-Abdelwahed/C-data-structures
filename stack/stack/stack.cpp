#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
	string userChoice;

	while (true)
	{
		cout <<"=====================================================\n"
			<< "[1] Create a short stack\n"
			<< "[2] Create an int stack\n"
			<< "[3] Create a float stack\n"
			<< "[4] Create a double stack\n"
			<< "[5] Create a char stack\n"
			<< "[6] Create a string stack\n"
			<< "[7] Exit\n";
		cin >> userChoice;

		if (userChoice == "1")
		{
			Stack <short> shortStack;
			cout << "\nA short stack has been created successfully\n";
			shortStack.stackInterface();
		}
		else if (userChoice == "2")
		{
			Stack <int> intStack;
			cout << "\nAn int stack has been created successfully\n";
			intStack.stackInterface();
		}
		else if (userChoice == "3")
		{
			Stack <float> floatStack;
			cout << "\nA float stack has been created successfully\n";
		    floatStack.stackInterface();
		}
		else if (userChoice == "4")
		{
			Stack <double> doubleStack;
			cout << "\nA double stack has been created successfully\n";
			doubleStack.stackInterface();
		}
		else if (userChoice == "5")
		{
			Stack <char> charStack;
			cout << "\nA char stack has been created successfully\n";
			charStack.stackInterface();
		}
		else if (userChoice == "6")
		{
			Stack <string> stringStack;
			cout << "\nA string stack has been created successfully\n";
			stringStack.stackInterface();
		}
		else if (userChoice == "7")
		{
			exit(0);
		}
		else
		{
			cout << "\nInvalid choice ... try again\n";
		}
	}
    return 0;
}