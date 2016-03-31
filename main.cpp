#include "Artist.hpp"
#include "Artists.hpp"
#include "Album.hpp"
#include "Albums.hpp"
#include "Track.hpp"
#include "Tracks.hpp"
#include "JSONArray.hpp"
#include "JSONDataObject.hpp"
#include "JSONDataItem.hpp"

int main(){

	Artists *artists = new Artists();
	Albums *albums = new Albums();
	Tracks *tracks = new Tracks();

	artists->loadArtistsFromFile("artists_human_readable.json");
	albums->loadAlbumsFromFile("albums_human_readable.json");
	tracks->loadTracksFromFile("tracks_human_readable.json");

	albums->setTracksForAlbums(tracks);
	artists->setAlbumsForArtists(albums);

	artists->htmlString();

	std::cout << std::endl;
	return 0;
};








