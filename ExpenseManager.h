#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "FileWithExpenses.h"
#include "OtherMethods.h"
#include "Date.h"
#include "UserManager.h"

using namespace std;

class ExpenseManager {

    vector<Expense> expenses;
    Expense enterDataOfNewExpense();
    FileWithExpenses fileWithExpenses;
    const int LOGGED_USER_ID;

public:
    ExpenseManager (string fileName, int loggedUserId)
    : fileWithExpenses(fileName), LOGGED_USER_ID(loggedUserId) {
    expenses = fileWithExpenses.loadExpensesFromFile();
    };

    void addExpense ();
    int getNewExpenseId ();
    void showAllExpenses ();
};

#endif // EXPENSEMANAGER_H
