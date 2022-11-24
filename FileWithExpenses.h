#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "DataFile.h"
#include "Expense.h"
#include "Markup.h"
#include "OtherMethods.h"
#include "Date.h"

using namespace std;

class FileWithExpenses : public DataFile {

public:
    FileWithExpenses (string fileName) : DataFile (fileName) {};
    void addExpenseToFile (Expense expense);
    vector<Expense> loadExpensesFromFile (int loggedUserId);
    static int setLastExpenseId();
};

#endif // FILEWITHEXPENSES_H
