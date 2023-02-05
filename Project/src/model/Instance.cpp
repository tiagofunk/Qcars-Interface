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
	return this->MINIMAL_RATIO_SATISFACTION * this->getSatisfactionTotal();
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

string Instance::toString(){
	string s = "Number of Cars: " + to_string( numbersCars )+"\n";
	s += "Number of Cities: " + to_string(numbersCities)+"\n";
	s += "Cars:\n";
	for (size_t i = 0; i < cars.size(); i++){
		s += cars[i].toString();
	}
	s += "Bonus satisfaction:" + to_string(bonusSatisfaction.size())+"\n";
	for (size_t i = 0; i < bonusSatisfaction.size(); i++){
		s += to_string(bonusSatisfaction[i]) + "\t";
	}
	s+="\nSatisfactionTotal: "+ to_string(satisfactionTotal)+"\n";
	return s;
}