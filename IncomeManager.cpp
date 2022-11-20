#include "IncomeManager.h"

void IncomeManager::addIncome () {
    Income income;

    income = enterDataOfNewIncome ();
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);

    cout << "Dodano przychod." << endl << endl;
    system("pause");
}

Income IncomeManager::enterDataOfNewIncome () {
    Income income;

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_USER_ID);

    cout << "Podaj date przychodu. " << endl;
    income.setDate(Date::inputDate());

    cout << "Podaj kategorie przychodu: ";
    income.setItem(OtherMethods::getLine());

    cout << "Podaj kwote przychodu: ";
    income.setAmount(OtherMethods::getFloatNumberForCashAmount());

    return income;
}

int IncomeManager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void IncomeManager::showAllIncomes() {

system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
cout << "Przychody: " << endl;
cout << "---------------------------------------" << endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

 if (incomes.size() == 0) {
        cout << "Wektor jest pusty. Brak danych do wyswietlenia!" << endl << endl;
    } else {
        for (int i = 0; i < (int)incomes.size(); i++) {
            cout << "IncomeId: " << incomes[i].getIncomeId() << endl;
            cout << "UserId: " << incomes[i].getUserId() << endl;
            cout << "Date: " << incomes[i].getDate() << endl;
            cout << "Item: " << incomes[i].getItem() << endl;
            cout << "Amount: " << incomes[i].getAmount() << endl << endl;
        }
    }
}
