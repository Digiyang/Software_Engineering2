/*
 * Link: https://stackoverflow.com/questions/25696992/converting-seconds-to-hours-and-minutes-and-seconds
 */

#include "song.h"
#include "artist.h"
#include "metadata.h"

#include <iostream>
#include <string>

using namespace std;

Song::Song(Artist artist, string title)
{
    an_artist = &artist;
    a_title = title;
}

Artist Song::artist() const
{
    return *an_artist;
}

void Song::artist(Artist *artist)
{
   an_artist = artist ;
}

string Song::title() const
{
    return a_title;
}

void Song::title(string title)
{
    a_title = title;
}

Metadata *Song::metadata()
{
    return &a_metadata;
}

// converting enum to string
const string enumToString (Genre val)
{
    switch (val)
    {
        case Genre::Funk:
            return "Funk";
        case Genre::Soul:
            return "Soul";
        case Genre::Rap:
            return "Rap";
        case Genre::Rock:
            return "Rock";
        case Genre::Unknown:
            return "Unknown";
        default:
            return "Not recognized!";
    }
}

string Song::info()
{
    int minutes = a_metadata.lengthInSeconds / 60;
    int seconds = a_metadata.lengthInSeconds % 60;


    cout << "(info): " << a_title << " by " << an_artist->name() << ";"
                       << " Genre: " << enumToString(a_metadata.a_genre) << ","
                       << " Length: "<< minutes << ":" << seconds << ","
                       << " Published: " << a_metadata.publishedInYear;
    return "";
}
