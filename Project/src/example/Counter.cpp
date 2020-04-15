#include "Counter.h"

#include <iostream>

using namespace std;

Counter::Counter(int stop) {
	this->stop = stop;
	this->count = 1;
}

bool Counter::proceed(){
	this->count++;
	return this->stop != this->count;
}
