#include "Artists.hpp"
#include "Albums.hpp"
#include <vector>
using namespace std;

Artists::Artists(){}
int Artists::numArtists()		{ return _listOfDataObjects->size();  }
void Artists::addArtist(Artist *artist) { listOfArtists()->push_back(artist); }
void Artists::runAsserts(){}

Artist *Artists::artistWithID(unsigned int aID){
	for ( auto i : *listOfArtists() )
		if ( i->artistID() == aID )
			return i;
}

void Artists::loadArtistsFromFile(std::string artistsFileName){
    std::fstream artStream;
    artStream.open(artistsFileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}

void Artists::setAlbumsForArtists(Albums *albums){
	for ( auto i : *listOfArtists() )
		i->setAlbums(albums->albumsForArtistWithID(i->artistID()));
}

void Artists::print(){
	for ( auto i : *listOfArtists() )
		i->print();
}

string Artists::htmlString(){
	string x; // Declare a string to hold the parsed information as a string
	x = "<ol>";
	for ( auto i : *listOfArtists() )
		x += i->htmlString(); // Loop through each artist object
	x += "</ol>";
	string s = "<!DOCTYPE html>\n <html>\n <head>\n </head>\n <body>\n"; 
	ofstream myfile;
	myfile.open("artists.html");
	myfile << s;
	myfile << x;
	myfile << "</body>";
	myfile << "</html>";
	myfile.close();
}

