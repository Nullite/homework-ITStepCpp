#pragma once
#include <string>
#include "variables.h"

bool numsInPosition()
{
	if (board[sqears[15]] != ' ') return false;
	for (int i = 0; i < 15; i++)
	{
		try
		{
			std::string check = board.substr(sqears[i], 2);
			if (std::stoi(check) != i + 1)
				return false;
		}
		catch (std::invalid_argument exeption)
		{
			return false;
		}
		
	}
	return true;
}
