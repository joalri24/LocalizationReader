#pragma once
using namespace std;

class Reader
{
	string currentLanguage;
public:
	Reader();
	~Reader();
	void setLanguage(string languageIn);
};

