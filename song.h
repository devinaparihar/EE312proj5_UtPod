
#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song
{

private:
    string artist;
    string title;
    int size;

public:
    Song();             //constructer
    Song(string artist, string title, int size); //constructer

    void setArtist(string a);
    string getArtist()const
    {
        return artist;
    };

    void setTitle(string t);
    string getTitle() const
    {
       return title;
    };

    void setSize(int size);
    int getSize() const
    {
        return size;
    };


    bool operator >(Song const &rhs);       //overloaded functions
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);


    ~Song();
};
















#endif