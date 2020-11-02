#ifndef GROUP_H
#define GROUP_H

class Group : Artist {

public:
	std::vector<Person> members;

	Group(String name);

	void addMember(Person person);

	String info();
};

#endif
