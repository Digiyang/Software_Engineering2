#include "metadata.h"

using namespace std;

/*Metadata::Metadata(int lengthInSeconds, int publishedInYear)
{
    lengthInSeconds = 0;
    publishedInYear = 1970;
}*/

void Metadata::init(int length, int year, Genre genre)
{
    lengthInSeconds = length;
    publishedInYear = year;
    a_genre = genre;
}
