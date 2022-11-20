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
    static string getNumberFromString(string text, int charPosition);
    static int convertStringToInt(string strNumber);
    static int getInteger();
    static float getFloat();
    static char choseFromMainMenu();
    static char choseFromUserMenu();
    static char getCharacter();
    static float getFloatNumberForCashAmount();
    static string changeCommaToDot (string strNumber);
    static float convertStringToFloat(string strNumber);
    static string convertFloatToString(float floatNumber);
};

#endif // OTHERMETHODS_H
