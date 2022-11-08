#include "DataFile.h"

string DataFile::getFileName() {
    return FILE_NAME;
}

bool DataFile::isFileEmpty(fstream &dataFile) {
    dataFile.seekg(0, ios::end);
    if (dataFile.tellg() == 0)
        return true;
    else
        return false;
}
