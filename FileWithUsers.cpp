#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {

    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("users.xml");
}

vector<User> FileWithUsers::loadUsersFromFile() {


    User user;
    vector<User> users;

    CMarkup xml;

    xml.Load( "users.xml" );

    xml.FindElem(); // root OPERATIONS element
    xml.IntoElem(); // inside OPERATIONS
    while ( xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem("Id");
        user.setId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);
    }
    return users;
}

/*Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami) {
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < (int)daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejUzytkownika) {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}*/

void FileWithUsers::updateFileWithUsersAfterPasswordChange(vector<User>& users) {

    CMarkup xml;
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");

    xml.AddElem("Users");
    xml.FindElem();
    xml.IntoElem();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("Id", itr -> getId());
        xml.AddElem("Login", itr -> getLogin());
        xml.AddElem("Password", itr -> getPassword());
        xml.AddElem("Name", itr -> getName());
        xml.AddElem("Surname", itr -> getSurname());
    }

    xml.Save("users.xml");
}
