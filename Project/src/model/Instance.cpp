#include "Instance.h"

Instance::Instance(int numberCars, int numberCities ) {
	this->numbersCars = numberCars;
	this->numbersCities = numberCities;
	this->satisfactionTotal = 0;
}

Instance::~Instance() {
}

Car Instance::getCar( int index ){
	return this->cars.at( index );
}

int Instance::getBonusSatisfaction( int index ){
	return this->bonusSatisfaction[ index ];
}

int Instance::getSatisfactionTotal(){
	return satisfactionTotal;
}
