#include "JSONArray.hpp"
#include "JSONDataObject.hpp"

JSONArray::JSONArray(){ _listOfDataObjects = new std::vector<JSONDataObject *>(); }
JSONArray::~JSONArray(){}

int JSONArray::numJSONObjects(){ return _listOfDataObjects->size(); }

void JSONArray::parseJSONArray(std::fstream &stream)
{
	char cc[2], prev = ' ';
	cc[1] = '\0';
	// we expect this to be a open-bracket character.
	if( ! (stream >> cc[0]) || cc[0] != '[' ){
		std::cout << "parseJSONArray failed\n";
		exit(1);
	}
	do {
		JSONDataObject *dItem = jsonObjectNode();
		dItem->parseFromJSONstream(stream);
		_listOfDataObjects->push_back(dItem);
	if( ! (stream >> cc[0]) ){
		std::cout << "parseJSONArray failed 3\n";
		exit(1); 
	}
	if( cc[0] != ']' && cc[0] != ',' ){ 
		std::cout << "parseJSONArray failed 3\n";
		exit(1);
	}
	} while( cc[0] != ']' );
}

void JSONArray::print(){
	for ( auto i : *_listOfDataObjects )
		i->print(); 
}


