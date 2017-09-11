#pragma once
#include <conio.h>

class Key
{
public:
	enum TYPE
	{
		NONE,
		NUM0 = '0', NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
		SPACE = 32, ENTER = 13, ESC = 27, I = 105, TAB=9, C=99,
		ARROW = 224, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80,
		F1 = 59, F2, F3, F4, F5, F6, F7, F8, F9, F10,
	};

	static TYPE GetInput()
	{
		int input = getch();
		if (input == NONE || input == ARROW)
		{
			input = getch();
		}
		return (TYPE)input;
	}

	static TYPE GetArrow()
	{
		int input = 0;
		while (true)
		{
			input = getch();
			if (input == ENTER)return (TYPE)input;
			if (input == ARROW)return (TYPE)getch();
		}
	}
};