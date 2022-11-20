#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "DataFile.h"
#include "Income.h"
#include "Markup.h"
#include "OtherMethods.h"

using namespace std;

class FileWithIncomes : public DataFile {

public:
    FileWithIncomes (string fileName) : DataFile (fileName) {};
    void addIncomeToFile (Income income);
    vector<Income> loadIncomesFromFile ();
    void saveAllIncomesInFile ();
};

#endif // FILEWITHINCOMES_H
