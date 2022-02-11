#include <cmath>
#include "struct.h"
#include "handler.h"

void leapYearCalc(int year1, int year2, int& date1, int& date2)
{
	for (int i = 1; i < year1; i++)
	{
		if (!(i % 4) && i % 100 || !(i % 400)) date1++;
	}
	for (int i = 1; i < year2; i++)
	{
		if (!(i % 4) && i % 100 || !(i % 400)) date2++;
	}
}

void monthsDaysCalc(int month1, int month2, int& date1, int& date2)
{
	const int size = 12;
	int daysInMonths[size]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int days1 = 0;
	int days2 = 0;

	if (month1 > 1)
	{
		for (int i = 0; i < month1 - 1; i++)
		{
			days1 += daysInMonths[i];
		}
	}

	if (month2 > 1)
	{
		for (int i = 0; i < month2 - 1; i++)
		{
			days2 += daysInMonths[i];
		}
	}

	date1 += days1 - 1;
	date2 += days2 - 1;
}

int datesDifferences(Date dateFirst, Date dateSecond)
{

	int daysInDate1 = dateFirst.day + dateFirst.year * 365 - 365;
	int daysInDate2 = dateSecond.day + dateSecond.year * 365 - 365;

	leapYearCalc(dateFirst.year, dateSecond.year, daysInDate1, daysInDate2);
	monthsDaysCalc(dateFirst.month, dateSecond.month, daysInDate1, daysInDate2);

	return abs(daysInDate1 - daysInDate2);
}