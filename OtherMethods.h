#ifndef OTHERMETHODS_H
#define OTHERMETHODS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class OtherMethods {

public:
    static string getLine();
    static string convertIntToString(int intNumber);
    static string swapFirstLetterToUppercaseRemainedToLowercase(string text);
    static string getNumber(string text, int charPosition);
    static int convertStringToInt(string strNumber);
    static int getInteger();
    static char choseFromMainMenu();
    static char choseFromUserMenu();
    static char getCharacter();
};

#endif // OTHERMETHODS_H
