//---------------------------------------------------------------------------------
// App.cpp
// Implementation of the calls that are exposed via the App namespace.
//---------------------------------------------------------------------------------
#include "stdafx.h"
//---------------------------------------------------------------------------------
#include <string>
#include "main.h"
#include "app.h"
#include "SimpleSound.h"
#include "SimpleController.h"
#include "SimpleSprite.h"


//---------------------------------------------------------------------------------
// Utils and externals for system info.

namespace App
{	
	void DrawLine(float sx, float sy, float ex, float ey, float r, float g, float b)
	{
#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(sx, sy);
		APP_VIRTUAL_TO_NATIVE_COORDS(ex, ey);
#endif
		glBegin(GL_LINES);
		glColor3f(r, g, b);
		glVertex2f(sx, sy);
		glVertex2f(ex, ey);
		glEnd();
	}


	// Added stuff
	void DrawCircle(float x, float y, float radius, float r, float g, float b)
	{
	#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(x, y);
	#endif
		const unsigned int triangles = 20; // number of triangles
		const float twoPi = 2.0f * 3.14159f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(r, g, b);
		glVertex2f(x, y); 
		float delta = twoPi / triangles;
		for (unsigned int i = 0; i <= triangles; i++)
			glVertex2f(x + ((radius * 0.05) * cos(i * delta)),
				y + ((radius * 0.05) * sin(i * delta)));
		glEnd();
	}

	void DrawPolygonOutline(int cx, int cy, float radius, float numPoints, float r, float g, float b)
	{
		float angle = 2 * M_PI / numPoints;
		for (int i = 0; i < numPoints +1; i++)
		{
			if (i > 0) 
			{
				DrawLine(cx + radius * sin(i * angle),
					cy + radius * cos(i * angle), cx + radius * sin((i - 1) * angle), cy + radius * cos((i - 1) * angle), r, g, b);
			}
		}
	}

	void DrawRect(float sx, float sy, float ex, float ey, float r, float g, float b)
	{
#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(sx, sy);
		APP_VIRTUAL_TO_NATIVE_COORDS(ex, ey);
#endif
		glBegin(GL_TRIANGLES);
		glColor3f(r, g, b);
		glVertex2f(sx, sy);
		glVertex2f(ex, sy);
		glVertex2f(ex, ey);

		glVertex2f(ex, ey);
		glVertex2f(sx, ey);
		glVertex2f(sx, sy);
		glEnd();
	}

	void DrawRectOutline(float sx, float sy, float ex, float ey, float r, float g, float b)
	{
#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(sx, sy);
		APP_VIRTUAL_TO_NATIVE_COORDS(ex, ey);
#endif
		glBegin(GL_LINE_STRIP);
		glColor3f(r, g, b); 
		glVertex2f(sx, sy);
		glVertex2f(ex, sy);
		glVertex2f(ex, ey);

		glVertex2f(ex, ey);
		glVertex2f(sx, ey);
		glVertex2f(sx, sy);
		glEnd();
	}
	
	CSimpleSprite *CreateSprite(const char *fileName, int columns, int rows)
	{
		return new CSimpleSprite(fileName, columns, rows);
	}

	Player *CreatePlayer(float x, float y, float w, float h, float speed)
	{
		return new Player(x, y, w, h, speed);
	}

	Grief *CreateGrief(float x, float y, float radius, float speed)
	{
		return new Grief(x, y, radius, speed);
	}

	Hope *CreateHope(float x, float y, float radius, float speed)
	{
		return new Hope(x, y, radius, speed);
	}

	LightFuelBar *CreateLightFuelBar(float x, float y, float width, float maxFuel)
	{
		return new LightFuelBar(x, y, width, maxFuel);
	}

	bool IsKeyPressed(int key)
	{
		return ((GetAsyncKeyState(key) & 0x8000) != 0);
	}

	void GetMousePos(float &x, float &y)
	{
		POINT mousePos;
		GetCursorPos(&mousePos);	// Get the mouse cursor 2D x,y position			
		ScreenToClient(MAIN_WINDOW_HANDLE, &mousePos);
		x = (float)mousePos.x;
		y = (float)mousePos.y;
		x = (x * (2.0f / WINDOW_WIDTH) - 1.0f);
		y = -(y * (2.0f / WINDOW_HEIGHT) - 1.0f);

#if APP_USE_VIRTUAL_RES		
		APP_NATIVE_TO_VIRTUAL_COORDS(x, y);
#endif
	}
	void PlaySound(const char *fileName, bool looping)
	{
		DWORD flags = (looping) ? DSBPLAY_LOOPING : 0;
		CSimpleSound::GetInstance().PlaySound(fileName, flags);
	}
	void StopSound(const char *fileName)
	{
		CSimpleSound::GetInstance().StopSound(fileName);
	}
	bool IsSoundPlaying(const char *fileName)
	{
		return CSimpleSound::GetInstance().IsPlaying(fileName);
	}
	// This prints a string to the screen
	void Print(float x, float y, const char *st, float r, float g, float b, void *font)
	{
#if APP_USE_VIRTUAL_RES		
		APP_VIRTUAL_TO_NATIVE_COORDS(x, y);
#endif		
		// Set location to start printing text
		glColor3f(r, g, b); // Yellow
		glRasterPos2f(x, y);
		int l = (int)strlen(st);
		for (int i = 0; i < l; i++)
		{
			glutBitmapCharacter(font, st[i]); // Print a character on the screen
		}
	}
	const CController &GetController( int pad )
	{
		return CSimpleControllers::GetInstance().GetController(pad);
	}
}