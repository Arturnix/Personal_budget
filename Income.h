#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {

    int incomeId;
    int userId;
    string date;
    string item;
    float amount;

public:

    void setIncomeId (int newIncomeId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getIncomeId ();
    int getUserId ();
    string getDate ();
    string getItem ();
    float getAmount ();
};

#endif // INCOME_H
