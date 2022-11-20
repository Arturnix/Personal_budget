#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "OtherMethods.h"
#include "FileWithUsers.h"
//#include "IncomeManager.h"

using namespace std;

class UserManager {

    vector <User> users;
    FileWithUsers fileWithUsers;
    int loggedUserId;

    User enterDataOfNewUser();
    int getNewUserId();
    bool doesLoginExist(string login);

public:
    UserManager ();
    UserManager(string fileName, int LOGGED_USER_ID = 0)
        : fileWithUsers(fileName), loggedUserId(LOGGED_USER_ID) {
        users = fileWithUsers.loadUsersFromFile();
    };

    void userRegistration();
    void showAllUsers();
    void userLogging();
    bool isUserLoggedIn();
    int getLoggedUserId();
    void changePasswordOfLoggedUser();
    /*void ustawIdZalogowanegoUzytkownika (int noweId);*/
    void logoutUser();
};

#endif // USERMANAGER_H
