#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	std::string		file_content;
	std::fstream	infile(argv[1]);
	std::ofstream	outfile((std::string)argv[1] + ".replace");
	std::size_t		index;

	if (argc < 4)
		return (1);
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	if (s1 == s2)
		return (0);
	if (!infile.is_open())
	{
		std::cerr << "Error opening the infile." << std::endl;
		return (1);
	}
	std::getline(infile, file_content, '\0');
	//searching occurrences of s1 in file_content
	while (file_content.find(s1, 0) != std::string::npos)
	{
		//find
		index = file_content.find(s1, 0);
		//erase
		file_content.erase(index, s1.length());
		//insert
		file_content.insert(index, s2);
	}
	//write it back in the infile
	outfile << file_content;
	outfile.flush();
	return (0);
}
