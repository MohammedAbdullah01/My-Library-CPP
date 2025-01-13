#pragma once
#include <iostream>
#include <string>
#include "clsInputValidate.h"

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

	static double ReadDoubleNumber()
	{
		double number;
		cin >> number;
		return number;
	}

	static int ReadIntNumber()
	{
		return (int)ReadDoubleNumber();
	}

	static short ReadShortNumber()
	{
		return (short)ReadIntNumber();
	}

	static double ReadPositiveDoubleNumber(string msgInvalid)
	{
		double number = ReadDoubleNumber();
		while (number <= 0)
		{
			cout << msgInvalid << endl;
		}
		return number;
	}

	static int ReadPositiveNumber(string msgInvalid)
	{
		return (int)ReadPositiveDoubleNumber(msgInvalid);
	}

	static double ReadNumberInRange(double from, double to , string msgInvalid)
	{

		double number = ReadDoubleNumber();
		
		while ( !clsInputValidate::IsNumberBetween(number , from , to))
		{
			cout << msgInvalid << endl;
			number = ReadDoubleNumber();
		}
		return number;
	}

	static int ReadNumberInRange(int from, int to , string msgInvalid)
	{
		return (int)ReadNumberInRange((double)from , (double)to , msgInvalid);
	}

	static short ReadNumberInRange(short from, short to, string msgInvalid)
	{
		return (short)ReadNumberInRange((double)from, (double)to, msgInvalid);
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

