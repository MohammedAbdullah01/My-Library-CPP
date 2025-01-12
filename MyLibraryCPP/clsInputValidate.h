#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(float num, float numFrom, float numTo)
	{
		return num >= numFrom && num <= numTo;
	}

	static bool IsNumberBetween(short num, short numFrom, short numTo)
	{
		return IsNumberBetween(num , numFrom , numTo);
	}

	static bool IsDateBetween(clsDate currentDate , clsDate dateFrom , clsDate dateTo)
	{
		return (currentDate.CompareDates(dateFrom) != clsDate::enDateCompare::Before) &&
			(currentDate.CompareDates(dateTo) != clsDate::enDateCompare::After);
	}

	static int ReadNumberWithValidate(string msgInvalid)
	{
		int number;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << msgInvalid;
			cin >> number;
		}
		return number;
	}

	static bool IsValidateDate(clsDate date) {
		if (date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31) {
			return false;
		}
		short daysInMonth = clsDate::howManyDaysInMonth(date.year, (clsDate::enNumberOfDaysPerMonth)date.month);
		return date.day <= daysInMonth;
	}
};

