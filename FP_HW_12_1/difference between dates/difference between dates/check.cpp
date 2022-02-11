#include "struct.h"
#include "check.h"


void checkDate(Date date)
{
	if (date.day <= 0) throw - 1;
	if ((date.day > 28 && date.month == 2 && !(!(date.year % 4) && date.year % 100 || !(date.year % 400)))) throw - 1;
	if (date.day > 29 && date.month == 2) throw - 1;
	if (date.day > 30 && (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)) throw -1;
	if (date.day > 31) throw - 1;
	if (date.month < 1 || date.month > 12) throw - 1;
	if (date.year < 1 || date.year > 5000) throw - 1;
}
