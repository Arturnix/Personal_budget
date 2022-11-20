#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "FileWithIncomes.h"
#include "OtherMethods.h"
#include "Date.h"
#include "UserManager.h"

using namespace std;

class IncomeManager {

    vector<Income> incomes;
    Income enterDataOfNewIncome();
    FileWithIncomes fileWithIncomes;
    const int LOGGED_USER_ID;

public:
    IncomeManager (string fileName, int loggedUserId)
    : fileWithIncomes(fileName), LOGGED_USER_ID(loggedUserId) {
    incomes = fileWithIncomes.loadIncomesFromFile();
    };

    void addIncome ();
    int getNewIncomeId ();
    void showAllIncomes ();
};

#endif // INCOMEMANAGER_H
