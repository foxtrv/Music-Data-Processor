#include "Tracks.hpp"
#include "Track.hpp"
#include <vector>
using namespace std;

Tracks::Tracks(){}
Tracks::~Tracks(){}
int Tracks::numTracks()		    { return _listOfDataObjects->size(); }
void Tracks::addTrack(Track *track) { listOfTracks()->push_back(track);  }
Track *Tracks::artistWithID(unsigned int aID){}
void Tracks::runAsserts(){}

void Tracks::loadTracksFromFile(std::string tracksFileName){
    std::fstream trackStream;
    trackStream.open(tracksFileName.c_str(), std::fstream::in);
    parseJSONArray(trackStream);
    trackStream.close();
}

Tracks *Tracks::tracksForAlbumWithID(unsigned int aID){
	Tracks *a = new Tracks();
	for ( auto i : *listOfTracks() )
		if ( i->albumID() == aID )
			a->addTrack(i);
	return a;
}

std::string Tracks::htmlString(){
	string x;
	x = "<ol>";
	for ( auto i : *listOfTracks() )
		x += i->htmlString();
	x += "</ol>";
	return x;
}


