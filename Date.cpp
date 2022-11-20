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

/*int Date::getCurrentDay () {

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int currentDay = timeinfo->tm_mday;

    return currentDay;
}

void Date::showCurrentDate () {

    cout << getCurrentDate() << endl;
}

int Date::getPreviousMonth () {

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int previousMonth = timeinfo->tm_mon;

    return previousMonth;
}

string Date::getFullDatePreviousMonth () {

    time_t rawtime;
    struct tm * timeinfo;

    string fullDatePreviousMonth = "";

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    int day = timeinfo->tm_mday;
    int month = timeinfo->tm_mon;
    int year = timeinfo->tm_year + 1900;

    fullDatePreviousMonth = to_string(year) + "-" + to_string(month) + "-" + to_string(day);

    return fullDatePreviousMonth;
}*/

bool Date::isLeapYear (int year) {

    if ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int Date::howManyDaysInMonth(int month) {

    int daysInMonth = 0;

    if(month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else if (month == 2) {

        !isLeapYear(getCurrentYear()) ? daysInMonth = 28 : daysInMonth = 29;
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

/*void Date::compareYears (string date1, string date2) {

    if (getYearFromInputDate(date1) > getYearFromInputDate(date2)) {
        cout << "Data 1 jest wczesniejsza niz data 2" << endl;
    } else {
        cout << "Data 2 jest wczesniejsza niz data 1" << endl;
    }
}*/

string Date::getMonthFromInputDate (string date) {

    string monthFromInputDate = "";

    if (date.find('-') != string::npos) {

        monthFromInputDate = date.substr(date.find('-')+1, 2);
    }
    return monthFromInputDate;
}

/*void Date::compareMonths (string date1, string date2) {

    if (getMonthFromInputDate(date1) > getMonthFromInputDate(date2)) {
        cout << "Data 1 jest wczesniejsza niz data 2" << endl;
    } else {
        cout << "Data 2 jest wczesniejsza niz data 1" << endl;
    }
}*/

string Date::getDayFromInputDate (string date) {

    string dayFromInputDate = "";

    if (date.find('-') != string::npos) {
        size_t dataSeparator = date.find_last_of('-');

        dayFromInputDate = date.substr(dataSeparator+1, 2);
    }
    return dayFromInputDate;
}

/*void Date::compareDays (string date1, string date2) {

    if (getDayFromInputDate(date1) > getDayFromInputDate(date2)) {
        cout << "Data 1 jest wczesniejsza niz data 2" << endl;
    } else {
        cout << "Data 2 jest wczesniejsza niz data 1" << endl;
    }
}

void Date::compareDates() {

    string date1 = "", date2 = "";

    cout << "Podaj pierwsza date do porownania rrrr-mm-dd: ";
    date1 = getLine();

    cout << "Podaj druga date do porownania rrrr-mm-dd: ";
    date2 = getLine();

    if (getYearFromInputDate(date1) != getYearFromInputDate(date2)) {

        compareYears(date1, date2);
    } else if (getMonthFromInputDate(date1) != getMonthFromInputDate(date2)) {

        compareMonths(date1, date2);
    } else if (getDayFromInputDate(date1) != getDayFromInputDate(date2)) {

        compareDays(date1, date2);
    } else {
        cout << "Podane daty sa takie same" << endl;
    }
}*/

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

    if ((userDay >= 1) && (userDay <= howManyDaysInMonth(userMonth))) {
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

/*int Date::convertStringDateToIntDate (string stringDateWithSeparators) {

    string stringDateWithoutSeparators = "";
    int intDate = 0;

    stringDateWithoutSeparators = OtherMethods::convertIntToString(getYearFromInputDate(stringDateWithSeparators));
    stringDateWithoutSeparators += OtherMethods::convertIntToString(getMonthFromInputDate(stringDateWithSeparators));
    stringDateWithoutSeparators += OtherMethods::convertIntToString(getDayFromInputDate(stringDateWithSeparators));

    cout << stringDateWithoutSeparators << endl;

}*/

string Date::stringDateWithoutSeparators (string stringDateWithSeparators) {

    string stringDateWithoutSeparators = "";

    stringDateWithoutSeparators = getYearFromInputDate(stringDateWithSeparators)
    + getMonthFromInputDate(stringDateWithSeparators)
    + getDayFromInputDate(stringDateWithSeparators);
    //stringDateWithoutSeparators += getMonthFromInputDate(stringDateWithSeparators);
    //stringDateWithoutSeparators += getDayFromInputDate(stringDateWithSeparators);

    return stringDateWithoutSeparators;
}
