#include <iostream>
#include "UserManager.h"
#include "OtherMethods.h"

using namespace std;

int main()
{
    UserManager user1("users.xml");

    while (true) {
        if (!user1.isUserLoggedIn()) {

            switch (OtherMethods::choseFromMainMenu()) {
            case '1':
                user1.userRegistration();
                break;
            case '2':
                user1.userLogging();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            switch (OtherMethods::choseFromUserMenu()) {
            case '1':

                break;
            case '2':

                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':
                user1.changePasswordOfLoggedUser();
                break;
            case '7':
                user1.logoutUser();
                break;
            }
        }
    }

    return 0;
}
