#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "Expense.h"
#include "FileWithExpenses.h"
#include "OtherMethods.h"
#include "Date.h"

using namespace std;

class ExpenseManager {

    vector<Expense> expenses;
    FileWithExpenses fileWithExpenses;
    const int LOGGED_USER_ID;

    Expense enterDataOfNewExpense();
    int getNewExpenseId ();
    vector<Expense> sortVectorByDate (vector<Expense>& expenses);
    void displayExpensesTitle ();
    void showExpenseDetails (Expense expense);
    float totalExpensesOfLoggedUserCurrentMonth ();
    float totalExpensesOfLoggedUserPreviousMonth ();
    float totalExpensesOfLoggedUserTimePeroid (string dateStart, string dateEnd);
    void showAllExpensesOfLoggedUserTimePeroid (string dateStart, string dateEnd);

public:
    ExpenseManager (string fileName, int loggedUserId)
    : fileWithExpenses(fileName), LOGGED_USER_ID(loggedUserId) {
    expenses = fileWithExpenses.loadExpensesFromFile(loggedUserId);
    };

    void addExpense ();
    void showAllExpensesOfLoggedUserCurrentMonth();
    void showAllExpensesOfLoggedUserPreviousMonth();
    void setTimePeroidToShowFinancialBalance ();
};

#endif // EXPENSEMANAGER_H
