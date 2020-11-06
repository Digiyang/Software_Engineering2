#include <iostream>
#include <sstream>
#include "person.h"

Person::Person(string name)
{
    a_name = name;
}

Group *Person::group() const
{
    return a_group;
}

void Person::group(Group *group)
{
    a_group = group;
}

string Person::info()
{
    cout << "(info): " << a_name << " " << "of" << " " << a_group->name();
    return "";
}




