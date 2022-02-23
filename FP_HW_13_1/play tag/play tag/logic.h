#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include "variables.h"
#include "check.h"


void fillBoard()
{
	for (int i = 0; i < 15; i++)
	{
		std::string a = std::to_string(tiles[i]);
		if (a.length() == 1)
			a.insert(a.begin(), ' ');
		board.replace(sqears[i], 2, a);
	}
}

void ShuffleTiles()
{
	srand(time(nullptr));
	std::random_shuffle(tiles, std::end(tiles));
}

void game()
{
	while (!numsInPosition())
	{
		system("cls");
		char move;
		std::cout << board;
		while (!_kbhit())
		{
			move = _getch();
			if (move != -32) continue;

		}
		move = _getch();
		switch (move)
		{
		case 'P':
			if (empty < 4) break;
			temp = board.substr(sqears[empty - 4], 2);
			board.replace(sqears[empty - 4], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty -= 4;
			break;
		case 'H':
			if (empty > 11) break;
			temp = board.substr(sqears[empty + 4], 2);
			board.replace(sqears[empty + 4], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty += 4;
			break;
		case 'M':
			if (empty == 0 || empty == 4 || empty == 8 || empty == 12) break;
			temp = board.substr(sqears[empty - 1], 2);
			board.replace(sqears[empty -1], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty -= 1;
			break;
		case 'K':
			if (empty == 3 || empty == 7 || empty == 11 || empty == 15) break;
			temp = board.substr(sqears[empty + 1], 2);
			board.replace(sqears[empty + 1], 2, emptyTile);
			board.replace(sqears[empty], 2, temp);
			empty += 1;
			break;

		}
		system("cls");
		std::cout << board;
	}
}

void congratulations()
{
	std::cout << "\n\n\n\n\n\n\t\t\t\tCONGRATIULATIONS!!! YOU SOLVE THE TAG!";
	Sleep(5000);
	system("cls");
}
