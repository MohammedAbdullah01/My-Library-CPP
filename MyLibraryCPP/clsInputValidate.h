#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsDate.h"
#include <string>
#include <sstream>

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(double num, double numFrom, double numTo)
	{
		return num >= numFrom && num <= numTo;
	}

	static bool IsNumberBetween(int num, int numFrom, int numTo)
	{
		return IsNumberBetween((double)num, (double)numFrom, (double)numTo);
	}

	static bool IsNumberBetween(short num, short numFrom, short numTo)
	{
		return IsNumberBetween((double)num, (double)numFrom, (double)numTo);
	}

	static bool IsDateBetween(clsDate currentDate , clsDate dateFrom , clsDate dateTo)
	{
		if ((currentDate.CompareDates(dateFrom) == clsDate::enDateCompare::After) &&
			(currentDate.CompareDates(dateTo) == clsDate::enDateCompare::Before))
		{
			return true;
		}

		if ((currentDate.CompareDates(dateTo) != clsDate::enDateCompare::Before) &&
			(currentDate.CompareDates(dateFrom) != clsDate::enDateCompare::After))
			return true;

		return false;
	}

	static double ReadDoubleNumberWithValidate(string msgInvalid)
	{
		double number;
		string input;

		while (true)
		{
			cin >> input; // Read input as string

			// Try to convert the input to a double
			stringstream ss(input);
			if (ss >> number && ss.eof())  // Ensure the entire string is valid and can be converted to a double
			{
				break;  // Exit the loop if the number is valid
			}
			else
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
				cout << msgInvalid; // Print the invalid message
			}
		}

		return number;
	}

	static int ReadIntNumberWithValidate(string msgInvalid)
	{
		return (int)ReadDoubleNumberWithValidate(msgInvalid);
	}

	static bool IsValidateDate(clsDate date) {
		if (date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31) {
			return false;
		}
		short daysInMonth = clsDate::howManyDaysInMonth(date.year, (clsDate::enNumberOfDaysPerMonth)date.month);
		return date.day <= daysInMonth;
	}
};

