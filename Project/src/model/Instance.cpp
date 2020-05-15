#include "Instance.h"

Instance::Instance(int numberCars, int numberCities ) {
	this->numbersCars = numberCars;
	this->numbersCities = numberCities;
	this->satisfactionTotal = 0;
	this->bonusSatisfaction.resize( numberCities );
	this->cars.resize( this->numbersCars );
}

Instance::~Instance() {
}

void Instance::setCar( int index, Car c ){
	this->cars[ index ] = c;
}

Car Instance::getCar( int index ){
	return this->cars[ index ];
}

void Instance::setBonusSatisfaction( int index, int value ){
	this->satisfactionTotal += value;
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
