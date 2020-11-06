#pragma once
#include "artist.h"
#include <string>
#include <vector>

using namespace std;
class Person;

class Group : public Artist
{
    private:
        vector <Person*> members;

    public:

        Group() = default;
        Group(string group_name);

        void addMember(Person *person);
        vector <Person *> member();
        string info();
};


