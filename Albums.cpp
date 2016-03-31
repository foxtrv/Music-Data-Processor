#include "Albums.hpp"
#include "Artists.hpp"
#include "Tracks.hpp"
#include <vector>
using namespace std;

Albums::Albums(){}
int Albums::numAlbums(){ return _listOfDataObjects->size(); }
void Albums::addAlbum(Album *album){ listOfAlbums()->push_back(album); }
void Albums::runAsserts(){}

Album *Albums::artistWithID(unsigned int aID){
	for ( auto i : *listOfAlbums() )
		if ( i->artistID() == aID )
			return i;
}

void Albums::loadAlbumsFromFile(std::string albumsFileName){
    std::fstream albumStream;
    albumStream.open(albumsFileName.c_str(), std::fstream::in);
    parseJSONArray(albumStream);
    albumStream.close();
}

void Albums::setTracksForAlbums(Tracks *tracks){
	for (auto i : *listOfAlbums() )
		i->setTracks(tracks->tracksForAlbumWithID(i->albumID()));
}

Albums *Albums::albumsForArtistWithID(unsigned int aID){
	Albums *a = new Albums;
	for (vector<Album *>::iterator i = listOfAlbums()->begin(); i != listOfAlbums()->end(); i++)
		if ((*i)->artistID() == aID)
			a->addAlbum((*i));
	return a;
}

std::string Albums::htmlString(){
	string x;
	x = "<ol>";
	for ( auto i : *listOfAlbums() )
		x += i->htmlString();
	x += "</ol>";
	return x;
}


