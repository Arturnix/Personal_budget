#include "OtherMethods.h"

string OtherMethods::getLine() {
    string inputString = "";
    getline(cin, inputString);
    return inputString;
}

string OtherMethods::convertIntToString(int intNumber) {
    ostringstream ss;
    ss << intNumber;
    string str = ss.str();
    return str;
}

string OtherMethods::swapFirstLetterToUppercaseRemainedToLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int OtherMethods::convertStringToInt(string strNumber) {
    int intNumber;
    istringstream iss(strNumber);
    iss >> intNumber;

    return intNumber;
}

string OtherMethods::getNumberFromString(string text, int charPosition) {
    string strNumber = "";
    while(isdigit(text[charPosition]) == true) {
        strNumber += text[charPosition];
        charPosition ++;
    }
    return strNumber;
}

char OtherMethods::choseFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = getCharacter();

    return choice;
}

char OtherMethods::choseFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = getCharacter();

    return choice;
}


char OtherMethods::getCharacter() {
    string inputString = "";
    char character  = {0};

    while (true) {
        getline(cin, inputString);

        if (inputString.length() == 1) {
            character = inputString[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

int OtherMethods::getInteger() {

    string inputString = "";
    int intNumber = 0;

    while (true) {
        getline(cin, inputString);

        stringstream myStream(inputString);
        if (myStream >> intNumber)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return intNumber;
}

float OtherMethods::getFloatNumberForCashAmount() {

    string inputString = "";
    float floatNumber = 0.00;

    while (true) {
        getline(cin, inputString);

        inputString = changeCommaToDot(inputString);
        stringstream myStream(inputString);
        if (myStream >> floatNumber)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }

    return floatNumber;
}

string OtherMethods::changeCommaToDot (string stringNumber) {

    for (int i = 0; i < (int)stringNumber.length(); i++) {
        if (stringNumber[i] == ',') {
            stringNumber[i] = '.';
        }
    }

    return stringNumber;
}

float OtherMethods::convertStringToFloat(string stringNumber) {

    float floatNumber;
    istringstream iss(stringNumber);
    iss >> floatNumber;

    return floatNumber;
}

string OtherMethods::convertFloatToString(float floatNumber) {
    ostringstream ss;
    ss << floatNumber;
    string str = ss.str();
    return str;
}
