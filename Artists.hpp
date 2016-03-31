#ifndef __ARTISTS__HPP
#define __ARTISTS__HPP

#include "JSONArray.hpp"
#include "Artist.hpp"
#include "Tracks.hpp"
class Albums; // Forward Declaration of Albums

class Artists: public JSONArray
{
public:
    Artists();

    int numArtists();
    void addArtist(Artist *artist);
    Artist *artistWithID(unsigned int aID);
    void loadArtistsFromFile(std::string fileName);
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Artist();  }
    void setAlbumsForArtists(Albums *albums);
    std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; }
    void runAsserts();  // used for checking the integrity of this class.
    void print();
};
#endif
