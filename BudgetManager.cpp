#include "BudgetManager.h"

void BudgetManager::userRegistration() {
    userManager.userRegistration();
}

void BudgetManager::userLogging() {
    userManager.userLogging();
    if(userManager.isUserLoggedIn()){
        incomeManager = new IncomeManager(NAME_FILE_WITH_INCOMES, userManager.getLoggedUserId());
        expenseManager = new ExpenseManager(NAME_FILE_WITH_EXPENSES, userManager.getLoggedUserId());
    }
}

bool BudgetManager::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

void BudgetManager::changePasswordOfLoggedUser() {
    if (!isUserLoggedIn()) {
        cout << "Aby zmienic haslo nalezy sie najpierw zalogowac!\n\n";
    } else {
        userManager.changePasswordOfLoggedUser();
    }
}

void BudgetManager::logoutUser() {
    userManager.logoutUser();
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
}

void BudgetManager::addIncome(){
    if(!isUserLoggedIn()){
        cout <<"Aby dodac przychod nalezy sie najpierw zalogowac!\n\n";
    } else {
        incomeManager -> addIncome();
    }
}

void BudgetManager::addExpense(){
    if(!isUserLoggedIn()) {
        cout <<"Aby dodac wydatek nalezy sie najpierw zalogowac!\n\n";
    } else {
        expenseManager -> addExpense();
    }
}

void BudgetManager::showFinancialBalanceCurrentMonth() {
    if(!isUserLoggedIn()) {
        cout << "Aby wyswielic bilans nalezy sie najpierw zalogowac!\n\n";
    } else {
      incomeManager -> showAllIncomesOfLoggedUserCurrentMonth();
      expenseManager -> showAllExpensesOfLoggedUserCurrentMonth();
    }
    system("pause");
}

void BudgetManager::showFinancialBalancePreviousMonth() {
    if(!isUserLoggedIn()) {
        cout << "Aby wyswielic bilans nalezy sie najpierw zalogowac!\n\n";
    } else {
      incomeManager -> showAllIncomesOfLoggedUserPreviousMonth();
      expenseManager -> showAllExpensesOfLoggedUserPreviousMonth();
    }
}

void BudgetManager::showFinancialBalanceTimePeroid() {
    if(!isUserLoggedIn()) {
        cout << "Aby wyswielic bilans nalezy sie najpierw zalogowac!\n\n";
    } else {
      incomeManager -> setTimePeroidToShowFinancialBalance();
      expenseManager -> setTimePeroidToShowFinancialBalance();
    }
}

char BudgetManager::menuInterface() {
    if(!isUserLoggedIn()) {
       return OtherMethods::choseFromMainMenu();
    } else {
        return OtherMethods::choseFromUserMenu();
    }
}
