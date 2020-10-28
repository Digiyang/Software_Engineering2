#pragma once
#include "genre.h"


class Metadata
{

private:
    Genre genre_;

public:
    int lengthInSeconds = 0;
    int publishedInYear = 1970;
    void init(int length, int year, Genre genre) const;
};

