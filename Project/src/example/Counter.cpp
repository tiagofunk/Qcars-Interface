#include "Counter.h"

Counter::Counter(int stop) {
	this->stop = stop;
	this->count = 0;
}

bool Counter::proceed(){
	this->count++;
	return this->stop == this->count;
}
