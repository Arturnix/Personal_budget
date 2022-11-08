#include "UserManager.h"

void UserManager::userRegistration() {
    User user = enterDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::enterDataOfNewUser() {
    User user;

    user.setId(getNewUserId());

    do {
        cout << "Podaj login: ";
        user.setLogin(OtherMethods::getLine());
    } while (doesLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(OtherMethods::getLine());

    cout << "Podaj imie: ";
    user.setName(OtherMethods::getLine());

    cout << "Podaj nazwisko: ";
    user.setSurname(OtherMethods::getLine());

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExist(string login) {
    for (int i = 0; i < (int)users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers() {

    if (users.size() == 0) {
        cout << "Wektor jest pusty. Brak danych do wyswietlenia!" << endl << endl;
    } else {
        for (int i = 0; i < (int)users.size(); i++) {
            cout << "Id: " << users[i].getId() << endl;
            cout << "Login: " << users[i].getLogin() << endl;
            cout << "Haslo: " << users[i].getPassword() << endl;
            cout << "Imie: " << users[i].getName() << endl;
            cout << "Nazwisko: " << users[i].getSurname() << endl << endl;
        }
    }
}

void UserManager::userLogging() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = OtherMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int trials = 3; trials > 0; trials--) {
                cout << "Podaj haslo. Pozostalo prob: " << trials << ": ";
                password = OtherMethods::getLine();

                if (itr -> getPassword() == password) {
                    loggedUserId = itr -> getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

bool UserManager::isUserLoggedIn() {
    if (loggedUserId > 0) {
        return true;
    } else {
        return false;
    }
}

/*void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika (int noweId) {
    idZalogowanegoUzytkownika = noweId;
}*/

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

void UserManager::logoutUser() {
    loggedUserId = 0;
}

void UserManager::changePasswordOfLoggedUser() {

    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = OtherMethods::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == getLoggedUserId()) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.updateFileWithUsersAfterPasswordChange(users);
}
