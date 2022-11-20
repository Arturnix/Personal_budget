#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {

    int expenseId;
    int userId;
    string date;
    string item;
    float amount;

public:

    void setExpenseId (int newExpenseId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getExpenseId ();
    int getUserId ();
    string getDate ();
    string getItem ();
    float getAmount ();
};

#endif // EXPENSE_H
