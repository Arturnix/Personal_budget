#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "OtherMethods.h"
#include "DataFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public DataFile {

public:
    FileWithUsers(string fileName) : DataFile(fileName) {};
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void updateFileWithUsersAfterPasswordChange(vector<User>& users);

};

#endif // FILEWITHUSERS_H
