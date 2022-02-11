#include <iostream>
#include <string>
#include "struct.h"
#include "input.h"



void getDate(Date& date)
{
	std::cout << "Enter a day\n\n";
	std::cin >> date.day;
	if (!std::cin >> date.day) throw - 2;
	std::cin.clear();
	std::cout << "Enter a month\n\n";
	std::cin >> date.month;
	if (!std::cin >> date.month) throw - 2;
	std::cin.clear();
	std::cout << "Enter a year\n\n";
	std::cin >> date.year;
	if (!std::cin >> date.year) throw - 2;
	std::cin.clear();
}

std::string getFormatDate(struct Date date)
{
	char zero = '0';
	std::string day = std::to_string(date.day);
	if (day.length() == 1) day.insert(day.begin(), zero);

	std::string month = std::to_string(date.month);
	if (month.length() == 1) month.insert(month.begin(), zero);

	std::string year = std::to_string(date.year);
	if (year.length() < 4)
	{
		for (int i = 0; i <= 4 - year.length(); i++)
		{
			year.insert(year.begin(), zero);
		}
		if (year.length() == 3) year.insert(year.begin(), zero);
	}


	std::string formatDate = day + " / " + month + " / " + year;
	return formatDate;
}

bool EnterDate(bool isFirstDate)
{
	if (isFirstDate) std::cout << "Enter a first Date.\n\n";
	else std::cout << "Enter a second date.\n\n";
	return false;
}

