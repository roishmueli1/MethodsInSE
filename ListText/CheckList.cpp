#include "stdafx.h"


#include "CheckList.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>


HANDLE hStdin;
DWORD fdwSaveOldMode;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int x = 0, y = 0;
void CheckList::DrawCheckList()
{
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	// Get the standard input handle. 

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	// Loop to read and handle the next 100 input events. 
	gotoXY(33, 16);
	std::cout << "\xDB Menu Item 1";
	gotoXY(33, 20);
	std::cout << "\xDB Menu Item 2";
	gotoXY(50, 16);
	std::cout << "\xDB Menu Item 3";
	gotoXY(50, 20);
	std::cout << "press escape to Quit";

	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD NumInputs = 0;
	DWORD InputsRead = 0;
	bool running = true;

	INPUT_RECORD irInput;

	GetNumberOfConsoleInputEvents(hInput, &NumInputs);

	while (running)
	{
		ReadConsoleInput(hInput, &irInput, 1, &InputsRead);
		//std::cout << irInput.Event.KeyEvent.wVirtualKeyCode << std::endl;

		switch (irInput.Event.KeyEvent.wVirtualKeyCode)
		{
		case VK_ESCAPE:
			running = false;
			//Quit The Running Loop
			break;
		case VK_LEFT:
		case VK_NUMPAD4:

			break;
		case VK_UP:
		case VK_NUMPAD8:
		{
			gotoXY(33, 16);
			std::cout << "\xFB";
			gotoXY(33, 26);
			std::cout << "You picked menu one";

		}
		break;
		case VK_RIGHT:
		case VK_NUMPAD6:
		{

			gotoXY(50, 16);
			std::cout << "\xFB";
			gotoXY(33, 26);
			std::cout << "You picked menu three";
			gotoXY(54, 26);
			std::cout << "      Hello from checklist Number 3  ";
		}
		break;
		case VK_DOWN:
		case VK_NUMPAD2:
		{
			gotoXY(33, 20);
			std::cout << "\xFB";
			gotoXY(33, 26);
			std::cout << "You picked menu two";
			Sleep(1000);
			gotoXY(54, 26);
			std::cout << ".";
			Sleep(1000);
			gotoXY(55, 26);
			std::cout << ".";
			Sleep(1000);
			gotoXY(56, 26);
			std::cout << ".";
			gotoXY(58, 26);
			Sleep(1000);
			std::cout << "  Hello from Menu two ";
		}
		break;
		}

	}

}


VOID CheckList::ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

VOID CheckList::KeyEventProc(KEY_EVENT_RECORD ker)
{
	printf("Key event: ");

	if (ker.bKeyDown)
		printf("key pressed");
	else printf("key released");
}


VOID CheckList::ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}

void CheckList::gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}