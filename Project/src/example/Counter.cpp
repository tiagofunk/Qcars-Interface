#include "Counter.h"

#include <iostream>

Counter::Counter(int stop) {
	this->stop = stop;
	this->count = 1;
}

bool Counter::proceed(){
	this->count++;
//	std::cout << this->count << std::endl;
	return this->stop != this->count;
}
