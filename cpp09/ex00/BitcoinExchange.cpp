#include "BitcoinExchange.hpp"
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <istream>
#include <sstream>
#include <algorithm>
#include <utility>

using std::string;

//checks the date format, returns 1 if format is wrong, 0 else
static int checkDate(const string &date) {
	struct tm time = {};
	std::stringstream ss(date);
	char dash;
	char dash2;
	int year;
	int month;
	int day;
	ss >> time.tm_year >> dash >> time.tm_mon >> dash2 >> time.tm_mday;
	year = time.tm_year;
	month = time.tm_mon;
	day = time.tm_mday;
	std::mktime(&time);
	if (year != time.tm_year || month != time.tm_mon || day != time.tm_mday)
		return (1);
	return (0);
}

//checks the value, returns 1 if value is unexpected, 0 else
static int checkValue(const double &value) {
	if (value < 0 || value > 1000)
		return (1);
	return(0);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(string file) {
	std::ifstream inFile;
	string line;
	inFile.open(file.c_str());
	if (inFile.fail())
		throw (CantOpenFile());
	std::getline(inFile, line);
	while (!inFile.eof()) {
		std::getline(inFile, line);
		if (line.empty())
			break;
		if (line.find(',') == std::string::npos)
			throw(BadFile());
		std::stringstream ss(line);
		double value;
		string time;
		std::getline(ss, time, ',');
		ss >> value;
		data[time] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	this->data = other.data;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->data = other.data;
	}
	return *this;
}

void BitcoinExchange::processInput(const std::string &inputFile) {
	std::ifstream inFile;
	string line;
	inFile.open(inputFile.c_str());
	if (inFile.fail())
		throw (CantOpenFile());
	std::getline(inFile, line);
	while (!inFile.eof()) {
		std::getline(inFile, line);
		if (line.empty() || line == "\n")
			break;
		if (line.find('|') == std::string::npos)
			throw(BadFile());
		std::stringstream ss(line);
		double value;
		string stringValue;
		string date;
		std::getline(ss, date, '|');
		ss >> value;
		if (checkValue(value) || checkDate(date)) {
			if (checkDate(date))
				std::cout << "error: bad input => " << date << std::endl;
			else if (checkValue(value)) {
				if (value < 0)
					std::cout << "error: not a positive number." << std::endl;
				if (value > 1000)
					std::cout << "error: too large number." << std::endl;
			}
		}
		else {
			std::map<string, double>::iterator it = data.lower_bound(date);
			if (it == data.begin() && date != data.begin()->first)
				std::cout << "Error: date not registered: " << date;
			else
				std::cout << date << " => " << value << " = " << (--it)->second * value << std::endl;
		}
	}
}
