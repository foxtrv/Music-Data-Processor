#ifndef __ARTIST__HPP
#define __ARTIST__HPP

#include "JSONDataObject.hpp"
#include <iostream>
#include "Albums.hpp"

class Artist: public JSONDataObject
{
public:
    Artist();

    std::string profile();
    std::string name();
    std::string realName();
    std::string numImages();
    std::string htmlString();
    unsigned artistID();
    void setAlbums(Albums *albums)       { _albums = albums;       }
    Albums *albums()		         { return _albums;         }
private:
    Albums *_albums;
    std::string _name, _realName, _profile, _numImages;
    unsigned _artistID;
    bool cachedName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;
};
#endif
