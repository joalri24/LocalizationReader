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

	// rapidxml testing -------------
	xml_document<> doc;
	xml_node<> * root_node;
	ifstream xmlFile("Localization_Text.xml");
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
	}

	//------------ -

	// Listens to the user input
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

