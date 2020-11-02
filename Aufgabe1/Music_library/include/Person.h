#ifndef PERSON_H
#define PERSON_H

class Person : Artist {

public:
	Group group;

	Person(String name);

	Group group();

	void group(Group group);

	String info();
};

#endif
