#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsInputRead
{
public:
	static char ReadCharacter(string msg)
	{
		char charcter;
		cout << msg;
		cin >> charcter;
		return charcter;
	}

	static string ReadWord(string msg)
	{
		string Word;
		cout << msg;
		cin >> Word;
		return Word;
	}

	static string ReadWords(string msg)
	{
		string Inter = ReadWord(msg);
		getline(cin >> ws, Inter);
		return Inter;
	}

	static double ReadNumberDouble(string msg)
	{
		double number;
		cout << msg;
		cin >> number;
		return number;
	}

	static int ReadNumberInteger(string msg)
	{
		return ReadNumberDouble(msg);
	}

	static double ReadPositiveDoubleNumber(string msgInvalid)
	{
		double number;
		do
		{
			number = ReadNumberDouble(msgInvalid);
		} while (number <= 0);

		return number;
	}

	static int ReadPositiveNumber(string msgInvalid)
	{
		return ReadPositiveDoubleNumber(msgInvalid);
	}

	static double ReadNumberInRangeDouble(double from, double to , string msgInvalid)
	{
		double number;
		do
		{
			number = ReadNumberInteger(msgInvalid);
		} while (number < from || number > to);

		return number;
	}

	static int ReadNumberInRange(int from, int to , string msgInvalid)
	{
		return ReadNumberInRangeDouble(from , to , msgInvalid);
	}

	static char ReadCharacterAsteriskOrPlusOrMinusOrDivide()
	{
		char character;
		do
		{
			character = ReadCharacter("Please Enter Asterisk Or Plus Or Minus Or Divide (*, +, -, /): ");
		} while (character != '*' &&
			character != '+' &&
			character != '-' &&
			character != '/');

		return character;
	}

};

