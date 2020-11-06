#include "group.h"
#include "person.h"
#include "artist.h"
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

Group::Group(string name)
{
    a_name = name;
}

void Group::addMember(Person *person)
{
    members.push_back(person);
    person->group(this);
}

vector<Person *> Group::member()
{
    return members;
}

string Group::info()
{
    cout << "(info): " << a_name << " : ";

    // declare an iterator to a vector of strings
    vector <Person *>::iterator it;
    for (it = members.begin(); it != members.end(); it++)
    {
        cout << (*it)->name() << ", ";
    }
    return "";
}
