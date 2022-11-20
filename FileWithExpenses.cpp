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
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", OtherMethods::convertFloatToString(expense.getAmount())); // zmienic niech float prosto laduje

    xml.Save("expenses.xml");
}

vector<Expense> FileWithExpenses::loadExpensesFromFile() {

Expense expense;
    vector<Expense> expenses;

    CMarkup xml;

    xml.Load( "expenses.xml" );

    xml.FindElem(); // root OPERATIONS element
    xml.IntoElem(); // inside OPERATIONS
    while ( xml.FindElem("Expense") ) {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        expense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("UserId");
        expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Date");
        expense.setDate(xml.GetData());
        xml.FindElem("Item");
        expense.setItem(xml.GetData());
        xml.FindElem("Amount");
        expense.setAmount(OtherMethods::convertStringToFloat(xml.GetData()));
        xml.OutOfElem();

        expenses.push_back(expense);
    }
    return expenses;
}
