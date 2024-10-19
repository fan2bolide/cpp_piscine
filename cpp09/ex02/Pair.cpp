#include "Pair.hpp"

#define NULL 0

Pair::Pair(Pair *pair1, Pair *pair2) {
	if (pair1->high < pair2->high) {
		highPair = pair2;
		lowPair = pair1;
	}
	else {
		highPair = pair1;
		lowPair = pair2;
	}
	high = highPair->high;
}

Pair::Pair(Pair *pair) : high(pair->high), highPair(pair->highPair), lowPair(pair->lowPair) {
}

Pair::~Pair() {
	delete highPair;
	delete lowPair;
}

Pair Pair::operator=(Pair pair) {
	if (this != &pair) {
		high = pair.high;
		highPair = pair.highPair;
		lowPair = pair.lowPair;
	}
	return *this;
}

Pair::Pair(int high) {
	this->high = high;
	this->highPair = NULL;
	this->lowPair = NULL;
}

Pair *Pair::getHighPair() {
	return highPair;
}

Pair *Pair::getLowPair() {
	return lowPair;
}

int Pair::getHigh() {
	return high;
}
