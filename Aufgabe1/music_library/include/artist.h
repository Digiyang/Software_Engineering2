#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "song.h"

using namespace std;

class Song;

class Artist
{
    protected:
        string a_name;
        vector<Song*> the_songs;

    public:
        Artist() = default;

        string name() const;
        void name (string);

        vector<Song *> songs();
        void addSong(Song *song);

        // info() method of Artist class is pure virtual function, so it is also shown as italics
        virtual string info();
};

