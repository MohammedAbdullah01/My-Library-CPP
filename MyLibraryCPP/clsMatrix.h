#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "clsString.h"
#include "clsUtil.h"

using namespace std;
class clsMatrix
{
	static int HowManyNumberCertainElementRepeated(int searchNum, int arr[100], int arrLength)
	{
		short counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (searchNum == arr[i])
				counter++;
		}
		return counter;
	}

	static void FillArrayWithRandomNumbers(int arr[100], int& arrLength, int startFromNum = 1, int endToNum = 100)
	{
		if (arrLength <= 0)
			throw invalid_argument("must be array length greater than 0");

		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = clsUtil::RandomNumber(startFromNum, endToNum);
		}
	}

	static int GetMaxNumberInArray(int arr[100], int arrLength)
	{
		int max = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (max < arr[i])
				max = arr[i];
		}
		return max;
	}

	static int GetMinNumberInArray(int arr[100], int arrLength)
	{
		int min = 2147483647;
		for (int i = 0; i < arrLength; i++)
		{
			if (min > arr[i])
				min = arr[i];
		}
		return min;
	}

	static int SumArray(int arr[100], int arrLength)
	{
		int sum = 0;
		for (int i = 0; i < arrLength; i++)
		{
			sum += arr[i];
		}
		return sum;
	}

	static float AverageArray(int arr[100], int arrLength)
	{
		return (float)SumArray(arr, arrLength) / arrLength;
	}

	static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrDestination[i] = arrSource[i];
		}
	}

	static void copyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{

			if (clsUtil::checkNumberPrime(arrSource[i]) == clsUtil::enPrimeOrNotPrime::Prime)
			{
				arrDestination[counter++] = arrSource[i];
			}
		}

		arr2Length = counter;
	}

	static void SumOfTwoArrayElements(int firstArr[100], int SecondArr[100], int sumArr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			sumArr[i] = firstArr[i] + SecondArr[i];
		}
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			int randNum1 = clsUtil::RandomNumber(1, arrLength - 1),
				randNum2 = clsUtil::RandomNumber(1, arrLength - 1);

			clsUtil::Swap2Number(arr[randNum1], arr[randNum2]);
		}
	}

	static void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrDestination[i] = arrSource[arrLength - 1 - i];
		}
	}

	static void FillArrayWithKeys(string arrSource[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrSource[i] = clsUtil::GenerateKey();
		}
	}

	static int FindPositionNumber(int findNumber, int arrSource[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arrSource[i] == findNumber)
				return i;
		}
		return -1;
	}

	static bool FindNumberInArray(int findNumber, int arrSource[100], int arrLength)
	{
		return FindPositionNumber(findNumber, arrSource, arrLength) != -1;
	}

	static bool IsPalindromeArray(int arr[100], int length)
	{
		for (int i = 0; i < length / 2; i++)
		{
			if (arr[i] != arr[length - i - 1])
			{
				return false;
			}
		}
		return true;
	}

	static int OddCount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if ((arr[i] % 2) != 0) {
				counter++;
			}
		}
		return counter;
	}

	static int EvenCount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if ((arr[i] % 2) == 0) {
				counter++;
			}
		}
		return counter;
	}

	static int PositiveCount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > 0) {
				counter++;
			}
		}
		return counter;
	}

	static int NegativeCount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] <= 0) {
				counter++;
			}
		}
		return counter;
	}

	static void FillMatrixWithRandomNumbers(int matrix[3][3], short strartFrom, short endTo)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matrix[i][j] = clsUtil::RandomNumber(strartFrom, endTo);
			}
		}
	}

	static void PrintEachRowSum(int matrix[3][3])
	{
		for (int i = 0; i < 3; i++)
		{
			int sum = 0;
			for (int j = 0; j < 3; j++)
			{
				sum += matrix[i][j];
			}
			cout << "Row " << i + 1 << " Sum = " << sum << endl;
		}
	}

	static int SumMatrixRowsInArray(int matrix[3][3], int arr[3])
	{
		for (int i = 0; i < 3; i++)
		{
			int sum = 0;
			for (int j = 0; j < 3; j++)
			{
				sum += matrix[i][j];
			}
			arr[i] = sum;
		}
	}

	static int SumColumnsInMatrix(int matrix[3][3], int column)
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			sum += matrix[i][column];
		}
		return sum;
	}

	static void SumMatrixColumnsInArray(int matrix[3][3], int arr[3])
	{
		for (int j = 0; j < 3; j++)
		{
			arr[j] = SumColumnsInMatrix(matrix, j);
		}
	}

	static void FillMatrixWithOrderedNumbers(int matrix[3][3])
	{
		short order = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				matrix[i][j] = order++;
			}
		}
	}

	static void TransposeMatrix(int matrix[3][3], int temp[3][3])
	{
		for (short i = 0; i < 3; i++)
		{
			for (short j = 0; j < 3; j++)
			{
				temp[j][i] = matrix[i][j];
			}
		}
	}

	static void MultiplyTwoMatrix(int matrix[3][3], int matrix2[3][3], int resultMatrix[3][3])
	{
		for (short i = 0; i < 3; i++)
		{
			for (short j = 0; j < 3; j++)
			{
				resultMatrix[i][j] = matrix[i][j] * matrix2[i][j];
			}
		}
	}

	static int SumAllNumbersInMatrix(int matrix[3][3], short rows, short columns)
	{
		int sum = 0;
		for (short i = 0; i < rows; i++)
		{
			sum += SumColumnsInMatrix(matrix, i);
		}
		return sum;
	}

	static bool CheckSumTwoMatrixEqualOrNotEqual(int matrix[3][3], int matrix2[3][3], short rows, short columns)
	{
		return SumAllNumbersInMatrix(matrix, rows, columns) == SumAllNumbersInMatrix(matrix2, rows, columns);
	}

	static bool CheckTwoMatrixEqualOrNotEqual(int matrix[3][3], int matrix2[3][3], short rows, short columns)
	{
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < columns; j++)
			{
				if (matrix[i][j] != matrix2[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}

	static bool IsIdentityMatrix(int matrix[3][3], short rows, short columns)
	{
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < columns; j++)
			{
				if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0))
				{
					return false;
				}
			}
		}
		return true;
	}

	static bool IsScalarMatrix(int matrix[3][3], short rows, short columns)
	{
		short firstDiagElement = matrix[0][0];
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < columns; j++)
			{
				if ((i == j && matrix[i][j] != firstDiagElement) ||
					(i != j && matrix[i][j] > 0))
				{
					return false;
				}
			}
		}
		return true;
	}

	static short HowManyRepetedNumberInMatrix(int matrix[3][3], short findNumber, short rows, short columns)
	{
		short counter = 0;
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < columns; j++)
			{
				if (matrix[i][j] == findNumber)
				{
					counter++;
				}
			}
		}
		return counter;
	}

	static bool IsMatrixSparce(int matrix[3][3], short rows, short columns)
	{
		return HowManyRepetedNumberInMatrix(matrix, 0, rows, columns) >= rows * columns / 2;
	}

	static bool IsExistsNumberInMatrix(int matrix[3][3], int Findnumber, short rows, short columns)
	{
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < columns; j++)
			{
				if (matrix[i][j] == Findnumber)
				{
					return true;
				}
			}
		}
		return false;
	}

	static int MinNumberInMatrix(int matrix[3][3], short rows, short columns)
	{
		int min = INT_MAX;
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < columns; j++)
			{
				if (matrix[i][j] < min)
				{
					min = matrix[i][j];
				}
			}
		}
		return min;
	}

	static int MaxNumberInMatrix(int matrix[3][3], short rows, short columns)
	{
		int max = INT_MIN;
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < columns; j++)
			{
				if (matrix[i][j] > max)
				{
					max = matrix[i][j];
				}
			}
		}
		return max;
	}

	static bool IsPalindromMatrix(int matrix[3][3], short rows, short columns)
	{
		for (short i = 0; i < rows; i++)
		{
			for (short j = 0; j < columns / 2; j++)
			{
				if (matrix[i][j] != matrix[i][columns - 1 - j])
				{
					return false;
				}
			}
		}
		return true;
	}
};
