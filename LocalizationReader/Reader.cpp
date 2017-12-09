#include "stdafx.h"
#include "Reader.h"

const string ENGLISH = "en";
const string SPANISH = "es";

/*
	Builder. It assigns the english language by default.
*/
Reader::Reader()
{
	currentLanguage = ENGLISH;
	cout << "Current language: " << "English\n";
}

/*
	Destructor
*/
Reader::~Reader()
{
}

/*
	Set the current language to the one given as parameter.
	If the parameter does not match any expected value, print the valid options.
*/
void Reader::setLanguage(string languageIn)
{
	if (languageIn == ENGLISH)
	{
		currentLanguage = ENGLISH;
		cout << "Language set to " << "English\n";
	}	
	else if (languageIn == SPANISH)
	{
		currentLanguage = SPANISH;
		cout << "Language set to " << "Spanish\n";
	}		
	else
	{
		cout << "Invalid name. The expected values are: \nen (for english)\nes(for spanish)\n";
	}
}

/*
	Change the current xml document for the one in the location given as parameter.
	Returns true if the file has a valid format.
*/
bool Reader::setCurrentDocument(string fileLocation)
{
	bool validFile = true;

	// Test the validity of the file
	ifstream xmlFileStream(fileLocation);
	xml_document<> currentDoc;
	xml_node<> *rootNode;
	vector<char> buffer((istreambuf_iterator<char>(xmlFileStream)), istreambuf_iterator<char>());
	buffer.push_back('\0'); // rapidxml needs the text to be zero-terminated.
	currentDoc.parse<0>(&buffer[0]);
	rootNode = currentDoc.first_node();
	if (rootNode == NULL)
		validFile = false;

	if(validFile) xmlFile = fileLocation;
	return validFile;
}

/*
	Retrieves the string associated with the given key for the current language.
*/
string Reader::getString(string key)
{
	ifstream xmlFileStream(xmlFile);
	xml_document<> currentDoc;
	xml_node<> *rootNode;
	vector<char> buffer((istreambuf_iterator<char>(xmlFileStream)), istreambuf_iterator<char>());
	buffer.push_back('\0'); // rapidxml needs the text to be zero-terminated.
	currentDoc.parse<0>(&buffer[0]);
	rootNode = currentDoc.first_node();

	string answer = "**Key not found**\n";
	for (xml_node<> * stringNode = rootNode->first_node(); stringNode; stringNode = stringNode->next_sibling())
	{
		//cout << "key: " << string_node->first_attribute()->value() << "\n";

		if (stringNode->first_attribute("key")->value() == key)
		{
			xml_node<> *textNode = stringNode -> first_node(currentLanguage.c_str());
			if (textNode != NULL)
			{
				answer = textNode -> value();
				answer.append("\n");
				break;
			}			
		}
	}
	return answer;

}