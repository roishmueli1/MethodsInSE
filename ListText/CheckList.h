#pragma once

#include <iostream>
#include <stdio.h>
#include <windows.h>

class CheckList
{
private:



public:

	void DrawCheckList();
	void ErrorExit(LPSTR);
	void KeyEventProc(KEY_EVENT_RECORD);
	void ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
	void gotoXY(int x, int y);

};