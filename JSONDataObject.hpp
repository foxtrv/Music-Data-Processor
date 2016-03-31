#ifndef __JSONDATAOBJECT__HPP
#define __JSONDATAOBJECT__HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <vector>

using namespace std;

class JSONDataItem;

class JSONDataObject {
public:
    JSONDataObject();
    virtual ~JSONDataObject();
    std::vector<JSONDataItem *> *listOfDataItems() const { return _listOfDataItems; }
    void parseFromJSONstream(std::fstream &stream);
    virtual void print();
    std::string valueForStringAttribute(std::string s);
    unsigned valueForIntegerAttribute(std::string s);

private:
    std::vector<JSONDataItem *> *_listOfDataItems;
};
#endif
