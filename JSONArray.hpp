#ifndef __JSONARRAY__HPP
#define __JSONARRAY__HPP
#include <vector>
#include <iostream>

class JSONDataObject;

class JSONArray 
{
public:
    JSONArray();
    ~JSONArray();
    std::vector<JSONDataObject *> *listOfDataObjects() { return _listOfDataObjects; }
    virtual JSONDataObject *jsonObjectNode() = 0;
    int numJSONObjects();
    void parseJSONArray(std::fstream &stream);
    virtual void print();

protected:
    std::vector<JSONDataObject *> *_listOfDataObjects;
    
};
#endif
