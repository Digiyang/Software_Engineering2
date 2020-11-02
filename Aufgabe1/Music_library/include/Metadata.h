#ifndef METADATA_H
#define METADATA_H

class Metadata {

public:
	Genre genre;
	Int lengthInSeconds;
	Int publishedInYear;

	void init(Int length, Int year, Genre genre);
};

#endif
