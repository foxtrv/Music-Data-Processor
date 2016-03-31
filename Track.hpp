#ifndef __TRACK__HPP
#define __TRACK__HPP

#include "JSONDataObject.hpp"

class Track: public JSONDataObject
{
public:
    Track();

    std::string artistName();
    std::string title();
    std::string albumName();
    unsigned albumID();
    std::string duration();
    std::string position();
    std::string htmlString();

private:
    std::string _artistName, _title, _albumName, _duration, _position;
    unsigned _albumID;

    bool cachedartistname, cachedtitle, cachedalbumname, cachedalbumid, \
	 cachedduration, cachedposition;
};
#endif
