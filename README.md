# Comprehensive Utility Toolkit

## Description
This project consists of several classes that offer extensive functionalities for different data types and use cases. The primary objective is to provide a suite of tools for string manipulation, date calculations, geometric calculations, matrix operations, and various utility functions. Each class encapsulates related methods and properties to perform specific operations efficiently.

### The project includes the following classes:

- **clsString**: Provides methods for manipulating and analyzing string values.

- **clsPeriod**: Handles operations related to periods between two dates, including overlap checks and period length calculations.

- **clsRectangle**: Calculates the area of a rectangle and manages its dimensions.

- **clsTriangle**: Calculates various properties of triangles, including area and circle-related calculations.

- **clsCircle** Provides methods for calculating properties of circles based on radius, diameter, and circumference.

- **clsSquare**: Calculates the area of a circle inscribed within a square.

- **clsMatrix** Offers various utility methods for working with arrays and matrices.

- **clsDate**: Provides comprehensive date manipulation and validation functionalities.

- **clsUtil**: Contains a variety of utility functions for mathematical operations, data handling, and encryption.

These classes are designed to be used independently or together, providing a robust and versatile toolkit for developers.

## Usage
### `clsString` Class
- **Overview**: The `clsString` class provides various methods for manipulating and analyzing string values.
- **Constructors**:
  - `clsString()`
  - `clsString(string value)`
- **Properties**:
  - `string value`
- **Methods**:
  - `UppercaseFirstLetterOfEachWord()`
  - `LowercaseFirstLetterOfEachWord()`
  - `UpperAllLetters()`
  - `LowerAllLetters()`
  - `InvertAllStringLettersCase()`
  - `CountLetters()`
  - `CountSmallLettersInString()`
  - `CountCapitalLettersInString()`
  - `HowManyRecurringcharacters()`
  - `IsVowel()`
  - `CountVowels()`
  - `CountEachWordInString()`
  - `SplitEachWordInVector()`
  - `TrimRightString()`
  - `TrimLeftString()`
  - `TrimString()`
  - `JoinString()`
  - `ReverseWords()`
  - `ReplaceString()`
  - `RemovePunctuationFromString()`
  - `replaceWordInString()`
- **Enums**:
  - `enWhatToCount`: Specifies what to count (CapitalLetters, SmallLetters, All).

### `clsPeriod` Class
- **Overview**: The `clsPeriod` class provides methods for working with periods between two dates.
- **Constructors**:
  - `clsPeriod(clsDate dateEnd)`
  - `clsPeriod(clsDate dateStart, clsDate dateEnd)`
- **Methods**:
  - `IsOverlapPeriods()`
  - `getDatesOverlapBetween2Periods()`
  - `calculatePeriodLengthInDays()`
  - `isDateInPeriod()`
  - `howManyDaysOverlap()`
  - `DisplayStartDate()`
  - `DisplayEndDate()`

### `clsRectangle` Class
- **Overview**: The `clsRectangle` class provides methods for calculating the area of a rectangle and managing its dimensions.
- **Constructors**:
  - `clsRectangle(float width, float height)`
- **Properties**:
  - `float width`
  - `float height`
  - `float diagonal`
- **Methods**:
  - `calculateRectangleArea()`
  - `calculateRectangleAreaThroughDiagonal()`

### `clsTriangle` Class
- **Overview**: The `clsTriangle` class provides methods for calculating various properties of triangles, including area and validation.
- **Constructors**:
  - `clsTriangle(float height, float base)`
  - `clsTriangle(float side1, float side2, float side3)`
- **Properties**:
  - `float height`
  - `float base`
  - `float ribs[]`
- **Methods**:
  - `calculateTriangleArea()`
  - `CalculateCircleAreaCircleDescribedAroundArbitraryTriangle()`
  - `CalculateCircleAreaInscribedInIsoscelesTriangle()`

### `clsCircle` Class
- **Overview**: The `clsCircle` class provides methods for calculating various properties of a circle, such as area based on radius, diameter, and circumference.
- **Constructors**:
  - `clsCircle(float radius, float diameter, float lengthPerimeter)`
- **Properties**:
  - `float radius`
  - `float diameter`
- **Methods**:
  - `CalculateCircleAreaByRadius()`
  - `CalculateAreaCircleFullDiameter()`
  - `CalculateCircleAreaAlongCircumference()`

### `clsSquare` Class
- **Overview**: The `clsSquare` class provides methods for calculating the area of a circle inscribed within a square.
- **Constructors**:
  - `clsSquare(float squareSide)`
- **Properties**:
  - `float squareSide`
- **Methods**:
  - `CalculateCircleAreaInscribedInSquare()`

