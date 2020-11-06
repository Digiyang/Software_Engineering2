#include "artist.h"
#include "song.h"

#include <string>

using namespace std;

string Artist::name() const {
    return a_name;
}

void Artist::name(string name) {
    a_name = name;
}

void Artist::addSong(Song *song)
{
    the_songs.push_back(song);
    song->artist(this);
}

vector<Song *> Artist::songs()
{
    return the_songs;
}

string Artist::info()
{
    return "";
}

