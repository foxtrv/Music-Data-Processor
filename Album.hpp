#ifndef __ALBUM__HPP
#define __ALBUM__HPP

#include "JSONDataObject.hpp"
#include "Tracks.hpp"
class Artist;

class Album: public JSONDataObject 
{
public:
    Album();

    std::string genres();
    std::string title();
    std::string year();
    unsigned albumID();	
    unsigned artistID();
    unsigned numImages();
    unsigned numTracks();

    void setTracks(Tracks *tracks)  { _tracks = tracks;		   }
    void setArtist(Artist *artist)  { _artist = artist;		   }

    Artist *artist()		    { return _artist;		   }
    Tracks *tracks() 		    { return _tracks;              }

    std::string htmlString();

private:
    Tracks *_tracks;
    Artist *_artist;
    std::string _title, _genres, _year;
    unsigned _albumID, _numTracks, _numImages, _artistID;
    bool cachedgenres, cachedtitle, cachedalbumid, cachedartistid, cachednumimages, \
	cachednumtracks, cachedyear;
};
#endif
