#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <ctime>

class BitcoinExchange {
private:
	std::map<std::string, double> data;

public:
	BitcoinExchange();
	BitcoinExchange(std::string file);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	class BadFile : public std::exception {
	    const char *what() const throw() {
			return "error: bad file format";
		}
	};
	class CantOpenFile : public std::exception {
	    const char *what() const throw() {
			return "error: could not open file";
		}
	};
	BitcoinExchange &operator=(const BitcoinExchange &other);
	void processInput(const std::string &inputFile);
};

#endif
