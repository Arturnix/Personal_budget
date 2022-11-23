#include <iostream>
#include <cstdlib>

#include "BudgetManager.h"

using namespace std;

int main()
{
    BudgetManager budgetManager("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (!budgetManager.isUserLoggedIn()) {

            switch (budgetManager.menuInterface()) {
            case '1':
                budgetManager.userRegistration();
                break;
            case '2':
                budgetManager.userLogging();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            switch (budgetManager.menuInterface()) {
            case '1':
                budgetManager.addIncome();
                break;
            case '2':
                budgetManager.addExpense();
                break;
            case '3':
                budgetManager.showFinancialBalanceCurrentMonth();
                break;
            case '4':
                budgetManager.showFinancialBalancePreviousMonth();
                break;
            case '5':
                budgetManager.showFinancialBalanceTimePeroid();
                break;
            case '6':
                budgetManager.changePasswordOfLoggedUser();
                break;
            case '7':
                budgetManager.logoutUser();
                break;
            }
        }
    }
    return 0;
}
