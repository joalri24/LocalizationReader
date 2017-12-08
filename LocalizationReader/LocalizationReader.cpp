// LocalizationReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Reader.h"

// Function declarations
void printHeader();
void printHelp();


int main()
{
	printHeader();
	Reader reader;
	cout << "Type a command or a string key:\n";
	string input;
	while (true)
	{
		cin >> input;

		if (input == "exit")
			break;

		if (input == "help")
		{
			printHelp();
			continue;
		}
			
	}

    return 0;
}

void printHeader()
{
	cout << "---- Localization reader -----\n";
	cout << "This program reads the string associated with a given key and prints it on the console.\n";
	cout << "Type 'help' for help.\n";

}

void printHelp()
{
	cout << "*** help ***\n";
	cout << "Type 'change to <language>' to change language. The possible values are:\n 'es' for spanish\n 'en' for english\n";
	cout << "Example: change to en\n\n";
	cout << "Type 'exit' to quit.\n\n";
	cout << "Type 'help' for help.\n";
}

