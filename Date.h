#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdio.h>
#include <time.h>

#include "OtherMethods.h"

using namespace std;

class Date {

    static bool isLeapYear (int year);
    static int howManyDaysInMonth(int month);
    static bool isYearCorrect(string userDate);
    static bool isMonthCorrect (string userDate);
    static bool isDayCorrect (string userDate);
    static int getCurrentYear ();
    static int getCurrentMonth ();
    static int getPreviousMonth ();
    static string getCurrentDate();
    static string getYearFromInputDate (string date);
    static string getMonthFromInputDate (string date);
    static string getDayFromInputDate (string date);
    static bool isDateCorrect(string userDate);
    static int convertStringDateToIntDate (string stringDateWithSeparators);

public:
    static string inputDate ();
    static string inputDateForTimePeroid ();
    static int intDateWithoutSeparators (string stringDateWithSeparators);
    static string stringDateWithSeparators (int stringDateWithoutSeparators);
    static bool dateValidationForCurrentMonthFinancialBalance (string userDate);
    static bool dateValidationForPreviousMonthFinancialBalance (string userDate);
    static bool startDateValidationForTimePeroidFinancialBalance (string dateStart, int dateFromVector);
    static bool endDateValidationForTimePeroidFinancialBalance (string dateEnd, int dateFromVector);
};

#endif // DATE_H
