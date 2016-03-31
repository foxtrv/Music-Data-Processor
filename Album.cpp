/******************************************************************************
 * Title:       Album.cpp                                                     *
 * Description: Application to read a set of files containing data            *
 *              related to a music database and generate HTML files           *
 *              to make that information available to users via web browsers. *
 * Author:      Trevor Fox                                                    *
 * Date:        11/5/15                                                       *
 ******************************************************************************/

#include "Album.hpp"
#include "Artist.hpp"
#include <vector>
using namespace std;

Album::Album(){
	_genres = "";
	_title = "";
	_year = "";
	_albumID = 0;
	_artistID = 0;
	_numImages = 0;
	_numTracks = 0;
	cachedgenres = false;
	cachedtitle = false;
	cachedalbumid = false;
	cachedartistid = false;
	cachednumimages = false;
	cachednumtracks = false;
	cachedyear = false;
}

std::string Album::genres(){
	if( cachedgenres )
		return _genres;
	cachedgenres = true;
	return _genres = valueForStringAttribute("genres");
}

std::string Album::title(){
	if( cachedtitle )
		return _title;
	cachedtitle = true;
	return _title = valueForStringAttribute("title");
}

unsigned Album::albumID(){
	if( cachedalbumid )
		return _albumID;
	cachedalbumid = true;
	return _albumID = valueForIntegerAttribute("album_id");
}

unsigned Album::artistID(){
	if( cachedartistid )
		return _artistID;
	cachedartistid = true;
	return _artistID = valueForIntegerAttribute("artist_id");
}

unsigned Album::numImages(){
	if( cachednumimages )
		return _numImages;
	cachednumimages = true;
	return _numImages = valueForIntegerAttribute("num_images");
}

unsigned Album::numTracks(){
	if( cachednumtracks )
		return _numTracks;
	cachednumtracks = true;
	return _numTracks = valueForIntegerAttribute("num_tracks");
}

std::string Album::year(){
	if( cachedyear )
		return _year;
	cachedyear = true;
	return _year = valueForStringAttribute("year");
}

std::string Album::htmlString(){
	string x;
        x += "<li><p>Album Title: " + title() + "</p></li>\n";
        x +=  "<ul>";
        x +=  "<li><p>\tGenres: " + genres() + "</p></li>\n";
        x += "<li><p>\tArtist ID: " + to_string(artistID()) + "</p></li>\n";
        x += "<li><p>\tAlbum ID: " + to_string(albumID()) + "</p></li>\n";
        x += "<li><p>\tNum Images: " + to_string(numImages()) + "</p></li>\n";
        x += "<li><p>\tNum Tracks: " + to_string(numTracks()) + "</p></li>\n";
        x += "<li><p>\tYear: " + year() + "</p></li>\n";
        x += "</ul>";
	x += tracks()->htmlString();
	return x;
}


