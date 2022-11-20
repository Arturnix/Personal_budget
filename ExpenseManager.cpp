#include "ExpenseManager.h"

void ExpenseManager::addExpense () {
    Expense expense;

    expense = enterDataOfNewExpense ();
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);

    cout << "Dodano wydatek." << endl << endl;
    system("pause");
}

Expense ExpenseManager::enterDataOfNewExpense () {
    Expense expense;

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_USER_ID);

    cout << "Podaj date wydatku. " << endl;
    expense.setDate(Date::inputDate());

    cout << "Podaj kategorie wydatku: ";
    expense.setItem(OtherMethods::getLine());

    cout << "Podaj kwote wydatku: ";
    expense.setAmount(OtherMethods::getFloatNumberForCashAmount());

    return expense;
}

int ExpenseManager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

void ExpenseManager::showAllExpenses() {

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
cout << "Wydatki: " << endl;
cout << "---------------------------------------" << endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

 if (expenses.size() == 0) {
        cout << "Wektor jest pusty. Brak danych do wyswietlenia!" << endl << endl;
    } else {
        for (int i = 0; i < (int)expenses.size(); i++) {
            cout << "ExpenseId: " << expenses[i].getExpenseId() << endl;
            cout << "UserId: " << expenses[i].getUserId() << endl;
            cout << "Date: " << expenses[i].getDate() << endl;
            cout << "Item: " << expenses[i].getItem() << endl;
            cout << "Amount: " << expenses[i].getAmount() << endl << endl;
        }
    }
}