### `clsMatrix` Class
- **Overview**: The `clsMatrix` class provides various utility methods for working with arrays and matrices.
- **Methods**:
  - `HowManyNumberCertainElementRepeated()`
  - `FillArrayWithRandomNumbers()`
  - `GetMaxNumberInArray()`
  - `GetMinNumberInArray()`
  - `SumArray()`
  - `AverageArray()`
  - `CopyArray()`
  - `copyOnlyPrimeNumbers()`
  - `SumOfTwoArrayElements()`
  - `ShuffleArray()`
  - `CopyArrayInReverseOrder()`
  - `FillArrayWithKeys()`
  - `FindPositionNumber()`
  - `FindNumberInArray()`
  - `IsPalindromeArray()`
  - `OddCount()`
  - `EvenCount()`
  - `PositiveCount()`
  - `NegativeCount()`
  - `FillMatrixWithRandomNumbers()`
  - `PrintEachRowSum()`
  - `SumMatrixRowsInArray()`
  - `SumColumnsInMatrix()`
  - `SumMatrixColumnsInArray()`
  - `FillMatrixWithOrderedNumbers()`
  - `TransposeMatrix()`
  - `MultiplyTwoMatrix()`
  - `SumAllNumbersInMatrix()`
  - `CheckSumTwoMatrixEqualOrNotEqual()`
  - `CheckTwoMatrixEqualOrNotEqual()`
  - `IsIdentityMatrix()`
  - `IsScalarMatrix()`
  - `HowManyRepetedNumberInMatrix()`
  - `IsMatrixSparce()`
  - `IsExistsNumberInMatrix()`
  - `MinNumberInMatrix()`
  - `MaxNumberInMatrix()`
  - `IsPalindromMatrix()`

### `clsDate` Class
- **Overview**: The `clsDate` class provides comprehensive date manipulation and validation functionalities.
- **Constructors**:
  - `clsDate()`
  - `clsDate(string date)`
  - `clsDate(short day, short month, short year)`
  - `clsDate(short addingDays, short year)`
- **Methods**:
  - `isLeapYear()`
  - `howManyDaysInYear()`
  - `howManyDaysInMonth()`
  - `SystemDate()`
  - `validateDate()`
  - `convertDateFromDateStringToDateObject()`
  - `IsLastDayInMonth()`
  - `IsLastMonthInYear()`
  - `increaseDateByOneDay()`
  - `IncreaseDateByXDays()`
  - `convertFromTotalDaysToDate()`
  - `DisplayDate()`
  - `FormatDate()`
  - `dayOfWeekOrder()`
  - `getMonthName()`
  - `getTotalDaysFromBeginOfYear()`
  - `IsDate1BeforeDate2()`
  - `IsDate1EqualDate2()`
  - `swapDates()`
  - `calculateDifferenceInDays()`
  - `IncreaseDateByOneWeek()`
  - `IncreaseDateByXWeek()`
  - `IncreaseDateByOneMonth()`
  - `IncreaseDateByXMonth()`
  - `IncreaseDateByOneYear()`
  - `IncreaseDateByXYears()`
  - `IncreaseDateByXYearsFaster()`
  - `IncreaseDateByOneDecade()`
  - `IncreaseDateByXDecades()`
  - `IncreaseDateByXDecadesFaster()`
  - `IncreaseDateByOneCentury()`
  - `IncreaseDateByOneMillennium()`
  - `decreaseDateByOneDay()`
  - `decreaseDateByXDays()`
  - `decreaseDateByOneWeek()`
  - `decreaseDateByXWeeks()`
  - `decreaseDateByOneMonth()`
  - `decreaseDateByXMonths()`
  - `decreaseDateByOneYear()`
  - `decreaseDateByXYears()`
  - `decreaseDateByXYearsFaster()`
  - `decreaseDateByOneDecade()`
  - `decreaseDateByXDecades()`
  - `decreaseDateByXDecadesFaster()`
  - `decreaseDateByOneCentury()`
  - `decreaseDateByOneMillennium()`
  - `IsEndOfWeek()`
  - `IsWeekEnd()`
  - `IsBusinessDay()`
  - `DaysUntilTheEndOfWeek()`
  - `DaysUntilTheEndOfMonth()`
  - `DaysUntilTheEndOfYear()`
  - `howManyTheActualVacationDaysFromDate1ToDate2()`
  - `vacationReturnDate()`
  - `IsDate1AfterDate2()`
  - `calculateBusinessDates()`
  - `calculateBusinessFromDateToNowDate()`
  - `CompareDates()`
  - `howManyHoursInYear()`
  - `howManyMinutesInYear()`
  - `howManySecondsInYear()`
  - `howManyHoursInMonth()`
  - `howManyMinutesInMonth()`
  - `howManySecondsInMonth()`
  - `getDay()`
  - `getMonth()`
  - `getYear()`
  - `setDay()`
  - `setMonth()`
  - `setYear()`
- **Enums**:
  - `enNumberOfDaysPerMonth
