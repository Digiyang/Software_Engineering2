#pragma once
#include <iostream>
#include <string>
#include "metadata.h"
#include "artist.h"

using namespace std;

class Artist;
class Metadata;

class Song
{
    private:
        string a_title;
        Artist *an_artist;
        Metadata a_metadata;

    public:
        Song() = default;
        Song(Artist artist, string title);

        string title() const;
        void title(string title);

        Artist artist() const;
        void artist(Artist *artist);

        Metadata *metadata();

        string info();
};

