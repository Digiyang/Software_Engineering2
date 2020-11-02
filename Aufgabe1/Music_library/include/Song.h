#ifndef SONG_H
#define SONG_H

class Song {

private:
	Artist artist;
	Metadata metadata;
	String title;

public:
	Song(Artist artist, String title);

	Artist artist();

	void artist(Artist artist);

	String title();

	void title(Title string);

	Metadata metadata();

	String info();
};

#endif
