#include "stdafx.h"
#include "Typewriter.h"

Typewriter::Typewriter()
{
	timer = 0.0f;
	printNextCharDelay = 5.0f;
	stringToPrint = "";
}

Typewriter::~Typewriter()
{
}

void Typewriter::PopulateQueue(std::string str)
{
	for (char c : str)
	{
		charsToPrint.push(c);
	}
}

void Typewriter::AddNextCharToPrintString()
{
	stringToPrint += charsToPrint.front();
	charsToPrint.pop();
}

void Typewriter::Update()
{
	App::Print(800.0f, 60.0f, stringToPrint.c_str(), 1.0f, 1.0f, 1.0f, GLUT_BITMAP_8_BY_13);
	// if there's still something in the queue
	if (!charsToPrint.empty())
	{
		// And it's time
		if (timer >= printNextCharDelay)
		{
			// add it to the string to print
			AddNextCharToPrintString();
			timer = 0.0f;
		}
		else
		{
			timer++;
		}
	}
}
