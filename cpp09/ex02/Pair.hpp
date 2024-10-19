#ifndef PAIR_HPP
#define PAIR_HPP

class Pair {
private:
	int		high;
	Pair	*highPair;
	Pair	*lowPair;
	Pair();
public:
	Pair(Pair *pair1, Pair *pair2);
	Pair(int high);
	Pair(Pair *pair);
	~Pair();
	Pair operator=(Pair pair);
	Pair *getHighPair();
	Pair *getLowPair();
	int getHigh();
};

#endif
