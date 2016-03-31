#include "JSONDataObject.hpp"
#include "JSONDataItem.hpp"

JSONDataObject::JSONDataObject() { _listOfDataItems = new vector<JSONDataItem *>(); }

JSONDataObject::~JSONDataObject(){}

void JSONDataObject::parseFromJSONstream(std::fstream &stream){
	char cc[2], prev = ' ';
	cc[1] = '\0';
        if( ! (stream >> cc[0]) || cc[0] != '{' ){
                std::cout << "parseJSONObject failed\n";
                exit(1);
        }
	do { 
		JSONDataItem *dItem = new JSONDataItem();
		dItem->parseJSONItem(stream);
		_listOfDataItems->push_back(dItem);
		stream >> cc[0];
        } while( cc[0] != '}' || cc[0] == ',' );
}

void JSONDataObject::print(){
	for ( auto i : *_listOfDataItems )
                i->print();
	std::cout << std::endl;
}

string JSONDataObject::valueForStringAttribute(std::string s){
	for (auto element : *_listOfDataItems)
		if ( element->attribute() == s )
			return element->stringValue();
}

unsigned JSONDataObject::valueForIntegerAttribute(std::string s){
	for (auto element : *_listOfDataItems)
		if ( element->attribute() == s )
			return element->integerValue();
}


