#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {

    int expenseId;
    int userId;
    int date;
    string item;
    float amount;

public:

    void setExpenseId (int newExpenseId);
    void setUserId (int newUserId);
    void setDate (int newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getExpenseId ();
    int getUserId ();
    int getDate ();
    string getItem ();
    float getAmount ();
};

#endif // EXPENSE_H
