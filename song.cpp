#include "song.h"
//#include <string>

using namespace std;


Song :: Song ()
{
    artist = "";
    title = "";
    size = 0;
}

Song :: Song(string _artist, string _title, int _size)
{
    artist = _artist;
    title = _title;
    size = _size;
}

void Song :: setArtist(string a){
    artist = a;
}

void Song ::setTitle(string t) {
    title = t;

}

void Song ::setSize(int size) {
    this->size = size;
}

bool Song ::operator<(Song const &rhs) {    //artist, then title, then size
    if(artist.compare(rhs.artist) >0)
        return true;
    else if(title.compare(rhs.title) >0)
        return true;
    else if(size < rhs.size)
        return true;
    else
        return false;

}

bool Song ::operator>(Song const &rhs) {
    if(artist.compare(rhs.artist) <0)
        return true;
    else if(title.compare(rhs.title) <0)
        return true;
    else if(size > rhs.size)
        return true;
    else
        return false;

}

bool Song ::operator==(Song const &rhs) {
    return(artist == rhs.artist && title == rhs.title && size == rhs.size);

// hi whats up

}
