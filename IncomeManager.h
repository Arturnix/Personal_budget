#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "Income.h"
#include "FileWithIncomes.h"
#include "OtherMethods.h"
#include "Date.h"

using namespace std;

class IncomeManager {

    vector<Income> incomes;
    FileWithIncomes fileWithIncomes;
    const int LOGGED_USER_ID;

    Income enterDataOfNewIncome();
    int getNewIncomeId ();
    vector<Income> sortVectorByDate (vector<Income>& incomes);
    void displayIncomesTitle ();
    void showIncomeDetails (Income income);
    float totalIncomesOfLoggedUserCurrentMonth ();
    float totalIncomesOfLoggedUserPreviousMonth ();
    float totalIncomesOfLoggedUserTimePeroid (string dateStart, string dateEnd);
    void showAllIncomesOfLoggedUserTimePeroid (string dateStart, string dateEnd);


public:
    IncomeManager (string fileName, int loggedUserId)
    : fileWithIncomes(fileName), LOGGED_USER_ID(loggedUserId) {
    incomes = fileWithIncomes.loadIncomesFromFile(loggedUserId);
    };

    void addIncome ();
    void showAllIncomesOfLoggedUserCurrentMonth();
    void showAllIncomesOfLoggedUserPreviousMonth();
    void setTimePeroidToShowFinancialBalance ();
};

#endif // INCOMEMANAGER_H
