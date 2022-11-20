#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile (Income income) {

CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", OtherMethods::convertFloatToString(income.getAmount())); // zmienic niech float prosto laduje

    xml.Save("incomes.xml");
}

vector<Income> FileWithIncomes::loadIncomesFromFile() {

Income income;
    vector<Income> incomes;

    CMarkup xml;

    xml.Load( "incomes.xml" );

    xml.FindElem(); // root OPERATIONS element
    xml.IntoElem(); // inside OPERATIONS
    while ( xml.FindElem("Income") ) {
        xml.IntoElem();
        xml.FindElem("IncomeId");
        income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("UserId");
        income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Date");
        income.setDate(xml.GetData());
        xml.FindElem("Item");
        income.setItem(xml.GetData());
        xml.FindElem("Amount");
        income.setAmount(OtherMethods::convertStringToFloat(xml.GetData()));
        xml.OutOfElem();

        incomes.push_back(income);
    }
    return incomes;
}
