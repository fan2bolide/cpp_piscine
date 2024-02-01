#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	std::string		file_content;
	std::size_t		index;

	if (argc < 4) {
		std::cerr << "Wrong number of arguments." << std::endl;
		return 1;
	}
	std::fstream	infile(argv[1]);
	std::ofstream	outfile(((std::string)argv[1] + ".replace").c_str());
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	if (s1.empty()) {
		std::cerr << "the string to replace is empty, unable to accomplish task" << std::endl;
		return 1;
	}
	if (!infile.is_open()) {
		std::cerr << "Error opening the infile." << std::endl;
		return 1;
	}
	std::getline(infile, file_content, '\0');
	infile.close();
	index = 0;
	while (file_content.find(s1, index) != std::string::npos) {
		index = file_content.find(s1, index);
		file_content.erase(index, s1.length());
		file_content.insert(index, s2);
		index += s2.length();
	}
	outfile << file_content;
	outfile.flush();
	outfile.close();
	return 0;
}
