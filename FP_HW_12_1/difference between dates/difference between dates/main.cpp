#include <iostream>
#include "handler.h"
#include "input.h"
#include "output.h"
#include "check.h"
#include "struct.h"

Date date1;
Date date2;
int dateDiff;
bool isFirstDate = true;

int main()
{
	isFirstDate = EnterDate(isFirstDate);
	try
	{
		getDate(date1);
		checkDate(date1);
	}
	catch (int exeption)
	{
		if (exeption == -1)
		{
			std::cout << "\x1b[31mIncorrect Date Input\x1b[0m\n";
			return -1;
		}
		if (exeption == -2)
		{
			std::cout << "\x1b[31mIncorrect Input\x1b[0m\n";
			return -2;
		}
	}
	system("cls");
	EnterDate(isFirstDate);
	try
	{
		getDate(date2);
		checkDate(date2);
	}
	catch (int exeption)
	{
		if (exeption == -1)
		{
			std::cout << "\x1b[31mIncorrect Date Input\x1b[0m\n";
			return -1;
		}
		if (exeption == -2)
		{
			std::cout << "\x1b[31mIncorrect Input\x1b[0m\n";
			return -2;
		}
	}
	system("cls");
	dateDiff = datesDifferences(date1, date2);
	showResults(date1, date2, dateDiff);
}
