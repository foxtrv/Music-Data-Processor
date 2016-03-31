#include "JSONDataItem.hpp"

JSONDataItem::JSONDataItem(){
	_attribute = "";
	_svalue = "";
	_ivalue = 0;
	hasReadAnItem = false;
	_isNumber = false;
}

std::string JSONDataItem::attribute()	 { return _attribute;	    }
unsigned JSONDataItem::integerValue()	 { return _ivalue;	    }
std::string JSONDataItem::stringValue()  { return _svalue;	    }
bool JSONDataItem::isNumber()		 { return _isNumber = true; }

void JSONDataItem::parseJSONItem(std::fstream &stream){
	char c; // declare a variable to keep place in stream
	if( !(stream >> c) || c != '"' ){
		cout << "readJSONDataItem worked incorrectly: no double quote (\") found  " << endl;
		exit (1);
	}
	_attribute = readQuotedString(stream); // set the key
	// After having read the key, including the closing double-quote, we should find a colon.
	if( !(stream >> c) || c != ':' ){
        	cout << "readJSONDataItem worked incorrectly: no colon found " << endl;
	        exit (1);
	}
	// Value is either a string or a number (or a number in a string).
	stream >> c;
	if( isdigit(c) ) {
		_isNumber = true;
		stream.unget(); // put the digit back into the stream so we read the number.
		stream >> _ivalue;
	} else 
		_svalue = readQuotedString(stream); // Set the value (as a string)
}

std::string JSONDataItem::readQuotedString(std::fstream &stream){
	char c;
	char prev;
	string valuehelper;
	stream >> c;
	while (c != '"') {
		prev = c;
		valuehelper += c;
		stream.get(c);
		if (prev == '\\') {
			valuehelper += c;
			stream.get(c);
		}
	}
	return valuehelper;
}


void JSONDataItem::print(){
	std::cout << _attribute << ": ";
	if ( _isNumber == true )
		std::cout << _ivalue << "\n";
	else 
		std::cout << _svalue << "\n";
}


