#include "App/app.h"

// Small class for printing text one char at a time like a typewriter

#ifndef TYPEWRITER_H
#define TYPEWRITER_H
class Typewriter
{
public:

	Typewriter();

	~Typewriter();

	void PopulateQueue(std::string str);

	void AddNextCharToPrintString();

	void Update();

private:
	std::queue<char> charsToPrint;
	std::string stringToPrint ;
	float timer;
	float printNextCharDelay;
};
#endif // TYPEWRITER_H
