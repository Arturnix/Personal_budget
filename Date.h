#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdio.h>
#include <time.h>

#include "OtherMethods.h"

using namespace std;

class Date {

public:
    static string getCurrentDate();
    static int getCurrentYear ();
    static int getCurrentMonth ();
    static string getYearFromInputDate (string date);
    static string getMonthFromInputDate (string date);
    static string getDayFromInputDate (string date);
    static bool isLeapYear (int year);
    static int howManyDaysInMonth(int month);
    static bool isYearCorrect(string userDate);
    static bool isMonthCorrect (string userDate);
    static bool isDayCorrect (string userDate);
    static bool isDateCorrect(string userDate);
    static string inputDate ();
    static int convertStringDateToIntDate (string stringDateWithSeparators);
    static string stringDateWithoutSeparators (string stringDateWithSeparators);
};

#endif // DATE_H
