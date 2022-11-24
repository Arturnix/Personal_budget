#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile (Expense expense) {

    CMarkup xml;

    bool fileExists = xml.Load( "expenses.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", Date::stringDateWithSeparators(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", OtherMethods::convertFloatToString(expense.getAmount()));

    xml.Save("expenses.xml");
}

vector<Expense> FileWithExpenses::loadExpensesFromFile(int loggedUserId) {

    Expense expense;
    vector<Expense> expenses;

    CMarkup xml;

    xml.Load( "expenses.xml" );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") ) {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        expense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("UserId");
        expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        if (expense.getUserId() == loggedUserId) {
            xml.FindElem("Date");
            string stringDateWithoutSeparators = xml.GetData();
            expense.setDate(Date::intDateWithoutSeparators(stringDateWithoutSeparators));
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(OtherMethods::convertStringToFloat(xml.GetData()));

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}

int FileWithExpenses::setLastExpenseId() {

    int lastExpenseId = 0;

    CMarkup xml;

    xml.Load( "expenses.xml" );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") ) {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        lastExpenseId = atoi(MCD_2PCSZ(xml.GetData()));
        xml.OutOfElem();
    }
    return lastExpenseId+1;
}
