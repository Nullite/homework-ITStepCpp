#include <iostream>
#include "struct.h"
#include "input.h"
#include "output.h"


void showResults(Date date1, Date date2, int diff)
{
	std::cout << "\x1b[32mDays between \x1b\x1b[31m" << getFormatDate(date1) 
			  << "\x1b[32m and \x1b\x1b[31m" << getFormatDate(date2) 
			  << "\x1b[32m - \x1b[33m" << diff <<"\x1b[0m";
}