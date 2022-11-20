#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "DataFile.h"
#include "Expense.h"
#include "Markup.h"
#include "OtherMethods.h"

using namespace std;

class FileWithExpenses : public DataFile {

public:
    FileWithExpenses (string fileName) : DataFile (fileName) {};
    void addExpenseToFile (Expense expense);
    vector<Expense> loadExpensesFromFile ();
    void saveAllExpensesInFile (); //czy potrzebne? chyba nie bo nie edycji tych obiektow
};

#endif // FILEWITHEXPENSES_H
