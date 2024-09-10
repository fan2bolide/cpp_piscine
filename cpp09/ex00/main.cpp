#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "error: could not open file." << std::endl;
		return (0);
	}

	//trying to open the input file
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	if (inputFile.fail()) {
		cout << "error: could not open file." << endl;
		return (1);
	}

	try {
		// parse csv file and create database
		BitcoinExchange btc("data.csv");

		// parse input file and process inputs
		btc.processInput(argv[1]);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	return (0);
}
