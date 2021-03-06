﻿// LocalizationReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Reader.h"

// Function declarations
void printHeader();
void printHelp();
void selectFile(Reader &readerIn);

// constants
const string ENGLISH = "en";
const string SPANISH = "es";
const string HELP_COMMAND = "help";
const string EXIT_COMMAND = "exit";
const string CHANGE_TO_ES_COMMAND = "change to es";
const string CHANGE_TO_EN_COMMAND = "change to en";
const string CHANGE_FILE_COMMAND = "change file";

int main()
{	
	printHeader();
	Reader reader;

	// promt for the localization file.
	string input;
	cout << "Type the location of the xml file:\n";
	selectFile(reader);

	// print some instructions
	cout << "Type '" << HELP_COMMAND << "' for help.\n";
	cout << "Type a command or a string key:\n";

	// Listen to the user's input
	string answer;
	while (true)
	{
		getline(cin, input);

		if (input == EXIT_COMMAND)
			break;

		if (input == HELP_COMMAND)
		{
			printHelp();
			continue;
		}

		if (input == CHANGE_TO_EN_COMMAND)
		{
			reader.setLanguage(ENGLISH);
			continue;
		}

		if (input == CHANGE_TO_ES_COMMAND)
		{
			reader.setLanguage(SPANISH);
			continue;
		}

		if (input == CHANGE_FILE_COMMAND)
		{
			cout << "Type the location of the xml file:\n";
			selectFile(reader);
			continue;
		}

		cout << reader.getString(input);
		
			
	}

    return 0;
}

void printHeader()
{
	cout << "---- Localization reader -----\n";
	cout << "This program reads the string associated with a given key and prints it on the console.\n";	
	//cout << "Type 'help' for help.\n";

}

void printHelp()
{
	cout << "*** help ***\n";
	cout << "Type 'change to <language>' to change language. The possible values are:\n 'es' for spanish\n 'en' for english\n";
	cout << "Example: change to en\n\n";
	cout << "Type '"<< CHANGE_FILE_COMMAND << "' to change the input xml file.\n\n";
	cout << "Type '"<< EXIT_COMMAND <<"' to quit.\n\n";
	cout << "Type '"<< HELP_COMMAND  << "' for help.\n";
}

void selectFile(Reader &readerIn)
{
	bool validFile = false;
	string input;
	do
	{		
		getline(cin, input);
		if (!readerIn.setCurrentDocument(input))
			cout << "Invalid file. Try again.\n";
		else
			validFile = true;
	} while (validFile != true);
	cout << "File opened succesfully!\n";
}

