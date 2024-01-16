#include "PhoneBook.h"

PhoneBook::PhoneBook() : index(0)
{

}

void PhoneBook::add_contact()
{
	std::string input;

	std::cout << "enter the contact's first name :";
	std::getline(std::cin, input);
	if (input.empty())
		input = retry_prompt();
	this->contacts[index].setFirstName(input);
	std::cout << "enter the contact's name :";
	std::getline(std::cin, input);
	if (input.empty())
		input = retry_prompt();
	this->contacts[index].setName(input);
	std::cout << "enter the contact's Nickname :";
	std::getline(std::cin, input);
	if (input.empty())
		input = retry_prompt();
	this->contacts[index].setNickname(input);
	std::cout << "enter the contact's phone number :";
	std::getline(std::cin, input);
	if (input.empty())
		input = retry_prompt();
	this->contacts[index].setPhoneNumber(input);
	std::cout << "enter the contact's darkest secret :";
	std::getline(std::cin, input);
	if (input.empty())
		input = retry_prompt();
	this->contacts[index].setDarkestSecret(input);
	index++;
	index %= 8;
}

std::string PhoneBook::retry_prompt()
{
	std::string input;

	while (input.empty())
	{
		if (std::cin.eof())
		{
			std::cout << std::endl << "EOF detected" << std::endl;
			exit(1);
		}
		std::cout << "this field can't be empty, please try again : ";
		std::cin.clear();
		std::getline(std::cin, input);
	}
	return (input);
}

void PhoneBook::print()
{
	int i;

	i = 0;
	std::cout << "index      First Name Name       Nickname" << std::endl;
	while (i < 8)
	{
		std::cout << "         " << i;
		std::cout << "|";
		write_field(contacts[i].getFirstName());
		std::cout << "|";
		write_field(contacts[i].getName());
		std::cout << "|";
		write_field(contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
}

void PhoneBook::write_field(std::string field)
{
	int column_length;

	column_length = 10;
	if (field.length() > 10)
		std::cout << field.substr(0, 9) << ".";
	else
	{
		column_length -= field.length();
		while (column_length > 0)
		{
			std::cout << " ";
			column_length--;
		}
		std::cout << field;
	}
}

void PhoneBook::search_contact()
{
	std::string input;

	print();
	std::cout << "enter the index to the contact you want:";
	std::cin >> input;
	while (input.length() > 1 || input.length() == 0 || (input[0] < '0' || input[0] > '9'))
	{
		std::cout << "that entry is not a number in range 0-7, try again:";
		input = retry_prompt();
	}
	contacts[input[0] - '0'].print();
}
