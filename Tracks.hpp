#ifndef __TRACKS__HPP
#define __TRACKS__HPP

#include "Track.hpp"
#include "JSONArray.hpp"

class Tracks: public JSONArray
{
public:
    Tracks();
    ~Tracks();

    int numTracks();
    void addTrack(Track *track);
    Track *artistWithID(unsigned int aID);
    Tracks *tracksForAlbumWithID(unsigned int aID);
    void loadTracksFromFile(std::string fileName);
    std::string htmlString();
    JSONDataObject *jsonObjectNode() { return new Track();  }
    std::vector<Track *> *listOfTracks() { return (std::vector<Track *> *) _listOfDataObjects; }
    void runAsserts();  // used for checking the integrity of this class.
};
#endif
