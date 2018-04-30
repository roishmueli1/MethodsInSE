// ListText.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <string.h>
#include "rect.h"
#include "CheckList.h"


using namespace std;

INPUT_RECORD irInput;
HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
DWORD InputsRead = 0;


int main()
{

	CheckList c; Rect r;
	system("Color 1A");
	cout << "\n\tPress ENTER: TextBox, Press F1: CheckList.:";
	while (1)
	{

		ReadConsoleInput(hInput, &irInput, 1, &InputsRead);

		switch (irInput.Event.KeyEvent.wVirtualKeyCode)
		{
		case VK_F1:
			cout << "F1" << endl;
			c.DrawCheckList();

			break;

		case VK_RETURN:
			cout << "ENTER" << endl;
			r.DrawRect(30, 5, 50, 5, 30, 20);
			r.TextInBox(31, 6, 3);

			break;
		}

	}

	return 0;
}

