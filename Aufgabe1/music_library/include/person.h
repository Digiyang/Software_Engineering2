#pragma once
#include <string>
#include "artist.h"
#include "group.h"

using namespace std;
class Group;

class Person : public Artist
{
    private:
        Group *a_group;

    public:
        Person() = default;
        Person(string person_name);

        Group *group() const;
        void group(Group *group);

        string info();
};

