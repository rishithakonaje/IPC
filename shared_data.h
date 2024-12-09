#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include <string>

enum DataType { type1, type2, type3 };

struct DataStructure {
    int intValue;
    float floatValue;
    char stringValue[100]; 
    DataType enumValue;
    bool dataReady;        
};

#endif
