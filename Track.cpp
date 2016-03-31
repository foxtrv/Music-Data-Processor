/******************************************************************************
 * Title:       Track.cpp                                                     *
 * Description: Application to read a set of files containing data            *
 *              related to a music database and generate HTML files           *
 *              to make that information available to users via web browsers. *
 * Author:      Trevor Fox                                                    *
 * Date:        11/5/15                                                       *
 ******************************************************************************/

#include "Track.hpp"
#include <vector>
using namespace std;

Track::Track(){
	_artistName = "";
	_title = "";
	_albumName = "";
	_albumID = 0;
	_duration = "";
	_position = "";
	cachedartistname = false;
	cachedtitle = false;
	cachedalbumname = false;
	cachedalbumid = false;
	cachedduration = false;
	cachedposition = false;
}

std::string Track::artistName(){
	if( cachedartistname )
		return _artistName;
	cachedartistname = true;
	return _artistName = valueForStringAttribute("artist_name");
}

std::string Track::title(){
	if( cachedtitle )
		return _title;
	cachedtitle = true;
	return _title = valueForStringAttribute("title");
}

std::string Track::albumName(){
	if( cachedalbumname )
		return _albumName;
	cachedartistname = true;
	return _albumName = valueForStringAttribute("album_name");
}

unsigned Track::albumID(){
	if( cachedalbumid )
		return _albumID;
	cachedalbumid = true;
	return _albumID = valueForIntegerAttribute("album_id");
}

std::string Track::duration(){
	if( cachedduration )
		return _duration;
	cachedduration = true;
	return _duration = valueForStringAttribute("duration");
}

std::string Track::position(){
	if( cachedposition )
		return _position;
	cachedposition = true;
	return _position = valueForStringAttribute("position");
}

std::string Track::htmlString(){
	string x;
        x += "<li><p>Title: " + title() + "</p></li>\n";
        x +=  "<ul>";
        x +=  "<li><p>\tArtist Name: " + artistName() + "</p></li>\n";
        x += "<li><p>\tAlbum Name: " + albumName() + "</p></li>\n";
        x += "<li><p>\tAlbum ID: " + to_string(albumID()) + "</p></li>\n";
        x += "<li><p>\tDuration: " + duration() + "</p></li>\n";
        x += "<li><p>\tPosition: " + position() + "</p></li>\n";
        x += "</ul>";
	return x;
}


