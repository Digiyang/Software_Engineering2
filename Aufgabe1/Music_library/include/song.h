#pragma once
#include <string>

class Artist;
class Metadata;

using namespace std;

class Song
{
private:
    string title;
    Artist *artist_;
    Metadata *metadata_;
public:
    Song();
    Song( Artist artist, string title);
    Artist getArtist() const;
    void setArtist(Artist);
    string getTitle() const;
    void setTitle(string);
    Metadata getMetadata() const;
    string getInfo() const;
};

