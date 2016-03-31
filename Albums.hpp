#ifndef __ALBUMS__HPP
#define __ALBUMS__HPP

#include "JSONArray.hpp"
#include "Album.hpp"
class Tracks;
class Artists;

class Albums: public JSONArray
{
public:
    Albums();
    int numAlbums();
    void addAlbum(Album *album);
    Album *artistWithID(unsigned int aID);
    Albums *albumsForArtistWithID(unsigned int aID);
    void loadAlbumsFromFile(std::string fileName);
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Album();  }
    void setTracksForAlbums(Tracks *tracks);
    std::vector<Album *> *listOfAlbums() { return (std::vector<Album *> *) _listOfDataObjects; }
    void runAsserts();  // used for checking the integrity of this class.
};
#endif
