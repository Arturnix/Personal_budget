#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>

#include "UserManager.h"
#include "OtherMethods.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class BudgetManager {

    UserManager userManager;
    IncomeManager* incomeManager;
    const string NAME_FILE_WITH_INCOMES;
    ExpenseManager* expenseManager;
    const string NAME_FILE_WITH_EXPENSES;

public:
    BudgetManager(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses)
    : userManager (nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses) {
    incomeManager = NULL;
    expenseManager = NULL;
    };
    ~BudgetManager() {
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
    };
    void userRegistration();
    void userLogging();
    bool isUserLoggedIn();
    void changePasswordOfLoggedUser();
    void logoutUser();
    void addIncome();
    void addExpense();
    void showFinancialBalanceCurrentMonth();
    void showFinancialBalancePreviousMonth();
    void showFinancialBalanceTimePeroid();
    char menuInterface();

};

#endif // BUDGETMANAGER_H
