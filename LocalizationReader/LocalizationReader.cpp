// LocalizationReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Reader.h"

// Function declarations
void printHeader();
void printHelp();

// constants
const string HELP_COMMAND = "help";
const string EXIT_COMMAND = "exit";

int main()
{	
	printHeader();
	Reader reader;

	// promt for the localization file.
	string input;
	cout << "Type the location of the xml file:\n";
	bool validFile = false;
	do
	{
		cin >> input;
		if (!reader.setCurrentDocument(input))
			cout << "Invalid file. Try again.\n";
		else
			validFile = true;
	} while (validFile != true);

	// print some instructions
	cout << "Type '" << HELP_COMMAND << "' for help.\n";
	cout << "Type a command or a string key:\n";

	// rapidxml testing -------------
	/*xml_document<> doc;
	xml_node<> * root_node;
	ifstream xmlFile("loc.xml");
	vector<char> buffer((istreambuf_iterator<char>(xmlFile)), istreambuf_iterator<char>());
	buffer.push_back('\0'); // rapidxml needs the text to be zero-terminated.
	doc.parse<0>(&buffer[0]);
	root_node = doc.first_node();

	for (xml_node<> * string_node = root_node->first_node(); string_node; string_node = string_node->next_sibling())
	{
		cout << "key: " << string_node->first_attribute()->value() << "\n";
		xml_node<> * text_node = string_node->first_node("en");

		if(text_node != NULL )
			cout << text_node->value() << "\n"; // The console does not support unicode, but the text is correct.
	}*/
	
	//------------ -

	// Listen to the user's input
	string answer;
	while (true)
	{
		cin >> input;

		if (input == EXIT_COMMAND)
			break;

		if (input == HELP_COMMAND)
		{
			printHelp();
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
	cout << "Type '"<< EXIT_COMMAND <<"' to quit.\n\n";
	cout << "Type '"<< HELP_COMMAND  << "' for help.\n";
}

