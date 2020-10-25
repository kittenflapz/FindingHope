#include "App/app.h"

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
