/******************************************************************************
 * Title:	Artist.cpp						      *
 * Description:	Application to read a set of files containing data 	      *
 * 		related to a music database and generate HTML files 	      *
 * 		to make that information available to users via web browsers. *
 * Author:	Trevor Fox						      *
 * Date:	11/5/15							      *
 ******************************************************************************/

#include "Artist.hpp"
#include <vector>
using namespace std;

Artist::Artist(){
	_name = "";
	_realName = "";
	_profile = "";
	_numImages = "";
	_artistID = 0;
	cachedName = false;
	cachedRealName = false;
	cachedProfile = false;
	cachedNumImages = false;
	cachedArtistID = false;
}

std::string Artist::profile(){
    if( cachedProfile )
        return _profile;
    cachedProfile = true;
    return _profile = valueForStringAttribute("profile");
}

std::string Artist::name(){
    if( cachedName )
        return _name;
    cachedName = true;
    return _name = valueForStringAttribute("artist_name");
}

std::string Artist::realName(){
    if( cachedRealName )
        return _realName;
    cachedRealName = true;
    return _realName = valueForStringAttribute("real_name");
}

std::string Artist::numImages(){
    if( cachedNumImages )
        return _numImages;
    cachedNumImages = true;
    return _numImages = valueForStringAttribute("num_images");
}

unsigned Artist::artistID(){
    if( cachedArtistID )
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}

std::string Artist::htmlString(){
	string x;
	x += "<li><p>Name: " + name() + "</p></li>\n";
	x +=  "<ul>";
	x +=  "<li><p>\tReal Name: " + realName() + "</p></li>\n";
	x += "<li><p>\tArtist ID: " + to_string(artistID()) + "</p></li>\n";
	x += "<li><p>\tNum Images: " + numImages() + "</p></li>\n";
	x += "<li><p>\tProfile: " + profile() + "</p></li>\n";
	x += "</ul>";
	x += albums()->htmlString();
	return x;
}


