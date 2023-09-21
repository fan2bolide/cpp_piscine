#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	std::string		file_content;
	std::string		file_replacement;
	std::ifstream	file;
	int				index;

	if (argc < 4)
		return (1);
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	file.open(argv[1], std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Error opening the file." << std::endl;
		return (1);
	}
	std::getline(file, file_content, '\0');
	std::cout << file_content << std::endl;
	//searching occurrences of s1 in file_content
	index = file_content.find_first_of(s1);
	if (!file_content.compare(index, s1.length(), s1))
	{
		//replace the occurrence
		file_content = file_content.substr(0, index) + s2 + file_content.substr(index + s1.length(), file_content.length() - index + s1.length());
	}
	std::cout << file_content;
	file.close();
	return (0);
}