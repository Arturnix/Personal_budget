#include "Date.h"

string Date::getCurrentDate() {

    time_t rawtime;
    struct tm * timeinfo;

    string date = "";

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int day = timeinfo->tm_mday;
    int month = timeinfo->tm_mon + 1;
    int year = timeinfo->tm_year + 1900;

    date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);

    return date;
}

int Date::getCurrentYear () {

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int currentYear = timeinfo->tm_year + 1900;

    return currentYear;
}

int Date::getCurrentMonth () {

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int currentMonth = timeinfo->tm_mon + 1;

    return currentMonth;
}

int Date::getPreviousMonth () {

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int previousMonth = timeinfo->tm_mon;

    return previousMonth;
}

bool Date::isLeapYear (int year) {

    if ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int Date::howManyDaysInMonth(int month, int userYear) {

    int daysInMonth = 0;

    if(month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else if (month == 2) {

        !isLeapYear(userYear) ? daysInMonth = 28 : daysInMonth = 29;
    } else {
        daysInMonth = 31;
    }
    return daysInMonth;
}

string Date::getYearFromInputDate (string date) {

    string yearFromInputDate = "";

    if (date.find('-') != string::npos) {
        size_t dataSeparator = date.find('-');

        yearFromInputDate = date.substr(0, dataSeparator);
    }
    return yearFromInputDate;
}

string Date::getMonthFromInputDate (string date) {

    string monthFromInputDate = "";

    if (date.find('-') != string::npos) {

        monthFromInputDate = date.substr(date.find('-')+1, 2);
    }
    return monthFromInputDate;
}

string Date::getDayFromInputDate (string date) {

    string dayFromInputDate = "";

    if (date.find('-') != string::npos) {
        size_t dataSeparator = date.find_last_of('-');

        dayFromInputDate = date.substr(dataSeparator+1, 2);
    }
    return dayFromInputDate;
}

bool Date::isYearCorrect(string userDate) {

    int userYear = atoi(getYearFromInputDate(userDate).c_str());

    if ((userYear >= 2000) && (userYear <= getCurrentYear())) {
        return true;
    } else {
        return false;
    }
}

bool Date::isMonthCorrect (string userDate) {

    int userMonth = atoi(getMonthFromInputDate(userDate).c_str());
    int userYear = atoi(getYearFromInputDate(userDate).c_str());

    if ((userYear != getCurrentYear()) && (userMonth >= 1) && (userMonth <= 12)) {
        return true;
    } else if ((userYear == getCurrentYear()) && (userMonth <= getCurrentMonth())) {
        return true;
    } else {
        return false;
    }
}

bool Date::isDayCorrect (string userDate) {

    int userDay = atoi(getDayFromInputDate(userDate).c_str());
    int userMonth = atoi(getMonthFromInputDate(userDate).c_str());
    int userYear = atoi(getYearFromInputDate(userDate).c_str());

    if ((userDay >= 1) && (userDay <= howManyDaysInMonth(userMonth, userYear))) {
        return true;
    } else {
        return false;
    }
}

bool Date::isDateCorrect (string userDate) {

    if(isYearCorrect(userDate) && isMonthCorrect(userDate) && isDayCorrect(userDate)) {
        return true;
    } else {
        return false;
    }
}

string Date::inputDate () {

    cout << "Czy data wydatku dotyczy dnia dzisiejszego? " << "t/n" << endl;

    while (true) {
        char wybor = OtherMethods::getCharacter();

        if (wybor == 't' || wybor == 'T') {
            return Date::getCurrentDate();

        } else if (wybor == 'n' || wybor == 'N') {
            cout << "Podaj date wydatku (rrrr-mm-dd) od 2000-01-01 do ostatniego dnia biezacego miesiaca: ";
            string userDate = OtherMethods::getLine();

            if (Date::isDateCorrect(userDate)) {
                return userDate;

            } else {
                do {
                    cout << "Podaj poprawna date: ";
                    userDate = OtherMethods::getLine();
                } while (!Date::isDateCorrect(userDate));
                return userDate;
            }
        }
    }
}

string Date::inputDateForTimePeroid () {

    string userDate = OtherMethods::getLine();

    if (Date::isDateCorrect(userDate)) {
        return userDate;
    } else {
        do {
            cout << "Podaj poprawna date: ";
            userDate = OtherMethods::getLine();
        } while (!Date::isDateCorrect(userDate));
        return userDate;
    }
}

int Date::intDateWithoutSeparators (string stringDateWithSeparators) {

    string stringDateWithoutSeparators = "";
    int intDateWithoutSeparators = 0;

    stringDateWithoutSeparators = stringDateWithSeparators.erase(4,1);
    stringDateWithoutSeparators = stringDateWithSeparators.erase(6,1);

    intDateWithoutSeparators = atoi(stringDateWithoutSeparators.c_str());

    return intDateWithoutSeparators;
}

string Date::stringDateWithSeparators (int intDateWithoutSeparators) {

    string stringDateWithoutSeparators = OtherMethods::convertIntToString(intDateWithoutSeparators);
    string stringDateWithSeparators = "";

    stringDateWithSeparators = (stringDateWithoutSeparators.insert(4, "-"));
    stringDateWithSeparators = (stringDateWithoutSeparators.insert(7, "-"));

    return stringDateWithSeparators;
}

bool Date::dateValidationForCurrentMonthFinancialBalance (string userDate) {

    string userDateToValidate = getYearFromInputDate(userDate);
    userDateToValidate += getMonthFromInputDate(userDate);

    string currentMonthDateToValidate = OtherMethods::convertIntToString(getCurrentYear());
    currentMonthDateToValidate += OtherMethods::convertIntToString(getCurrentMonth());

    if (userDateToValidate == currentMonthDateToValidate) {
        return true;
    } else {
        return false;
    }
}

bool Date::dateValidationForPreviousMonthFinancialBalance (string userDate) {

    string userDateToValidate = getYearFromInputDate(userDate);
    userDateToValidate += getMonthFromInputDate(userDate);

    string previousMonthDateToValidate = OtherMethods::convertIntToString(getCurrentYear());
    previousMonthDateToValidate += OtherMethods::convertIntToString(getPreviousMonth());

    if (userDateToValidate == previousMonthDateToValidate) {
        return true;
    } else {
        return false;
    }
}

bool Date::startDateValidationForTimePeroidFinancialBalance (string dateStart, int dateFromVector) {

    string stringUserDateToValidateStart = getYearFromInputDate(dateStart);
    stringUserDateToValidateStart += getMonthFromInputDate(dateStart);
    stringUserDateToValidateStart += getDayFromInputDate(dateStart);

    int intUserDateToValidateStart = atoi(stringUserDateToValidateStart.c_str());

    if (dateFromVector >= intUserDateToValidateStart) {
        return true;
    } else {
        return false;
    }
}

bool Date::endDateValidationForTimePeroidFinancialBalance (string dateEnd, int dateFromVector) {

    string stringUserDateToValidateEnd = getYearFromInputDate(dateEnd);
    stringUserDateToValidateEnd += getMonthFromInputDate(dateEnd);
    stringUserDateToValidateEnd += getDayFromInputDate(dateEnd);

    int intUserDateToValidateEnd = atoi(stringUserDateToValidateEnd.c_str());

    if (dateFromVector <= intUserDateToValidateEnd) {
        return true;
    } else {
        return false;
    }
}

bool Date::compareDates(string dateStart, string dateEnd) {

    string stringUserDateToValidateStart = getYearFromInputDate(dateStart);
    stringUserDateToValidateStart += getMonthFromInputDate(dateStart);
    stringUserDateToValidateStart += getDayFromInputDate(dateStart);

    int intUserDateToValidateStart = atoi(stringUserDateToValidateStart.c_str());

    string stringUserDateToValidateEnd = getYearFromInputDate(dateEnd);
    stringUserDateToValidateEnd += getMonthFromInputDate(dateEnd);
    stringUserDateToValidateEnd += getDayFromInputDate(dateEnd);

    int intUserDateToValidateEnd = atoi(stringUserDateToValidateEnd.c_str());

    if (intUserDateToValidateStart <= intUserDateToValidateEnd) {
        return true;
    } else {
        cout << "Koniec przedzialu to data wczesniejsza niz poczatek! Podaj daty jeszcze raz.\n\n";
        return false;
    }
}
