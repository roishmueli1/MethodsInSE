#pragma once

#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

class Rect
{
private:



public:
	Rect();
	BOOL setxy(int, int);
	void DrawRect(int, int, int, int, int, int);
	void TextInBox(int, int, int);

};