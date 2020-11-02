#ifndef ARTIST_H
#define ARTIST_H

class Artist {

protected:
	std::vector<Song> songs;
	String name;

public:
	Artist();

	String name();

	void name(String name);

	void addSong(Song song);

	String info();
};

#endif
