#ifndef __JSONDATAITEM_HPP__
#define __JSONDATAITEM_HPP__

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <string>

using namespace std;

class JSONDataItem {
public:
    JSONDataItem();
    void parseJSONItem(std::fstream &stream);
    std::string attribute();
    unsigned integerValue();
    std::string stringValue();
    bool isNumber();
    void print();  // purely for debugging -- any format you want

private:
    std::string _attribute, _svalue;
    unsigned _ivalue;
    bool hasReadAnItem, _isNumber;

    std::string readQuotedString(std::fstream &stream);
};

#endif
