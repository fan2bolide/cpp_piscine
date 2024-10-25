#include "Pair.hpp"

#ifndef NULL
#define NULL 0
#endif

Pair::Pair(Pair *pair1, Pair *pair2) {
	if (pair2 == NULL) {
		lowPair = pair1;
		highPair = NULL;
	}
	else if (pair1->high < pair2->high) {
		highPair = pair2;
		lowPair = pair1;
	}
	else {
		highPair = pair1;
		lowPair = pair2;
	}
	if (highPair != NULL)
		high = highPair->high;
	else
		high = -1;
}

Pair::Pair(Pair *pair) : high(pair->high), highPair(pair->highPair), lowPair(pair->lowPair) {
}

Pair::~Pair() {
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
