#include "BudgetManager.h"

void BudgetManager::userRegistration() {
    userManager.userRegistration();
}

void BudgetManager::userLogging() {
    userManager.userLogging();
    if(userManager.isUserLoggedIn()) {
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

void BudgetManager::addIncome() {
    if(!isUserLoggedIn()) {
        cout <<"Aby dodac przychod nalezy sie najpierw zalogowac!\n\n";
    } else {
        incomeManager -> addIncome();
    }
}

void BudgetManager::addExpense() {
    if(!isUserLoggedIn()) {
        cout <<"Aby dodac wydatek nalezy sie najpierw zalogowac!\n\n";
    } else {
        expenseManager -> addExpense();
    }
}

void BudgetManager::displayBalanceTitle() {
    cout << "Bilans: " << endl;
    cout << "---------------------------------------" << endl;
}

float BudgetManager::calculateFinancialBalanceCurrentMonth () {

    float totalFinancialBalance = 0.00;
    totalFinancialBalance = (incomeManager ->totalIncomesOfLoggedUserCurrentMonth() - expenseManager->totalExpensesOfLoggedUserCurrentMonth());

    return totalFinancialBalance;
}
void BudgetManager::showFinancialBalanceCurrentMonth() {
    if(!isUserLoggedIn()) {
        cout << "Aby wyswielic bilans nalezy sie najpierw zalogowac!\n\n";
    } else {
        incomeManager -> showAllIncomesOfLoggedUserCurrentMonth();
        expenseManager -> showAllExpensesOfLoggedUserCurrentMonth();
        displayBalanceTitle();
        cout << "Bilans finansowy w danym okresie: " << fixed << setprecision(2) <<
             calculateFinancialBalanceCurrentMonth() << " zl\n\n";
    }
    system("pause");
}

float BudgetManager::calculateFinancialBalancePreviousMonth () {

    float totalFinancialBalance = 0.00;
    totalFinancialBalance = (incomeManager ->totalIncomesOfLoggedUserPreviousMonth() - expenseManager->totalExpensesOfLoggedUserPreviousMonth());

    return totalFinancialBalance;
}

void BudgetManager::showFinancialBalancePreviousMonth() {
    if(!isUserLoggedIn()) {
        cout << "Aby wyswielic bilans nalezy sie najpierw zalogowac!\n\n";
    } else {
        incomeManager -> showAllIncomesOfLoggedUserPreviousMonth();
        expenseManager -> showAllExpensesOfLoggedUserPreviousMonth();
        displayBalanceTitle();
        cout << "Bilans finansowy w danym okresie: " << fixed << setprecision(2) <<
             calculateFinancialBalancePreviousMonth () << " zl\n\n";
    }
    system("pause");
}

float BudgetManager::calculateFinancialBalanceTimePeroid (string dateStart, string dateEnd) {

    float totalFinancialBalance = 0.00;
    totalFinancialBalance = (incomeManager ->totalIncomesOfLoggedUserTimePeroid(dateStart, dateEnd) -
                             expenseManager->totalExpensesOfLoggedUserTimePeroid(dateStart, dateEnd));

    return totalFinancialBalance;
}

void BudgetManager::showFinancialBalanceTimePeroid() {
    if(!isUserLoggedIn()) {
        cout << "Aby wyswielic bilans nalezy sie najpierw zalogowac!\n\n";
    } else {
        string dateStart = "",  dateEnd = "";

        cout << "Podaj poczatek okresu, dla ktorego ma zostac wyswietlony bilans (w formacie rrrr-mm-dd):  \n";
        dateStart = Date::inputDateForTimePeroid();

        cout << "Podaj koniec okresu, dla ktorego ma zostac wyswietlony bilans (w formacie rrrr-mm-dd):  \n";
        dateEnd = Date::inputDateForTimePeroid();

        incomeManager -> showAllIncomesOfLoggedUserTimePeroid(dateStart, dateEnd);
        expenseManager -> showAllExpensesOfLoggedUserTimePeroid(dateStart, dateEnd);
        displayBalanceTitle();
        cout << "Bilans finansowy w danym okresie: " << fixed << setprecision(2) <<
             calculateFinancialBalanceTimePeroid(dateStart, dateEnd) << " zl\n\n";
    }
    system("pause");
}

char BudgetManager::menuInterface() {
    if(!isUserLoggedIn()) {
        return OtherMethods::choseFromMainMenu();
    } else {
        return OtherMethods::choseFromUserMenu();
    }
}
