#pragma once
#include <iostream>
#include "genre.h"

using namespace std;

enum class Genre;

class Metadata
{
    public:
        int lengthInSeconds;
        int publishedInYear;
        Genre a_genre;

        Metadata() = default;
        Metadata(int lengthInSeconds, int publishedInYear);

        void init(int length, int year, Genre genre);
};

