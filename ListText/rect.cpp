#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <string.h>
#include "rect.h"
#include<stdio.h>
#include <tchar.h>


using namespace std;

Rect::Rect() {};
BOOL Rect::setxy(int x, int y)   //*This method sets the cursor position.
{
	COORD c = { x,y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Rect::DrawRect(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0)
{
	setxy(x, y);
	cout << "\xC9";
	for (int i = 1; i < width; i++)
	{
		cout << "\xCD";
	}
	cout << "\xBB";

	setxy(x, height + y);

	cout << char(200);
	for (int i = 1; i < width; i++)
	{
		cout << char(205);
	}

	cout << char(188);
	for (int i = y + 1; i < height + y; i++)
	{
		setxy(x, i); cout << char(186);
		setxy(x + width, i);
		cout << char(186);
	}
	setxy(curPosX, curPosY);
}
void Rect::TextInBox(int x, int y, int z)
{
	char  str[49];
	COORD destCoord;
	destCoord.X = x;
	destCoord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), destCoord);
	const int Buffer_Length = 49;

	HANDLE hStdin, hStdout;
	DWORD dwCharsRead, dwCharsWritten;
	TCHAR tszBuffer[Buffer_Length];

	BOOL bSuccess;

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!hStdin) {
		printf("Handle to stdin????.\n");
	}
	if (!hStdout) {
		printf("Handle to stdout ????\n");
	}

	while (1)
	{
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), destCoord);

		bSuccess = ReadConsole(hStdin, tszBuffer, Buffer_Length - 2, &dwCharsRead, NULL);

		if (!bSuccess)
		{
			printf("Read console not Success.");
		}
		if (z == 0)
		{
			exit(1);
		}

		//santance = strlen(tszBuffer);

		TextInBox(x, y + 1, z - 1);

	}

	CloseHandle(hStdin);
	CloseHandle(hStdout);

}