#include "Instance.h"

Instance::Instance(int numberCars, int numberCities ) {
	this->numbersCars = numberCars;
	this->numbersCities = numberCities;
	this->satisfactionTotal = 0;
	this->bonusSatisfaction.resize( numberCities );
}

Instance::~Instance() {
}

void Instance::setCar( int index, Car c ){
	this->cars.insert( this->cars.begin()+index, c);
}

Car Instance::getCar( int index ){
	return this->cars.at( index );
}

void Instance::setBonusSatisfaction( int index, int value ){
	this->bonusSatisfaction[ index ] = value;
}

int Instance::getBonusSatisfaction( int index ){
	return this->bonusSatisfaction[ index ];
}

double Instance::getMinimalSatisfaction(){
	return this->minimalRatioSatisfaction * this->getSatisfactionTotal();
}

int Instance::getSatisfactionTotal(){
	return satisfactionTotal;
}

int Instance::getNumberCities(){
	return this->numbersCities;
}

int Instance::getNumberCars(){
	return this->numbersCars;
}
