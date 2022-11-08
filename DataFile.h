#ifndef DATAFILE_H
#define DATAFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class DataFile {

    const string FILE_NAME;

public:
    DataFile(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
    bool isFileEmpty(fstream &dataFile);
};
#endif // DATAFILE_H
