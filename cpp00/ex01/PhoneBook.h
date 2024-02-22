#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"

class PhoneBook {
private:
	int index;
	Contact contacts[8];

public:
	PhoneBook();
	void add_contact();
	void print();
	void search_contact();
	std::string retry_prompt();
	static void write_field(std::string field);
};

#endif
