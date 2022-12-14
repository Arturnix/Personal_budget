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

    expense.setExpenseId(FileWithExpenses::setLastExpenseId());
    expense.setUserId(LOGGED_USER_ID);

    cout << "Podaj date wydatku. " << endl;
    expense.setDate(Date::intDateWithoutSeparators(Date::inputDate()));

    cout << "Podaj kategorie wydatku: ";
    expense.setItem(OtherMethods::getLine());

    cout << "Podaj kwote wydatku: ";
    expense.setAmount(OtherMethods::getFloatNumberForCashAmount());

    return expense;
}

vector<Expense> ExpenseManager::sortVectorByDate (vector<Expense>& expenses) {

    sort(expenses.begin(), expenses.end(), [](Expense& lhs, Expense& rhs) {
        return lhs.getDate() < rhs.getDate();
    });
    return expenses;
}

void ExpenseManager::displayExpensesTitle () {
    cout << "Wydatki: " << endl;
    cout << "---------------------------------------" << endl;
}

void ExpenseManager::showExpenseDetails (Expense expense) {
    cout << "Numer wydatku: " << expense.getExpenseId() << endl;
    cout << "Data wydatku: " << Date::stringDateWithSeparators(expense.getDate()) << endl;
    cout << "Cel wydatku: " << expense.getItem() << endl;
    cout << "Kwota wydatku: " << expense.getAmount() << " zl\n\n";
}

float ExpenseManager::totalExpensesOfLoggedUserCurrentMonth () {
    float totalExpenses = 0.00;

    for (vector<Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if(Date::dateValidationForCurrentMonthFinancialBalance(Date::stringDateWithSeparators(itr -> getDate()))) {
            totalExpenses += itr -> getAmount();
        }
    }
    return totalExpenses;
}

void ExpenseManager::showAllExpensesOfLoggedUserCurrentMonth() {
    displayExpensesTitle();
    if (expenses.size() == 0) {
        cout << "Brak wydatkow do wyswietlenia!" << "\n\n";
    } else {
        sortVectorByDate (expenses);
        for (vector<Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (Date::dateValidationForCurrentMonthFinancialBalance(Date::stringDateWithSeparators(itr -> getDate()))) {
                showExpenseDetails(*itr);
            }
        }
        cout << "Calkowita kwota wydatkow w danym okresie: " << fixed << setprecision(2) << totalExpensesOfLoggedUserCurrentMonth() << " zl\n\n";
    }
}

float ExpenseManager::totalExpensesOfLoggedUserPreviousMonth () {
    float totalExpenses = 0.00;

    for (vector<Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if(Date::dateValidationForPreviousMonthFinancialBalance(Date::stringDateWithSeparators( itr -> getDate()))) {
            totalExpenses +=  itr -> getAmount();
        }
    }
    return totalExpenses;
}

void ExpenseManager::showAllExpensesOfLoggedUserPreviousMonth() {
    displayExpensesTitle();
    if (expenses.size() == 0) {
        cout << "Brak wydatkow do wyswietlenia!" << "\n\n";
    } else {
        sortVectorByDate (expenses);
        for (vector<Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (Date::dateValidationForPreviousMonthFinancialBalance(Date::stringDateWithSeparators(itr -> getDate()))) {
                showExpenseDetails(*itr);
            }
        }
        cout << "Calkowita kwota wydatkow w danym okresie: " << fixed << setprecision(2) << totalExpensesOfLoggedUserPreviousMonth() << " zl\n\n";
    }
}

float ExpenseManager::totalExpensesOfLoggedUserTimePeroid (string dateStart, string dateEnd) {
    float totalExpenses = 0.00;

    for (vector<Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
        if(Date::startDateValidationForTimePeroidFinancialBalance(dateStart, itr -> getDate())
                && Date::endDateValidationForTimePeroidFinancialBalance(dateEnd, itr -> getDate())) {
            totalExpenses += itr -> getAmount();
        }
    }
    return totalExpenses;
}

void ExpenseManager::showAllExpensesOfLoggedUserTimePeroid(string dateStart, string dateEnd) {
    displayExpensesTitle();
    if (expenses.size() == 0) {
        cout << "Brak wydatkow do wyswietlenia!" << "\n\n";
    } else {
        sortVectorByDate (expenses);
        for (vector<Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (Date::startDateValidationForTimePeroidFinancialBalance(dateStart, itr -> getDate())
                    && Date::endDateValidationForTimePeroidFinancialBalance(dateEnd, itr -> getDate())) {
                showExpenseDetails(*itr);
            }
        }
        cout << "Calkowita kwota wydatkow w danym okresie: " << fixed << setprecision(2) << totalExpensesOfLoggedUserTimePeroid(dateStart, dateEnd) << " zl\n\n";
    }
}
