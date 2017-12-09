#pragma once
using namespace std;

class Reader
{
	string currentLanguage;
	string xmlFile;
public:
	Reader();
	~Reader();
	void setLanguage(string languageIn);
	bool setCurrentDocument(string fileLocation);
	string getString(string key);
};

