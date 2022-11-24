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

    income.setIncomeId(FileWithIncomes::setLastIncomeId());
    income.setUserId(LOGGED_USER_ID);

    cout << "Podaj date przychodu. " << endl;
    income.setDate(Date::intDateWithoutSeparators(Date::inputDate()));

    cout << "Podaj kategorie przychodu: ";
    income.setItem(OtherMethods::getLine());

    cout << "Podaj kwote przychodu: ";
    income.setAmount(OtherMethods::getFloatNumberForCashAmount());

    return income;
}

vector<Income> IncomeManager::sortVectorByDate (vector<Income>& incomes) {

    sort(incomes.begin(), incomes.end(), [](Income& lhs, Income& rhs) {
        return lhs.getDate() < rhs.getDate();
    });
    return incomes;
}

void IncomeManager::displayIncomesTitle () {
    system("cls");
    cout << "Przychody: " << endl;
    cout << "---------------------------------------" << endl;
}

void IncomeManager::showIncomeDetails (Income income) {
    cout << "Numer przychodu: " << income.getIncomeId() << endl;
    cout << "Data przychodu: " << Date::stringDateWithSeparators(income.getDate()) << endl;
    cout << "Zrodlo przychodu: " << income.getItem() << endl;
    cout << "Kwota przychodu: " << income.getAmount() << " zl\n\n";
}

float IncomeManager::totalIncomesOfLoggedUserCurrentMonth () {
    float totalIncomes = 0.00;

    for (vector<Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(Date::dateValidationForCurrentMonthFinancialBalance(Date::stringDateWithSeparators(itr -> getDate()))) {
            totalIncomes += itr -> getAmount();
        }
    }
    return totalIncomes;
}

void IncomeManager::showAllIncomesOfLoggedUserCurrentMonth() {
    displayIncomesTitle();
    if (incomes.size() == 0) {
        cout << "Brak przychodow do wyswietlenia!" << "\n\n";
    } else {
        sortVectorByDate (incomes);
        for (vector<Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (Date::dateValidationForCurrentMonthFinancialBalance(Date::stringDateWithSeparators(itr -> getDate()))) {
                showIncomeDetails(*itr);
            }
        }
        cout << "Calkowita kwota przychodow w danym okresie: " << fixed << setprecision(2) << totalIncomesOfLoggedUserCurrentMonth() << " zl\n\n";
    }
}

float IncomeManager::totalIncomesOfLoggedUserPreviousMonth () {
    float totalIncomes = 0.00;

    for (vector<Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(Date::dateValidationForPreviousMonthFinancialBalance(Date::stringDateWithSeparators( itr -> getDate()))) {
            totalIncomes +=  itr -> getAmount();
        }
    }
    return totalIncomes;
}

void IncomeManager::showAllIncomesOfLoggedUserPreviousMonth() {
    displayIncomesTitle();
    if (incomes.size() == 0) {
        cout << "Brak przychodow do wyswietlenia!" << "\n\n";
    } else {
        sortVectorByDate (incomes);
        for (vector<Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (Date::dateValidationForPreviousMonthFinancialBalance(Date::stringDateWithSeparators(itr -> getDate()))) {
                showIncomeDetails(*itr);
            }
        }
        cout << "Calkowita kwota przychodow w danym okresie: " << fixed << setprecision(2) << totalIncomesOfLoggedUserPreviousMonth() << " zl\n\n";
    }
}

float IncomeManager::totalIncomesOfLoggedUserTimePeroid (string dateStart, string dateEnd) {
    float totalIncomes = 0.00;

    for (vector<Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
        if(Date::startDateValidationForTimePeroidFinancialBalance(dateStart, itr -> getDate())
                && Date::endDateValidationForTimePeroidFinancialBalance(dateEnd, itr -> getDate())) {
            totalIncomes += itr -> getAmount();
        }
    }
    return totalIncomes;
}

void IncomeManager::showAllIncomesOfLoggedUserTimePeroid(string dateStart, string dateEnd) {
    displayIncomesTitle();
    if (incomes.size() == 0) {
        cout << "Brak przychodow do wyswietlenia!" << "\n\n";
    } else {
        sortVectorByDate (incomes);
        for (vector<Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (Date::startDateValidationForTimePeroidFinancialBalance(dateStart, itr -> getDate())
                    && Date::endDateValidationForTimePeroidFinancialBalance(dateEnd, itr -> getDate())) {
                showIncomeDetails(*itr);
            }
        }
        cout << "Calkowita kwota przychodow w danym okresie: " << fixed << setprecision(2) << totalIncomesOfLoggedUserTimePeroid(dateStart, dateEnd) << " zl\n\n";
    }
}
