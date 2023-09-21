#include "Contact.h"

Contact::Contact(std::string &name, std::string &first_name, std::string &phone_number): _phone_number(phone_number), _name(name), _first_name(first_name)  {

}

Contact::Contact() {

}

void Contact::print() {
	if (this->_first_name.empty())
	{
		std::cout << "this contact is empty" << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << this->_first_name << std::endl;
	std::cout << this->_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_phone_number << std::endl;
	std::cout << this->_darkest_secret << std::endl;
	std::cout << std::endl;
}

const std::string &Contact::getName() const {
	return _name;
}

const std::string &Contact::getFirstName() const {
	return _first_name;
}

const std::string &Contact::getPhoneNumber() const {
	return _phone_number;
}

void Contact::setName(const std::string &name) {
	_name = name;
}

void Contact::setFirstName(const std::string &firstName) {
	_first_name = firstName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
	_phone_number = phoneNumber;
}

const std::string &Contact::getNickname() const {
	return _nickname;
}

void Contact::setNickname(const std::string &nickname) {
	_nickname = nickname;
}

const std::string &Contact::getDarkestSecret() const {
	return _darkest_secret;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
	_darkest_secret = darkestSecret;
}

int ft_write(char *str)
{
	int i = 0;
	if (!str)
		std::cout << "(null)" << std::endl;
	while (str[i])
	{
		std::cout << str[i];
		i++;
	}
	return (i);
}
