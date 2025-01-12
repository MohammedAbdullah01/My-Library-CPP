#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsPeriod
{
private :
	clsDate _DateStart, _DateEnd;

public:

	clsPeriod(clsDate dateEnd)
	{
		clsDate _DateStart = clsDate();
		_DateEnd = dateEnd;
	}

	clsPeriod(clsDate dateStart, clsDate dateEnd)
	{
		_DateStart = dateStart;
		_DateEnd = dateEnd;
	}


	static bool IsOverlapPeriods(clsPeriod period1, clsPeriod period2)
	{
		if (!(clsDate::validateDate(period1._DateStart) && clsDate::validateDate(period1._DateEnd) &&
			clsDate::validateDate(period2._DateStart) && clsDate::validateDate(period2._DateEnd)))
		{
			throw invalid_argument("One or more provided dates are invalid.");
		}

		return (
			clsDate::CompareDates(period2._DateEnd, period1._DateStart)
			== clsDate::enDateCompare::Before ||

			clsDate::CompareDates(period2._DateStart, period1._DateEnd)
			== clsDate::enDateCompare::After)
			? false
			: true;
	}

	bool IsOverlapPeriods(clsPeriod period)
	{
		return IsOverlapPeriods(*this , period);
	}

	static vector<clsDate> getDatesOverlapBetween2Periods(clsPeriod period1, clsPeriod period2)
	{
		if (!IsOverlapPeriods(period1, period2)) {
			return {};
		}

		clsDate overlapStart = clsDate::CompareDates(period1._DateStart, period2._DateStart)
			== clsDate::enDateCompare::After ? period1._DateStart : period2._DateStart;

		clsDate overlapEnd = clsDate::CompareDates(period1._DateEnd, period2._DateEnd)
			== clsDate::enDateCompare::Before ? period1._DateEnd : period2._DateEnd;

		vector<clsDate> datesOverlap;

		while (clsDate::CompareDates(overlapStart, overlapEnd) != clsDate::enDateCompare::After)
		{
			datesOverlap.push_back(overlapStart);
			overlapStart = clsDate::increaseDateByOneDay(overlapStart);
		}

		return datesOverlap;
	}

	vector<clsDate> getDatesOverlapBetween2Periods(clsPeriod period)
	{
		return getDatesOverlapBetween2Periods(*this , period);
	}

	static short calculatePeriodLengthInDays(clsPeriod period, bool includeEndDate = false)
	{
		return clsDate::calculateDifferenceInDays(period._DateStart, period._DateEnd, includeEndDate);
	}

	short calculatePeriodLengthInDays(bool includeEndDate = false)
	{
		return calculatePeriodLengthInDays(*this , includeEndDate);
	}

	static bool isDateInPeriod(clsPeriod period, clsDate date)
	{
		return (clsDate::CompareDates(date, period._DateStart) != clsDate::enDateCompare::Before) &&
			(clsDate::CompareDates(date, period._DateEnd) != clsDate::enDateCompare::After);
	}

	bool isDateInPeriod(clsDate date)
	{
		return isDateInPeriod(*this , date);
	}

	static short howManyDaysOverlap(clsPeriod period1, clsPeriod period2, bool includeEndDate = false)
	{
		if (!IsOverlapPeriods(period1, period2)) {
			return 0;
		}

		clsDate overlapStart = clsDate::CompareDates(period1._DateStart, period2._DateStart)
			== clsDate::enDateCompare::After ? period1._DateStart : period2._DateStart;

		clsDate overlapEnd = clsDate::CompareDates(period1._DateEnd, period2._DateEnd)
			== clsDate::enDateCompare::Before ? period1._DateEnd : period2._DateEnd;

		return clsDate::calculateDifferenceInDays(overlapStart, overlapEnd, includeEndDate);
	}

	short howManyDaysOverlap(clsPeriod period, bool includeEndDate = false)
	{
		return howManyDaysOverlap(*this , period , includeEndDate);
	}

	void DisplayStartDate()
	{
		clsDate::DisplayDate(this->_DateStart);
	}

	void DisplayEndDate()
	{
		clsDate::DisplayDate(this->_DateEnd);
	}
};

