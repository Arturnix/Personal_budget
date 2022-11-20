#include <iostream>
#include <cstdlib>

#include "UserManager.h"
#include "OtherMethods.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "Date.h"

using namespace std;

int main()
{
    UserManager user("users.xml");
    IncomeManager* income;
    ExpenseManager* expense;

    while (true) {
        if (!user.isUserLoggedIn()) {

            switch (OtherMethods::choseFromMainMenu()) {
            case '1':
                user.userRegistration();
                break;
            case '2':
                user.userLogging();
                if (user.isUserLoggedIn()) {
                    income = new IncomeManager ("incomes.xml", user.getLoggedUserId());
                    expense = new ExpenseManager ("expenses.xml", user.getLoggedUserId()); //doopisac dla expense + nowy obiekt new
                }
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

            switch (OtherMethods::choseFromUserMenu()) {
            case '1':
                income -> addIncome();
                break;
            case '2':
                expense -> addExpense();
                break;
            case '3':
                income -> showAllIncomes();
                expense -> showAllExpenses();
                Sleep(6000);
                break;
            case '4':

                break;
            case '5':

                break;
            case '6':
                user.changePasswordOfLoggedUser();
                break;
            case '7':
                user.logoutUser();
                break;
            }
        }
    }

    return 0;
}
