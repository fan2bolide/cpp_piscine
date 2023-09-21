#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

int ft_write(char *str);

class Contact {
private:
	std::string _name;
	std::string _first_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
public:
	const std::string &getNickname() const;

	void setNickname(const std::string &nickname);

	const std::string &getDarkestSecret() const;

	void setDarkestSecret(const std::string &darkestSecret);

public:
	Contact();
	Contact(std::string &name, std::string &first_name, std::string &phone_number);

	void print();
	void setName(const std::string &name);
	void setFirstName(const std::string &firstName);
	void setPhoneNumber(const std::string &phoneNumber);
	const std::string &getName() const;
	const std::string &getFirstName() const;
	const std::string &getPhoneNumber() const;
};

#endif
