#include "PhoneBook.h"

int main()
{
	PhoneBook book = PhoneBook();
	std::string input_command;

	while (true)
	{
		std::cout << "insert command:";
		std::getline(std::cin, input_command);
		if (std::cin.eof()){
			std::cout << "EOF detected" << std::endl;
			return (1);
		}
		if (input_command == "ADD")
		{
			book.add_contact();
		}
		else if (input_command == "SEARCH")
		{
			book.search_contact();
		}
		else if (input_command == "EXIT")
		{
			return (0);
		}
		else{
			std::cout << "Command entered : " << input_command <<std::endl;
			std::cout << "Unknown command, please retry" << std::endl;
		}
		std::cin.clear();
	}
}