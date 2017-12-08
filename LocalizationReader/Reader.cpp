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
		cout << "Language changed to " << "English";
	}	
	else if (languageIn == SPANISH)
	{
		currentLanguage = SPANISH;
		cout << "Language changed to " << "Spanish";
	}		
	else
	{
		cout << "Invalid name. The expected values are: \nen (for english)\nes(for spanish)";
	}

}